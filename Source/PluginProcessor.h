/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "OscSender.h"
#include "Parameter.h"
//==============================================================================
/**
*/

class MIDITOOSCAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    MIDITOOSCAudioProcessor();
    ~MIDITOOSCAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void onChangeParameter(int paramID, float paramValue) {
        juce::String addr("/");
        addr += idText;
        addr += juce::String("/parameter0");
        addr += juce::String(paramID);
        
        std::vector<float> msgValues;
        msgValues.reserve(1);
        msgValues.emplace_back(paramValue);
        oscSender.send(addr.toRawUTF8(), msgValues);
    }

    OscSender oscSender;
    juce::String idText;
private:
    juce::AudioProcessorValueTreeState parameters;
    
    // atomic: 複数のスレッドから参照されてもok, 
    std::atomic<float>* parameter01 = nullptr;
    std::atomic<float>* parameter02 = nullptr;
    std::atomic<float>* parameter03 = nullptr;
    std::atomic<float>* parameter04 = nullptr;
    
    class ParameterListener : public juce::AudioProcessorValueTreeState::Listener {
        public:
        ParameterListener(MIDITOOSCAudioProcessor& _p) : p(_p){}
        void parameterChanged(const juce::String& parameterID, float newValue) override {
            if (parameterID == "/parameter01") p.onChangeParameter(1, newValue);
            if (parameterID == "/parameter02") p.onChangeParameter(2, newValue);
            if (parameterID == "/parameter03") p.onChangeParameter(3, newValue);
            if (parameterID == "/parameter04") p.onChangeParameter(4, newValue);
        }
        private:
        MIDITOOSCAudioProcessor& p;
    };
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDITOOSCAudioProcessor)
};
