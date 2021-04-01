/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "Editor.h"
using namespace std;
//==============================================================================
MIDITOOSCAudioProcessor::MIDITOOSCAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
#else
    :
#endif
        parameters(*this, nullptr, juce::Identifier("MIDI TO OSC"), // processor, undoManager, valueTreeType, parameterLayout
        {
            std::make_unique<juce::AudioParameterFloat>("/parameter01", "/parameter01", juce::NormalisableRange<float>(0.0, 1.0, 0.001), 0.0f),
            std::make_unique<juce::AudioParameterFloat>("/parameter02", "/parameter02", juce::NormalisableRange<float>(0.0, 1.0, 0.001), 0.0f),
            std::make_unique<juce::AudioParameterFloat>("/parameter03", "/parameter03", juce::NormalisableRange<float>(0.0, 1.0, 0.001), 0.0f),
            std::make_unique<juce::AudioParameterFloat>("/parameter04", "/parameter04", juce::NormalisableRange<float>(0.0, 1.0, 0.001), 0.0f),
        })
{    
    parameter01 = parameters.getRawParameterValue("/parameter01");
    parameter02 = parameters.getRawParameterValue("/parameter02");
    parameter03 = parameters.getRawParameterValue("/parameter03");
    parameter04 = parameters.getRawParameterValue("/parameter04");
    auto listener = new ParameterListener(*this);
    parameters.addParameterListener("/parameter01", listener);
    parameters.addParameterListener("/parameter02", listener);
    parameters.addParameterListener("/parameter03", listener);
    parameters.addParameterListener("/parameter04", listener);

    /*
    addParameter(new Parameter("/parameter01"));
    addParameter(new Parameter("/parameter02"));
    addParameter(new Parameter("/parameter03"));
    addParameter(new Parameter("/parameter04"));
    */	
         
}

MIDITOOSCAudioProcessor::~MIDITOOSCAudioProcessor()
{
}

//==============================================================================
const juce::String MIDITOOSCAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MIDITOOSCAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MIDITOOSCAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MIDITOOSCAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MIDITOOSCAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MIDITOOSCAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MIDITOOSCAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MIDITOOSCAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String MIDITOOSCAudioProcessor::getProgramName (int index)
{
    return {};
}

void MIDITOOSCAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void MIDITOOSCAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MIDITOOSCAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MIDITOOSCAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MIDITOOSCAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();


    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // MIDI
    juce::MidiBuffer::Iterator itr(midiMessages);
    juce::MidiMessage message(0);// default: noteOff
    int midiPosition;  // dummy variable

    // check midi buffer & get midi data
    while (itr.getNextEvent(message, midiPosition)) {
        // do MIDI processing
        if (message.isNoteOn()) {
            juce::String addr("/");
            addr += idText;
            addr += juce::String("/noteon");
            std::vector<float> msgValues;
            msgValues.reserve(2);
            msgValues.emplace_back(message.getNoteNumber());
            msgValues.emplace_back(message.getVelocity());
            oscSender.send(addr.toRawUTF8(), msgValues);

        }
        // else stop
    }
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool MIDITOOSCAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* MIDITOOSCAudioProcessor::createEditor()
{
    return new Editor (*this, parameters);
}

//==============================================================================
void MIDITOOSCAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // load from xml
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
        
    /*
    // save(store to memory) the parameter
    for (int i = 0; i < getParameters().size(); i++) {
        juce::MemoryOutputStream(destData, true).writeFloat(getParameters().getReference(i)->getValue());
    }
    */
}

void MIDITOOSCAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // save to xml
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
 
    if (xmlState.get() != nullptr) 
    {
        if (xmlState->hasTagName (parameters.state.getType())) 
        {
            parameters.replaceState (juce::ValueTree::fromXml (*xmlState));
        }
    }
                
    /*
    for (int i = 0; i < getParameters().size(); i++) {
        getParameters().getReference(i)->setValue(juce::MemoryInputStream(data, static_cast<size_t> (sizeInBytes), false).readFloat());
    }
     */
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MIDITOOSCAudioProcessor();
}
