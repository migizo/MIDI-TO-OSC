/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Editor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Editor::Editor (MIDITOOSCAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), processor(p),
      valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    parameter01.reset (new juce::Slider ("parameter01"));
    addAndMakeVisible (parameter01.get());
    parameter01->setRange (0, 1, 0.001);
    parameter01->setSliderStyle (juce::Slider::Rotary);
    parameter01->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 16);

    parameter01->setBounds (72, 366, 50, 70);

    parameter02.reset (new juce::Slider ("parameter02"));
    addAndMakeVisible (parameter02.get());
    parameter02->setRange (0, 1, 0.001);
    parameter02->setSliderStyle (juce::Slider::Rotary);
    parameter02->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 16);

    parameter02->setBounds (218, 366, 50, 70);

    parameter03.reset (new juce::Slider ("parameter03"));
    addAndMakeVisible (parameter03.get());
    parameter03->setRange (0, 1, 0.001);
    parameter03->setSliderStyle (juce::Slider::Rotary);
    parameter03->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 16);

    parameter03->setBounds (72, 488, 50, 70);

    parameter04.reset (new juce::Slider ("parameter04"));
    addAndMakeVisible (parameter04.get());
    parameter04->setRange (0, 1, 0.001);
    parameter04->setSliderStyle (juce::Slider::Rotary);
    parameter04->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 16);

    parameter04->setBounds (218, 488, 50, 70);

    extendToggle.reset (new juce::ImageButton ("extendToggle"));
    addAndMakeVisible (extendToggle.get());
    extendToggle->setButtonText (TRANS("extend"));
    extendToggle->addListener (this);

    extendToggle->setImages (false, true, true,
                             juce::ImageCache::getFromMemory (extendToggle_png, extendToggle_pngSize), 1.000f, juce::Colours::white,
                             juce::ImageCache::getFromMemory (extendToggle_png, extendToggle_pngSize), 0.900f, juce::Colours::white,
                             juce::ImageCache::getFromMemory (extendToggle_png, extendToggle_pngSize), 0.800f, juce::Colours::white);
    extendToggle->setBounds (25, 270, 288, 68);

    portTextEditor.reset (new juce::TextEditor ("portTextEditor"));
    addAndMakeVisible (portTextEditor.get());
    portTextEditor->setMultiLine (false);
    portTextEditor->setReturnKeyStartsNewLine (false);
    portTextEditor->setReadOnly (false);
    portTextEditor->setScrollbarsShown (true);
    portTextEditor->setCaretVisible (true);
    portTextEditor->setPopupMenuEnabled (true);
    portTextEditor->setColour (juce::TextEditor::textColourId, juce::Colours::white);
    portTextEditor->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    portTextEditor->setText (TRANS("7000"));

    portTextEditor->setBounds (26, 208, 128, 32);

    hostTextEditor.reset (new juce::TextEditor ("hostTextEditor"));
    addAndMakeVisible (hostTextEditor.get());
    hostTextEditor->setMultiLine (false);
    hostTextEditor->setReturnKeyStartsNewLine (false);
    hostTextEditor->setReadOnly (false);
    hostTextEditor->setScrollbarsShown (true);
    hostTextEditor->setCaretVisible (true);
    hostTextEditor->setPopupMenuEnabled (true);
    hostTextEditor->setColour (juce::TextEditor::textColourId, juce::Colours::white);
    hostTextEditor->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    hostTextEditor->setText (TRANS("127.0.0.1"));

    hostTextEditor->setBounds (26, 158, 128, 32);

    idTextEditor.reset (new juce::TextEditor ("idTextEditor"));
    addAndMakeVisible (idTextEditor.get());
    idTextEditor->setMultiLine (false);
    idTextEditor->setReturnKeyStartsNewLine (false);
    idTextEditor->setReadOnly (false);
    idTextEditor->setScrollbarsShown (true);
    idTextEditor->setCaretVisible (true);
    idTextEditor->setPopupMenuEnabled (true);
    idTextEditor->setColour (juce::TextEditor::textColourId, juce::Colours::white);
    idTextEditor->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    idTextEditor->setText (TRANS("0"));

    idTextEditor->setBounds (179, 158, 128, 32);

    checkButton.reset (new juce::ImageButton ("checkButton"));
    addAndMakeVisible (checkButton.get());
    checkButton->setButtonText (TRANS("new button"));
    checkButton->addListener (this);

    checkButton->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (button_png, button_pngSize), 1.000f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (button_png, button_pngSize), 0.900f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (button_png, button_pngSize), 0.800f, juce::Colour (0x00000000));
    checkButton->setBounds (179, 208, 128, 32);

    cachedImage_bg_png_1 = juce::ImageCache::getFromMemory (bg_png, bg_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (340, 338);


    //[Constructor] You can add your own custom stuff here..

    startTimerHz(60);

    hostTextEditor->addListener(this);
    hostTextEditor->setJustification(juce::Justification::centred);
    hostTextEditor->setColour (juce::TextEditor::outlineColourId, juce::Colours::transparentWhite);
    hostTextEditor->setColour (juce::TextEditor::focusedOutlineColourId, juce::Colours::transparentWhite);
    portTextEditor->addListener(this);
    portTextEditor->setJustification(juce::Justification::centred);
    portTextEditor->setColour (juce::TextEditor::outlineColourId, juce::Colours::transparentWhite);
    portTextEditor->setColour (juce::TextEditor::focusedOutlineColourId, juce::Colours::transparentWhite);
    idTextEditor->addListener(this);
    idTextEditor->setJustification(juce::Justification::centred);
    idTextEditor->setColour (juce::TextEditor::outlineColourId, juce::Colours::transparentWhite);
    idTextEditor->setColour (juce::TextEditor::focusedOutlineColourId, juce::Colours::transparentWhite);

    checkButton->setClickingTogglesState(true);
    checkButton->setToggleState(false, juce::NotificationType::sendNotification);

    parameter01->setLookAndFeel(&knob);
    parameter02->setLookAndFeel(&knob);
    parameter03->setLookAndFeel(&knob);
    parameter04->setLookAndFeel(&knob);
    extendToggle->setClickingTogglesState(true);
    extendToggle->setLookAndFeel(&extendToggleLookAndFeel);

    parameter01Attachment.reset(new KnobAttachment(valueTreeState, "/parameter01", *parameter01.get()));
    parameter02Attachment.reset(new KnobAttachment(valueTreeState, "/parameter02", *parameter02.get()));
    parameter03Attachment.reset(new KnobAttachment(valueTreeState, "/parameter03", *parameter03.get()));
    parameter04Attachment.reset(new KnobAttachment(valueTreeState, "/parameter04", *parameter04.get()));

    if(! processor.oscSender.connect(hostTextEditor->getText().toRawUTF8(), portTextEditor->getText().getIntValue())) {
        cout << "Error: could not connect to UDP port." << endl;
    }
    processor.idText = idTextEditor->getText();
    ping.setHostName(hostTextEditor->getText());

    /*
    for (int i = 0; i < processor.getParameters().size(); i++) {
        Parameter* param = (Parameter*)processor.getParameters().getReference(i);

        juce::Slider* knob;
        if (i == 0) knob = parameter01.get();
        else if (i == 1) knob = parameter02.get();
        else if (i == 2) knob = parameter03.get();
        else knob = parameter04.get();

        param->setMin(knob->getMinValue());
        param->setMax(knob->getMaxValue());
        param->setDefault(0.0);
        knob->setValue((double)param->getDefaultValue(), juce::dontSendNotification);
    }
    */
    //[/Constructor]
}

Editor::~Editor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    stopTimer();
    parameter01Attachment = nullptr;
    parameter02Attachment = nullptr;
    parameter03Attachment = nullptr;
    parameter04Attachment = nullptr;
    //[/Destructor_pre]

    parameter01 = nullptr;
    parameter02 = nullptr;
    parameter03 = nullptr;
    parameter04 = nullptr;
    extendToggle = nullptr;
    portTextEditor = nullptr;
    hostTextEditor = nullptr;
    idTextEditor = nullptr;
    checkButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Editor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 0, y = 0, width = 340, height = 581;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_bg_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_bg_png_1.getWidth(), cachedImage_bg_png_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    {
        // check status mark
        g.setColour (juce::Colours::white);
        g.setOpacity(1.0 - juce::jmax(successButtonBgAlpha, errorButtonBgAlpha));

        g.drawRoundedRectangle(179, 208, 128, 32, 5, 2);

        g.setColour (juce::Colour (0xb4b4b4));
        g.fillEllipse(200, 219, 12, 12);
    }

    // success
    {
        g.setColour (juce::Colour(0x46A0AA));
        g.setOpacity(successButtonBgAlpha);
        g.fillEllipse(200, 219, 12, 12);
        g.drawRoundedRectangle(179, 208, 128, 32, 5, 2);
    }

    // error
    {
        g.setColour (juce::Colour(0xAA4646));
        g.setOpacity(errorButtonBgAlpha);
        g.fillEllipse(200, 219, 12, 12);
        g.drawRoundedRectangle(179, 208, 128, 32, 5, 2);
    }


    //[/UserPaint]
}

void Editor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Editor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == extendToggle.get())
    {
        //[UserButtonCode_extendToggle] -- add your button handler code here..
        bool toggleState = extendToggle->getToggleState();
        if (toggleState) animator.start(10, defaultHeight, extendHeight);
        else animator.start(10, extendHeight, defaultHeight);
        //[/UserButtonCode_extendToggle]
    }
    else if (buttonThatWasClicked == checkButton.get())
    {
        //[UserButtonCode_checkButton] -- add your button handler code here..
        if (checkButton->getToggleState())ping.start();
        else ping.stop();
        //[/UserButtonCode_checkButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
// change internal parameter
/*
void Editor::parameterValueChanged (int parameterIndex, float newValue) {
    AudioParameterFloat* param = (AudioParameterFloat*)(processor.getParameters().getReference(parameterIndex));
    int paramID = param->paramID;
    if (paramID == 1) parameter01->setValue(newValue, dontSendNotification);
    else if (paramID == 2) parameter02->setValue(newValue, dontSendNotification);
    else if (paramID == 3) parameter03->setValue(newValue, dontSendNotification);
    else if (paramID == 4) parameter04->setValue(newValue, dontSendNotification);
    processor.onChangeParameter(paramID, newValue);
}
*/

void Editor::textEditorReturnKeyPressed(juce::TextEditor& t) {
    onChangeTextEdit(t);
}

void Editor::textEditorFocusLost(juce::TextEditor& t) {
    onChangeTextEdit(t);
}

void Editor::onChangeTextEdit(juce::TextEditor& t) {
    t.setText(t.getText().trim());
    
    if (&t == hostTextEditor.get())
    {
        auto& osc = processor.oscSender;
        osc.disconnect();
        if(! osc.connect(t.getText().toRawUTF8(), portTextEditor->getText().getIntValue())) {
            cout << "Error: could not connect to UDP port." << endl;
        }
        ping.setHostName(t.getText());
    }
    else if (&t == portTextEditor.get())
    {
        auto& osc = processor.oscSender;
        osc.disconnect();
        if (! osc.connect(hostTextEditor->getText().toRawUTF8(), t.getText().getIntValue())) {
            cout << "Error: could not connect to UDP port." << endl;
        }
    }
    else if (&t == idTextEditor.get())
    {
        processor.idText = t.getText();
    }
}

void Editor::timerCallback()
{
    /*
    for (int i = 0; i < 4; i++) {
        Parameter* param = (Parameter*)processor.getParameters().getReference(i);
        if (param->isChanged())
        {
            if (i == 0) parameter01->setValue((double)param->getValue(), juce::dontSendNotification);
            if (i == 1) parameter02->setValue((double)param->getValue(), juce::dontSendNotification);
            if (i == 2) parameter03->setValue((double)param->getValue(), juce::dontSendNotification);
            if (i == 3) parameter04->setValue((double)param->getValue(), juce::dontSendNotification);
            processor.onChangeParameter(i+1, param->getValue());
        }
    }
    */

    animator.update();
    if (animator.getIsProgress()) {
        setSize(340, animator.getValue());
    }

    // status alpha
    successButtonBgAlpha = 0.0f;
    errorButtonBgAlpha = 0.0f;
    if (checkButton->getToggleState()) {

        // cross fade success&error
        PingThread::ConnectStatus state = ping.getConnectStatus();
        static PingThread::ConnectStatus lastState = state;
        if (lastState != state) {
            if (state == PingThread::ConnectStatus::SUCCESS) {
                successAlphaAnimator.start(90, 0.0, 1.0);
            }
            else if (state == PingThread::ConnectStatus::ERROR) {
                errorAlphaAnimator.start(90, 0.0, 1.0);
            }
            if (lastState == PingThread::ConnectStatus::SUCCESS) {
                successAlphaAnimator.start(90, 1.0, 0.0);
            }
            else if (lastState == PingThread::ConnectStatus::ERROR) {
                errorAlphaAnimator.start(90, 1.0, 0.0);
            }
        }
        lastState = state;

        successAlphaAnimator.update();
        errorAlphaAnimator.update();

        // alpha
        float f = juce::jmap((double)sin((float)juce::Time::getMillisecondCounter() / 1000.0f * juce::MathConstants<float>::pi * 1.5f), -1.0, 1.0, 0.2, 1.0);
        successButtonBgAlpha = juce::jmap((double)successAlphaAnimator.getValue(), 0.0, 1.0, 0.0, (double)f);
        errorButtonBgAlpha = juce::jmap((double)errorAlphaAnimator.getValue(), 0.0, 1.0, 0.0, (double)f);
    }

    repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Editor" componentName=""
                 parentClasses="public juce::AudioProcessorEditor, private juce::Timer, public juce::TextEditor::Listener"
                 constructorParams="MIDITOOSCAudioProcessor&amp; p, juce::AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor(&amp;p), processor(p),&#10;valueTreeState(vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="340" initialHeight="338">
  <BACKGROUND backgroundColour="ff323e44">
    <IMAGE pos="0 0 340 581" resource="bg_png" opacity="1.0" mode="0"/>
  </BACKGROUND>
  <SLIDER name="parameter01" id="4240e6070b731c7" memberName="parameter01"
          virtualName="" explicitFocusOrder="0" pos="72 366 50 70" min="0.0"
          max="1.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="16" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="parameter02" id="20e264b94183a3ca" memberName="parameter02"
          virtualName="" explicitFocusOrder="0" pos="218 366 50 70" min="0.0"
          max="1.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="16" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="parameter03" id="3f7a2a3d2cebe12b" memberName="parameter03"
          virtualName="" explicitFocusOrder="0" pos="72 488 50 70" min="0.0"
          max="1.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="16" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="parameter04" id="8197577a1b6b0682" memberName="parameter04"
          virtualName="" explicitFocusOrder="0" pos="218 488 50 70" min="0.0"
          max="1.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="16" skewFactor="1.0"
          needsCallback="0"/>
  <IMAGEBUTTON name="extendToggle" id="ce5b633b7a9a7c86" memberName="extendToggle"
               virtualName="" explicitFocusOrder="0" pos="25 270 288 68" buttonText="extend"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="extendToggle_png" opacityNormal="1.0" colourNormal="ffffffff"
               resourceOver="extendToggle_png" opacityOver="0.8999999761581421"
               colourOver="ffffffff" resourceDown="extendToggle_png" opacityDown="0.800000011920929"
               colourDown="ffffffff"/>
  <TEXTEDITOR name="portTextEditor" id="215a74a85b39be02" memberName="portTextEditor"
              virtualName="" explicitFocusOrder="0" pos="26 208 128 32" textcol="ffffffff"
              bkgcol="0" initialText="7000" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="hostTextEditor" id="c6384cf16d78c048" memberName="hostTextEditor"
              virtualName="" explicitFocusOrder="0" pos="26 158 128 32" textcol="ffffffff"
              bkgcol="0" initialText="127.0.0.1" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="idTextEditor" id="31e9cdc4138124fe" memberName="idTextEditor"
              virtualName="" explicitFocusOrder="0" pos="179 158 128 32" textcol="ffffffff"
              bkgcol="0" initialText="0" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <IMAGEBUTTON name="checkButton" id="6c95b1c10408b1d8" memberName="checkButton"
               virtualName="" explicitFocusOrder="0" pos="179 208 128 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="button_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="button_png" opacityOver="0.8999999761581421" colourOver="0"
               resourceDown="button_png" opacityDown="0.800000011920929" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: bg_png, 16629, "../Resource/bg.png"
static const unsigned char resource_Editor_bg_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,84,0,0,2,69,8,6,0,0,0,130,240,15,22,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,56,101,88,73,
102,77,77,0,42,0,0,0,8,0,1,135,105,0,4,0,0,0,1,0,0,0,26,0,0,0,0,0,2,160,2,0,4,0,0,0,1,0,0,1,84,160,3,0,4,0,0,0,1,0,0,2,69,0,0,0,0,107,186,70,162,0,0,64,0,73,68,65,84,120,1,237,157,121,119,20,87,154,167,
95,144,196,38,144,16,251,142,216,193,44,102,49,187,205,110,192,6,140,203,166,92,101,87,213,244,82,167,187,207,233,115,102,254,232,79,80,95,192,253,199,156,57,51,229,234,110,79,247,116,217,101,151,187,
92,101,176,177,177,141,193,54,139,193,102,223,87,9,73,236,155,4,18,218,64,154,251,6,142,36,148,25,169,76,165,82,25,145,87,207,229,136,140,184,113,215,231,189,249,139,187,69,100,151,55,127,251,86,179,224,
32,0,1,8,64,160,221,4,186,182,59,5,18,128,0,4,32,0,1,135,0,130,74,67,128,0,4,32,144,38,2,8,106,154,64,146,12,4,32,0,1,4,149,54,0,1,8,64,32,77,4,16,212,52,129,36,25,8,64,0,2,8,42,109,0,2,16,128,64,154,
8,32,168,105,2,73,50,16,128,0,4,16,84,218,0,4,32,0,129,52,17,64,80,211,4,146,100,32,0,1,8,32,168,180,1,8,64,0,2,105,34,128,160,166,9,36,201,64,0,2,16,64,80,105,3,16,128,0,4,210,68,0,65,77,19,72,146,129,
0,4,32,128,160,210,6,32,0,1,8,164,137,0,130,154,38,144,36,3,1,8,64,0,65,165,13,64,0,2,16,72,19,1,4,53,77,32,73,6,2,16,128,0,130,74,27,128,0,4,32,144,38,2,8,106,154,64,146,12,4,32,0,1,4,149,54,0,1,8,64,
32,77,4,16,212,52,129,36,25,8,64,0,2,8,42,109,0,2,16,128,64,154,8,32,168,105,2,73,50,16,128,0,4,16,84,218,0,4,32,0,129,52,17,64,80,211,4,146,100,32,0,1,8,228,102,10,193,47,55,189,42,131,250,247,143,155,
221,249,210,82,57,120,236,152,84,92,185,26,55,204,184,226,98,217,184,102,117,220,235,209,23,110,220,190,45,191,255,175,63,69,123,115,14,1,8,64,160,67,8,100,76,80,91,19,83,173,217,120,35,150,250,167,194,
186,109,199,78,169,111,104,136,169,240,160,1,241,5,57,38,176,241,72,148,167,95,28,252,32,0,1,8,164,74,32,99,130,234,22,240,222,253,251,114,226,236,89,247,84,10,122,247,150,145,195,134,73,65,159,62,142,
159,138,106,119,211,11,253,96,203,199,145,48,238,193,193,163,199,220,195,164,62,111,220,186,157,84,56,2,65,0,2,16,72,7,129,140,11,106,149,17,212,189,63,28,136,41,187,14,231,215,46,95,38,221,187,117,115,
4,118,196,176,161,49,195,127,237,181,250,197,141,73,12,15,8,64,0,2,1,16,8,205,162,212,5,51,212,223,185,103,79,4,129,246,90,113,16,128,0,4,178,137,64,104,4,85,161,105,239,21,7,1,8,64,32,91,9,132,74,80,
179,21,34,229,134,0,4,32,160,4,66,37,168,11,231,204,137,88,69,23,175,112,16,128,0,4,178,137,64,198,23,165,252,224,232,66,212,26,179,32,229,206,155,234,226,211,249,146,82,191,160,248,65,0,2,16,8,45,129,
140,11,106,161,217,30,181,240,153,39,61,81,221,54,53,126,204,24,103,117,223,165,244,89,156,125,168,42,188,83,39,77,146,238,221,187,185,65,91,253,44,191,114,37,102,167,64,171,17,184,8,1,8,64,160,29,4,50,
46,168,186,223,212,59,180,247,150,93,123,166,42,166,186,226,239,231,102,207,152,30,55,174,95,120,205,231,159,223,250,157,223,37,252,32,0,1,8,164,157,64,198,5,53,94,13,78,156,57,99,182,77,237,245,125,66,
202,141,83,95,31,251,244,148,123,205,239,211,239,105,43,191,112,248,65,0,2,16,72,7,129,140,11,170,62,95,239,238,55,213,167,162,102,79,159,30,169,71,34,1,212,103,253,117,24,159,236,144,255,38,79,74,69,
216,114,0,1,8,116,60,129,140,11,106,125,125,125,100,94,83,5,207,153,19,253,113,110,116,239,129,3,114,239,126,117,171,181,190,105,4,25,7,1,8,64,32,140,4,2,221,54,165,61,82,237,117,186,46,222,220,170,123,
157,79,8,64,0,2,97,38,16,168,160,42,24,125,225,137,59,212,215,222,106,65,159,222,97,230,69,217,32,0,1,8,196,37,16,184,160,70,247,82,215,44,91,22,183,176,92,128,0,4,32,16,102,2,129,11,170,194,241,246,82,
117,115,191,190,105,10,7,1,8,64,32,219,8,132,66,80,163,123,169,204,165,102,91,51,162,188,16,128,128,18,200,248,42,127,60,236,218,75,213,45,84,173,189,15,117,160,249,9,149,101,139,22,198,75,34,198,95,119,
4,232,222,86,28,4,32,0,129,76,16,8,141,160,106,47,85,95,30,237,10,166,138,107,244,239,75,141,31,83,28,121,222,63,25,56,58,125,128,160,38,67,138,48,16,128,64,58,8,100,108,200,175,27,250,213,29,60,118,60,
110,185,117,11,149,27,206,111,191,169,190,48,165,45,111,161,210,223,167,194,65,0,2,16,200,20,129,46,111,254,246,173,230,76,101,70,62,16,128,0,4,108,38,144,177,30,170,205,16,169,27,4,32,0,1,37,128,160,
210,14,32,0,1,8,164,137,0,130,154,38,144,36,3,1,8,64,0,65,165,13,64,0,2,16,72,19,1,4,53,77,32,73,6,2,16,128,0,130,74,27,128,0,4,32,144,38,2,8,106,154,64,146,12,4,32,0,1,4,149,54,0,1,8,64,32,77,4,16,212,
52,129,36,25,8,64,0,2,8,42,109,0,2,16,128,64,154,8,32,168,105,2,73,50,16,128,0,4,16,84,218,0,4,32,0,129,52,17,64,80,211,4,146,100,32,0,1,8,32,168,180,1,8,64,0,2,105,34,128,160,166,9,36,201,64,0,2,16,64,
80,105,3,16,128,0,4,210,68,0,65,77,19,72,146,129,0,4,32,128,160,210,6,32,0,1,8,164,137,0,130,154,38,144,36,3,1,8,64,0,65,165,13,64,0,2,16,72,19,1,4,53,77,32,73,6,2,16,128,0,130,74,27,128,0,4,32,144,38,
2,8,106,154,64,146,12,4,32,0,1,4,149,54,0,1,8,64,32,77,4,16,212,52,129,36,25,8,64,0,2,8,42,109,0,2,16,128,64,154,8,32,168,105,2,73,50,16,128,0,4,16,84,218,0,4,32,0,129,52,17,64,80,211,4,146,100,32,0,1,
8,32,168,180,1,8,64,0,2,105,34,128,160,166,9,36,201,64,0,2,16,64,80,105,3,16,128,0,4,210,68,0,65,77,19,72,146,129,0,4,32,128,160,210,6,32,0,1,8,164,137,0,130,154,38,144,36,3,1,8,64,0,65,165,13,64,0,2,
16,72,19,1,4,53,77,32,73,6,2,16,128,0,130,74,27,128,0,4,32,144,38,2,8,106,154,64,146,12,4,32,0,1,4,149,54,0,1,8,64,32,77,4,16,212,52,129,36,25,8,64,0,2,8,42,109,0,2,16,128,64,154,8,32,168,105,2,73,50,
16,128,0,4,16,84,218,0,4,32,0,129,52,17,64,80,211,4,146,100,32,0,1,8,228,130,32,253,4,198,140,26,37,35,134,14,149,110,221,242,164,161,161,81,202,175,92,145,10,243,247,240,209,163,152,204,186,116,233,34,
195,135,12,145,145,195,135,73,175,158,61,229,225,195,71,114,253,230,77,57,125,254,124,76,88,245,232,221,171,151,60,53,105,162,116,203,203,147,139,101,229,114,229,218,53,223,112,234,89,208,167,143,20,154,
191,174,93,91,222,55,27,26,27,228,214,157,187,210,216,216,24,55,110,244,133,241,99,138,101,216,224,193,114,191,186,70,142,159,62,45,141,15,31,70,7,73,120,174,117,29,106,210,200,203,77,190,217,213,213,
215,25,30,183,18,166,221,167,119,111,25,52,160,191,244,47,234,103,254,250,74,109,93,157,169,227,29,185,109,234,121,253,214,45,105,106,106,74,152,70,91,3,40,215,193,3,7,200,128,126,154,103,145,244,232,
222,67,238,84,222,141,228,89,93,83,147,116,146,221,187,117,147,17,195,134,74,191,194,190,82,212,183,175,195,168,174,190,94,106,106,31,24,27,95,151,43,215,175,155,182,145,60,115,77,111,240,192,129,210,
191,95,145,12,48,76,148,253,221,170,42,185,91,89,41,165,229,229,190,109,49,233,194,18,48,46,129,228,91,118,220,36,184,224,37,48,115,234,84,89,241,236,98,175,151,204,157,249,180,148,85,92,150,255,250,228,
147,22,254,122,178,124,241,34,209,56,209,78,197,235,171,221,187,91,120,235,23,248,87,63,221,36,61,123,244,112,252,231,205,154,37,31,108,249,216,17,236,22,1,205,201,134,213,207,203,132,49,99,162,189,91,
156,87,221,191,47,55,111,223,150,239,15,29,150,171,55,110,180,184,230,61,153,61,125,186,44,91,180,48,226,53,97,236,24,249,227,230,45,145,243,100,14,38,141,27,39,43,159,123,214,136,78,247,100,130,183,8,
115,191,186,90,182,124,254,133,92,51,55,154,104,167,233,45,158,59,87,102,60,53,197,17,141,232,235,122,126,199,136,136,178,84,27,164,203,141,25,53,82,150,47,90,44,125,11,11,124,147,108,110,110,150,195,
199,79,200,158,31,126,144,250,134,6,223,48,174,231,180,73,147,228,185,5,243,35,118,117,253,189,159,143,204,13,65,237,180,239,224,65,209,227,120,78,133,115,214,180,105,178,232,153,57,230,134,222,205,55,
216,131,218,90,57,112,244,152,28,58,118,12,97,245,37,148,186,103,206,154,245,27,126,147,122,116,98,70,19,80,49,237,157,159,31,237,45,133,5,5,114,190,180,84,180,49,187,78,123,17,235,86,174,140,233,65,234,
245,190,38,252,15,71,143,186,65,157,79,253,18,79,159,60,185,133,159,126,113,47,92,186,212,194,79,197,107,193,156,217,45,252,252,78,84,140,250,153,222,208,212,73,19,157,203,151,227,244,118,85,8,243,77,
207,216,117,218,243,61,126,230,140,233,125,183,46,20,110,120,253,92,189,116,169,20,21,22,122,189,146,62,86,78,34,93,228,98,84,61,199,23,23,203,166,245,235,156,158,157,10,73,60,167,55,160,167,38,78,148,
1,253,251,201,133,210,75,162,204,82,117,185,166,119,173,55,171,69,207,60,35,61,122,196,191,57,60,238,141,15,146,105,147,39,201,157,187,149,78,239,208,47,207,133,70,248,244,102,149,168,215,222,213,212,
79,123,176,3,251,247,151,51,23,46,248,37,229,216,242,181,151,54,152,186,78,144,156,156,28,223,48,234,153,103,70,55,163,71,12,151,33,131,6,201,89,147,86,123,120,196,205,164,147,94,104,57,22,236,164,16,
210,85,109,253,226,107,35,141,231,198,142,30,213,226,210,40,211,168,227,53,252,30,70,4,134,152,33,155,215,21,143,28,233,61,117,142,139,71,142,136,241,211,47,93,91,156,246,124,23,205,125,70,214,46,95,22,
19,77,203,49,104,192,128,24,255,209,35,98,243,141,9,228,241,120,212,20,59,221,225,185,156,240,48,58,190,138,243,139,43,87,24,81,123,220,91,79,152,128,9,160,61,246,165,11,22,36,19,52,110,152,229,139,22,
201,184,209,163,227,94,143,190,160,211,56,47,174,90,233,76,191,68,95,211,169,130,249,102,148,209,22,167,109,200,239,134,173,237,104,253,243,171,156,169,135,100,211,83,27,46,51,245,193,165,143,0,130,154,
62,150,113,197,209,205,34,90,132,70,15,111,93,148,114,114,91,246,50,114,162,230,66,53,93,63,65,78,101,88,173,105,77,153,48,33,70,196,253,242,124,156,111,219,154,206,15,71,142,152,249,215,106,141,218,102,
167,115,161,199,78,157,142,196,211,27,128,138,169,246,22,163,157,142,0,46,94,42,147,27,102,222,212,175,231,53,115,218,84,241,187,9,69,167,227,119,62,206,244,136,167,79,105,57,66,208,112,154,143,206,243,
94,44,43,115,230,110,163,227,234,124,247,139,43,150,199,76,73,232,212,137,214,197,235,148,209,123,127,249,72,254,229,157,119,229,163,207,182,57,243,233,222,235,77,38,47,191,249,224,231,230,207,115,230,
114,189,97,245,88,167,27,180,92,58,93,226,23,111,226,184,177,209,81,56,111,7,129,216,22,217,142,196,136,218,58,1,93,144,81,17,112,23,23,180,135,154,41,167,95,40,157,247,84,177,213,222,157,206,139,142,
43,142,237,105,45,89,184,160,205,243,163,201,212,65,69,238,226,165,119,165,159,89,48,114,69,90,123,220,207,205,159,31,19,93,231,75,43,239,85,57,254,141,141,15,205,241,189,22,97,116,206,89,23,92,162,221,
201,179,231,100,219,206,157,17,33,29,62,116,136,188,188,118,173,60,158,50,120,18,122,245,178,101,242,47,191,127,39,18,238,201,149,248,71,42,124,171,151,46,137,9,160,11,71,127,254,244,83,185,122,253,241,
28,180,134,123,193,136,167,78,187,120,221,48,179,240,56,99,202,20,57,114,242,100,196,91,123,168,209,78,231,178,117,1,74,157,138,107,137,89,64,210,121,118,141,219,208,216,40,63,28,62,210,98,218,72,195,
233,8,66,237,25,237,84,228,255,180,117,171,212,153,5,58,117,186,80,250,202,139,47,180,184,17,233,13,217,219,38,163,211,224,188,109,4,90,222,30,219,22,151,208,109,36,160,66,50,194,124,201,213,21,244,233,
237,204,147,182,49,137,148,131,107,47,74,133,92,87,158,117,215,193,71,219,182,201,217,139,23,99,210,211,47,157,14,83,59,202,233,124,226,205,219,119,156,191,123,247,253,123,172,186,136,228,134,137,22,83,
45,151,95,175,74,123,166,159,127,253,117,11,145,188,124,245,154,236,63,120,40,166,42,186,83,98,216,144,193,49,254,173,121,140,28,54,204,119,209,104,239,15,7,34,98,170,241,181,23,184,109,199,78,81,161,
141,118,209,229,110,122,20,187,184,52,113,236,88,231,38,160,159,122,243,211,244,182,127,187,75,254,247,191,255,135,252,159,255,248,127,178,239,80,108,125,38,154,158,174,159,251,226,155,111,34,98,170,215,
43,174,94,149,45,95,124,217,130,145,238,216,112,111,240,126,105,224,215,54,2,244,80,219,198,171,205,161,117,200,229,237,33,141,50,195,252,210,242,10,209,79,175,211,47,96,170,67,117,111,58,109,57,62,120,
236,184,232,23,55,218,105,15,214,187,120,22,125,61,200,115,237,1,14,245,153,167,62,117,238,188,239,144,86,23,207,116,5,61,218,233,141,67,5,55,89,167,225,253,220,137,179,103,99,188,117,123,220,153,243,
23,228,233,169,79,181,184,166,219,227,188,238,218,205,27,50,105,124,203,158,172,94,215,121,82,253,115,166,18,204,212,133,46,198,105,253,234,163,122,234,110,90,126,101,211,27,146,78,123,68,187,18,51,252,
255,112,235,167,14,67,221,62,229,183,115,34,58,14,231,201,19,160,135,154,60,171,148,66,170,48,105,227,118,157,174,174,170,115,63,245,88,247,131,94,107,101,219,146,134,233,8,87,105,246,37,250,185,84,87,
227,253,210,74,183,95,190,233,61,251,173,232,87,197,17,27,221,143,234,183,223,214,187,107,33,153,50,250,133,215,180,227,237,116,240,235,89,235,205,192,221,242,166,121,30,57,121,74,238,181,50,175,172,245,
212,133,73,221,81,240,235,215,127,46,27,158,127,222,119,244,224,87,182,120,60,52,223,75,21,21,242,157,217,126,133,152,42,141,244,58,4,53,189,60,125,83,43,187,92,17,241,215,21,120,29,82,143,26,254,100,
254,84,135,98,143,124,134,127,145,72,29,116,16,79,12,122,118,224,144,191,189,85,137,183,183,210,111,136,237,230,85,231,179,189,203,59,106,112,195,181,246,169,15,105,68,187,250,250,248,219,198,234,27,98,
135,252,26,223,91,126,29,106,235,188,182,238,5,78,198,233,34,214,47,55,189,26,51,146,241,166,233,166,163,98,143,203,60,1,4,53,3,204,181,71,224,117,115,102,204,104,209,83,185,148,198,13,231,222,124,18,
29,199,19,206,123,102,195,127,88,93,60,161,240,235,165,185,117,240,155,19,142,151,142,27,39,250,211,47,124,126,175,248,115,205,249,61,159,236,219,245,166,21,157,142,178,126,231,195,63,203,199,102,110,
83,219,137,223,74,188,55,190,206,255,46,245,60,100,161,215,162,211,84,191,214,120,232,117,92,199,16,96,14,181,99,184,182,72,181,194,204,213,233,211,45,238,234,246,172,233,211,90,92,215,47,146,46,122,100,
218,249,205,69,106,25,244,17,197,176,58,21,143,71,102,142,50,122,187,152,62,118,234,231,244,145,80,151,187,247,186,62,66,219,22,87,237,19,94,55,200,235,3,27,126,195,235,129,62,229,209,169,7,191,81,129,
138,168,46,16,234,159,110,177,210,221,31,99,70,142,18,125,220,215,59,69,224,150,119,180,103,116,163,126,90,54,125,64,195,235,6,154,135,24,226,57,125,152,64,183,128,233,227,208,135,79,156,144,202,170,150,
187,40,226,197,195,63,49,1,122,168,137,25,181,59,132,14,237,188,207,220,231,122,158,98,169,121,240,64,110,223,189,219,238,60,218,154,128,46,128,205,155,29,187,169,92,23,66,226,205,173,182,53,143,142,8,
175,229,43,191,114,53,38,105,93,92,243,235,137,70,223,188,220,136,101,151,219,246,24,106,188,240,179,204,190,214,104,167,239,21,208,167,184,162,93,116,26,218,14,116,75,212,63,252,234,151,102,59,211,139,
206,230,127,221,26,117,190,164,84,116,133,254,119,255,249,123,241,91,244,210,141,253,222,27,202,37,159,186,104,25,84,52,163,221,138,197,139,101,225,156,57,50,200,76,61,233,86,171,159,174,95,239,59,39,
29,29,143,243,228,8,32,168,201,113,106,119,168,120,207,145,71,127,201,218,157,81,156,4,84,64,245,75,62,205,60,186,170,171,222,127,245,218,79,157,47,85,116,112,221,70,163,95,234,48,187,147,62,43,235,42,
48,250,216,165,46,226,232,98,142,246,236,244,233,47,221,191,25,237,244,65,129,100,231,45,221,184,186,63,84,95,44,18,237,84,148,22,204,158,237,228,231,62,110,170,34,165,11,80,209,46,90,28,39,154,189,170,
250,220,189,14,207,245,97,131,55,126,242,178,243,2,26,55,158,142,106,252,118,91,104,143,82,123,233,174,211,158,173,223,139,119,116,63,172,206,187,234,62,83,157,103,213,199,145,245,193,6,175,83,225,245,
123,242,202,27,134,227,228,9,48,228,79,158,85,187,66,234,176,126,241,188,185,49,105,68,207,175,198,4,72,193,67,123,113,209,78,87,238,95,90,179,58,218,187,197,185,246,164,247,152,125,149,97,119,250,38,
46,221,211,25,221,11,212,97,239,27,175,252,196,17,23,239,40,192,91,31,21,169,173,219,191,242,122,37,125,188,245,171,175,228,245,151,95,142,17,75,21,110,253,243,155,138,112,19,215,109,84,218,243,244,186,
232,41,23,237,97,235,77,65,23,41,245,13,89,69,5,133,206,246,41,111,28,61,190,124,189,229,118,47,157,114,216,181,111,127,139,23,216,104,56,157,62,208,157,1,58,165,160,98,175,127,209,78,167,119,82,125,130,
45,58,45,206,69,98,111,163,80,73,153,128,159,144,153,205,132,78,122,250,5,241,123,235,208,147,5,169,88,17,140,78,175,182,46,118,229,216,111,65,66,95,249,214,86,167,121,125,189,247,59,209,41,8,175,211,
222,170,223,66,73,157,79,89,188,241,146,57,174,53,175,230,243,115,173,173,216,187,225,63,255,250,155,152,178,186,215,226,137,169,94,87,225,209,30,106,42,78,159,60,210,141,252,241,156,119,24,238,13,163,
130,245,229,183,223,122,189,156,99,125,89,78,180,211,158,173,238,0,153,251,244,211,206,28,106,116,79,87,111,122,71,204,91,172,162,221,65,243,230,168,120,55,103,77,195,79,76,53,141,35,39,158,60,185,21,
157,38,231,109,39,128,160,182,157,89,220,24,42,110,209,11,58,186,32,165,78,5,43,122,216,175,95,108,87,192,162,223,244,164,95,156,27,230,11,236,117,231,74,74,188,167,206,177,159,95,188,47,86,76,228,31,
61,244,53,126,239,125,244,81,139,199,34,221,176,186,144,18,157,158,14,47,245,249,240,246,186,10,51,23,26,45,158,250,8,167,203,164,181,244,245,113,74,221,160,222,218,107,7,189,241,245,253,173,187,247,127,
111,94,91,119,212,235,221,230,227,253,135,15,203,222,3,7,146,126,186,72,231,206,181,156,254,55,211,10,115,19,219,155,116,25,180,13,105,239,58,222,254,81,189,22,239,61,186,209,153,104,90,59,247,236,21,
21,98,92,250,8,240,250,190,244,177,116,82,210,222,156,246,48,180,87,160,243,95,223,152,94,95,245,143,189,62,21,91,157,211,115,123,11,95,237,218,29,89,144,82,81,211,249,46,247,113,195,67,199,143,75,137,
121,129,180,215,169,208,232,243,233,186,178,172,78,207,119,236,217,19,35,74,250,120,169,230,169,67,96,221,111,233,230,231,166,165,189,78,237,49,235,243,245,58,103,250,213,174,93,102,165,58,254,86,41,189,
81,232,227,141,110,111,73,159,176,210,39,110,218,235,244,75,221,181,203,227,30,153,166,165,195,241,111,190,251,46,194,36,81,250,202,87,203,175,155,232,117,127,175,223,147,102,122,99,58,109,134,219,250,
162,17,125,46,62,29,78,111,4,58,143,171,115,159,250,154,69,151,139,55,109,181,181,218,87,123,253,126,163,8,55,172,222,64,244,166,152,151,151,107,222,115,80,100,120,196,14,203,181,77,233,147,82,159,237,
216,225,76,7,184,113,163,63,181,174,154,86,105,69,185,243,214,41,157,27,141,182,189,134,57,121,238,156,124,97,122,248,126,61,228,232,52,57,111,27,129,46,111,254,246,173,216,177,102,219,210,32,116,20,1,
125,183,165,190,248,66,123,18,42,26,94,167,95,122,253,242,235,2,135,43,180,222,235,250,162,11,125,122,198,125,161,133,247,154,123,172,43,180,186,200,160,111,246,79,229,205,249,110,58,109,249,212,69,30,
221,138,163,219,141,162,123,225,109,73,199,47,172,254,170,128,222,36,180,199,238,183,8,227,23,199,207,79,231,12,245,38,210,215,204,23,107,207,87,223,158,31,239,125,1,126,241,83,245,211,247,195,234,175,
4,116,239,214,221,176,169,52,249,86,249,62,157,149,40,125,21,63,21,193,2,179,80,164,139,69,250,202,66,221,167,170,139,80,126,61,220,68,233,169,208,235,220,185,190,144,198,204,160,58,55,30,109,119,153,
106,51,137,202,103,227,117,4,213,70,171,82,39,8,64,32,16,2,204,161,6,130,157,76,33,0,1,27,9,32,168,54,90,149,58,65,0,2,129,16,64,80,3,193,78,166,16,128,128,141,4,16,84,27,173,74,157,32,0,129,64,8,32,168,
129,96,39,83,8,64,192,70,2,8,170,141,86,165,78,16,128,64,32,4,16,212,64,176,147,41,4,32,96,35,1,4,213,70,171,82,39,8,64,32,16,2,8,106,32,216,201,20,2,16,176,145,0,130,106,163,85,169,19,4,32,16,8,1,4,53,
16,236,100,10,1,8,216,72,0,65,181,209,170,212,9,2,16,8,132,0,130,26,8,118,50,133,0,4,108,36,128,160,218,104,85,234,4,1,8,4,66,0,65,13,4,59,153,66,0,2,54,18,64,80,109,180,42,117,130,0,4,2,33,128,160,6,
130,157,76,33,0,1,27,9,32,168,54,90,149,58,65,0,2,129,16,64,80,3,193,78,166,16,128,128,141,4,16,84,27,173,74,157,32,0,129,64,8,32,168,129,96,39,83,8,64,192,70,2,8,170,141,86,165,78,16,128,64,32,4,16,212,
64,176,147,41,4,32,96,35,1,4,213,70,171,82,39,8,64,32,16,2,8,106,32,216,201,20,2,16,176,145,0,130,106,163,85,169,19,4,32,16,8,1,4,53,16,236,100,10,1,8,216,72,0,65,181,209,170,212,9,2,16,8,132,0,130,26,
8,118,50,133,0,4,108,36,128,160,218,104,85,234,4,1,8,4,66,0,65,13,4,59,153,66,0,2,54,18,64,80,109,180,42,117,130,0,4,2,33,128,160,6,130,157,76,33,0,1,27,9,32,168,54,90,149,58,65,0,2,129,16,64,80,3,193,
78,166,16,128,128,141,4,16,84,27,173,74,157,32,0,129,64,8,32,168,129,96,39,83,8,64,192,70,2,8,170,141,86,165,78,16,128,64,32,4,16,212,64,176,147,41,4,32,96,35,1,4,213,70,171,82,39,8,64,32,16,2,86,8,106,
207,30,61,164,123,183,110,173,2,236,221,171,87,171,215,185,8,1,8,64,160,189,4,114,219,155,64,71,196,239,91,80,32,63,219,248,146,188,245,159,191,111,145,252,255,248,245,223,202,191,188,243,174,212,214,
213,57,254,35,134,14,149,85,75,158,147,134,198,70,201,233,154,35,77,77,143,228,211,29,59,228,206,221,202,72,188,133,207,204,145,241,197,197,210,208,208,40,189,122,246,144,83,231,206,203,119,7,15,58,215,
255,246,231,63,151,174,57,93,165,91,110,174,228,154,191,7,63,166,251,249,206,175,165,236,242,229,72,26,28,216,71,32,223,220,96,255,230,231,63,147,255,245,246,255,117,42,55,109,242,100,89,177,120,209,227,
54,208,220,236,180,169,163,167,78,201,145,19,39,165,217,156,227,32,144,12,129,80,10,106,50,5,47,52,162,187,97,245,243,242,167,143,63,145,27,183,111,59,81,138,71,142,144,215,54,108,144,183,255,240,158,
243,133,24,60,112,160,60,253,212,83,242,111,239,254,65,26,31,62,116,122,177,191,126,227,117,41,41,47,147,235,55,111,201,219,239,189,231,196,155,50,97,130,76,24,59,70,54,111,251,60,153,172,9,99,41,129,
11,165,151,228,147,237,219,157,218,169,224,110,120,126,149,228,230,228,202,15,71,142,88,90,99,170,149,110,2,89,59,228,159,51,99,186,148,148,149,69,196,84,193,148,150,87,72,101,85,149,104,111,67,93,94,
94,174,60,124,244,200,233,125,234,121,125,67,131,252,113,243,22,169,174,121,160,167,56,8,196,37,80,243,224,129,28,60,118,92,102,77,155,26,55,12,23,32,16,77,32,227,61,212,162,194,66,153,55,107,150,104,
111,82,123,1,174,251,231,183,126,231,30,58,159,58,39,186,122,233,146,22,126,57,57,57,145,243,129,253,251,203,225,227,39,34,231,238,65,73,121,185,12,236,223,207,57,173,184,114,85,206,151,148,200,95,255,
236,53,185,121,251,142,92,184,84,42,167,206,158,147,186,250,122,55,120,194,207,127,250,135,191,79,24,134,0,45,9,168,24,149,148,149,203,254,67,135,164,242,222,189,150,23,51,112,150,108,27,75,84,148,242,
43,87,164,119,126,190,104,187,123,100,110,204,174,163,77,184,36,130,251,12,186,141,197,171,121,70,5,181,95,223,190,242,242,218,53,242,217,206,157,242,237,190,125,242,160,182,54,94,185,156,158,229,249,
210,210,22,215,167,76,156,24,57,215,121,173,174,93,99,59,216,234,231,157,243,218,185,103,175,236,218,255,189,140,25,57,82,198,140,26,41,139,204,144,95,135,246,250,101,73,198,69,11,125,50,113,58,123,152,
94,61,123,74,145,153,146,121,101,221,139,242,225,214,173,102,212,144,57,81,109,75,27,75,100,39,109,71,77,230,207,43,166,26,135,54,145,136,92,199,95,15,178,141,181,86,187,88,69,106,45,116,59,174,105,175,
97,163,17,211,183,223,123,95,174,92,187,222,170,152,106,54,218,136,47,94,42,107,241,215,220,212,20,41,193,141,91,183,156,94,110,196,227,199,131,98,35,156,238,156,234,164,113,227,100,236,232,81,242,208,
204,159,158,51,61,213,207,191,254,70,190,59,112,80,166,79,121,60,37,16,29,151,243,244,16,208,27,229,229,235,215,157,185,236,87,215,173,147,194,130,62,233,73,56,65,42,109,109,99,9,146,19,157,131,215,41,
36,92,248,8,4,213,198,18,145,200,152,160,206,155,53,83,182,237,216,153,168,60,73,95,63,112,244,152,17,212,145,78,163,119,35,141,27,61,90,10,122,247,150,227,167,207,56,94,42,202,11,231,204,105,177,165,
106,196,208,33,114,191,186,198,141,194,103,7,19,80,155,207,55,83,60,153,112,233,108,99,42,206,43,158,93,204,130,84,38,12,215,206,60,50,217,198,18,21,53,99,67,126,21,191,111,247,237,79,84,158,164,175,223,
175,174,150,143,62,219,38,47,172,88,46,141,186,109,234,199,121,46,93,116,210,30,169,58,157,50,232,95,84,228,108,193,210,173,85,121,185,121,114,183,170,82,246,153,185,61,92,102,8,40,239,226,145,163,50,
146,89,123,219,216,184,226,209,242,119,191,120,67,30,153,145,80,125,125,131,236,59,120,72,78,158,61,155,145,178,147,73,234,4,50,217,198,18,149,50,99,130,170,11,80,173,205,153,122,11,170,11,25,209,123,
80,245,250,255,252,183,183,189,193,228,138,25,86,254,251,251,127,52,251,75,123,58,83,4,186,138,31,237,84,60,245,79,55,246,215,152,161,168,119,126,213,13,123,234,220,57,179,63,245,156,123,202,103,26,9,
212,60,168,53,11,59,79,22,31,211,152,116,76,82,109,105,99,186,168,225,238,65,213,132,142,159,62,237,252,197,36,138,71,232,9,100,178,141,37,130,145,49,65,77,84,144,246,92,79,70,168,171,205,23,8,7,1,8,64,
160,35,9,100,108,14,181,35,43,65,218,16,128,0,4,194,64,0,65,13,131,21,40,3,4,32,96,5,1,4,213,10,51,82,9,8,64,32,12,4,16,212,48,88,129,50,64,0,2,86,16,64,80,173,48,35,149,128,0,4,194,64,0,65,13,131,21,
40,3,4,32,96,5,1,4,213,10,51,82,9,8,64,32,12,4,16,212,48,88,129,50,64,0,2,86,16,64,80,173,48,35,149,128,0,4,194,64,0,65,13,131,21,40,3,4,32,96,5,1,4,213,10,51,82,9,8,64,32,12,4,16,212,48,88,129,50,64,
0,2,86,16,64,80,173,48,35,149,128,0,4,194,64,0,65,13,131,21,40,3,4,32,96,5,1,4,213,10,51,82,9,8,64,32,12,4,16,212,48,88,129,50,64,0,2,86,16,64,80,173,48,35,149,128,0,4,194,64,0,65,13,131,21,40,3,4,32,
96,5,1,4,213,10,51,82,9,8,64,32,12,4,16,212,48,88,129,50,64,0,2,86,16,200,152,160,234,175,76,234,175,147,226,58,23,129,252,94,61,165,186,38,51,63,144,72,27,235,92,109,203,173,109,38,219,152,155,103,188,
207,140,9,106,73,89,185,20,21,22,196,43,7,254,150,18,40,42,236,43,37,101,101,25,169,29,109,44,35,152,67,151,73,38,219,88,162,202,103,76,80,247,31,58,36,107,151,47,79,84,30,174,91,70,96,237,138,229,178,
239,224,193,140,212,138,54,150,17,204,161,203,36,147,109,44,81,229,115,214,172,223,240,155,68,129,210,113,189,174,190,94,74,203,203,229,23,175,188,34,55,111,223,146,71,77,143,164,177,241,97,58,146,38,
141,144,17,208,33,216,224,1,3,229,103,27,95,146,15,182,124,44,247,238,223,207,72,9,105,99,25,193,28,138,76,130,106,99,137,42,223,229,205,223,190,213,156,40,80,58,175,23,22,244,145,249,179,102,73,241,200,
81,210,59,191,87,58,147,38,173,144,16,208,57,83,29,230,107,207,244,94,117,117,198,75,69,27,203,56,242,140,103,24,116,27,139,87,225,140,11,106,188,130,224,15,1,8,64,32,219,9,100,108,14,53,219,65,81,126,
8,64,0,2,137,8,32,168,137,8,113,29,2,16,128,64,146,4,16,212,36,65,17,12,2,16,128,64,34,2,8,106,34,66,92,135,0,4,32,144,36,1,4,53,73,80,4,131,0,4,32,144,136,0,130,154,136,16,215,33,0,1,8,36,73,0,65,77,
18,20,193,32,0,1,8,36,34,128,160,38,34,196,117,8,64,0,2,73,18,64,80,147,4,69,48,8,64,0,2,137,8,32,168,137,8,113,29,2,16,128,64,146,4,16,212,36,65,17,12,2,16,128,64,34,2,8,106,34,66,92,135,0,4,32,144,36,
1,4,53,73,80,4,131,0,4,32,144,136,64,214,11,106,94,110,174,244,238,197,107,0,19,25,154,235,16,128,64,199,19,200,237,248,44,218,158,67,223,130,2,249,155,159,255,76,238,215,212,56,145,187,118,237,42,23,
74,75,101,215,190,253,82,223,208,224,248,245,201,207,23,125,83,119,126,207,94,82,215,80,111,62,123,202,215,123,191,147,243,38,156,235,254,254,151,191,16,233,210,69,154,154,154,164,139,241,212,119,40,30,
56,122,84,206,94,188,40,131,6,12,144,151,214,172,118,130,246,236,222,221,188,240,186,73,26,26,27,157,243,127,127,255,143,242,240,33,47,191,118,57,242,9,1,8,36,71,32,148,130,170,69,127,80,91,43,255,250,
206,187,78,45,242,242,242,228,69,35,158,147,39,140,151,35,39,78,26,141,236,34,155,54,172,151,253,135,14,203,137,51,103,156,48,133,125,250,200,107,47,109,112,226,93,185,126,221,241,211,255,62,216,188,69,
238,86,85,57,231,3,251,247,147,77,235,215,203,197,75,151,228,198,173,91,145,244,87,47,93,34,55,239,220,145,67,199,142,71,226,113,0,1,8,64,160,173,4,178,98,200,223,104,122,142,229,87,174,202,160,254,3,
156,250,77,24,51,70,114,114,114,34,98,170,158,85,230,103,54,78,158,61,39,115,103,206,140,203,160,234,222,125,201,53,241,114,205,52,1,14,2,16,128,64,186,9,100,92,89,138,10,11,101,158,243,19,40,35,36,223,
51,247,249,207,111,253,174,69,221,114,204,48,127,240,192,129,206,80,189,95,81,145,204,156,58,85,118,236,217,237,132,25,96,122,154,165,230,87,84,163,93,137,249,205,170,41,166,23,235,117,227,138,71,59,67,
253,110,221,242,100,220,232,209,114,236,244,105,209,223,30,74,214,253,211,63,252,125,178,65,9,247,35,1,253,57,103,253,5,82,253,209,188,202,123,247,224,2,129,78,67,32,163,130,218,175,111,95,121,121,237,
26,249,108,231,78,249,118,223,62,103,120,30,143,180,14,243,23,206,153,227,92,214,225,255,246,93,187,228,82,69,133,115,222,220,220,44,58,175,26,237,84,132,155,204,53,175,235,111,196,88,133,91,195,23,153,
252,189,115,172,222,112,241,142,163,133,62,94,56,252,159,16,232,101,230,179,139,204,60,248,43,235,94,148,15,183,110,149,202,42,68,245,9,29,142,108,38,144,49,65,213,158,233,70,35,166,111,191,247,126,82,
60,181,23,249,151,207,62,243,13,123,227,214,109,153,62,121,114,204,181,226,145,35,204,47,170,222,110,225,175,243,172,238,28,234,161,227,199,229,141,151,95,150,99,167,78,183,8,195,73,122,9,232,13,80,255,
222,254,195,123,242,235,55,94,151,255,250,248,99,209,233,22,28,4,108,39,16,219,205,235,160,26,207,155,53,83,182,237,216,153,150,212,117,81,73,87,251,103,76,153,18,73,175,111,97,129,25,238,79,144,239,141,
128,198,115,218,83,210,185,215,110,166,247,139,203,12,1,181,185,254,202,45,14,2,157,129,64,198,122,168,197,35,71,154,97,254,254,180,48,213,33,255,159,62,254,68,94,88,185,66,230,204,152,46,181,166,55,171,
195,250,47,191,253,86,174,221,188,217,106,30,250,179,198,195,134,12,150,210,242,199,211,7,173,6,230,98,187,9,220,173,170,116,126,50,188,221,9,145,0,4,178,128,64,198,4,85,5,79,135,129,201,56,93,200,120,
235,63,127,223,106,208,106,179,240,241,193,150,143,69,231,90,187,119,235,102,22,158,30,239,89,245,70,250,221,239,223,241,158,58,199,255,241,199,15,98,252,62,255,250,155,24,63,60,210,67,160,230,65,173,
244,206,231,193,139,244,208,36,149,176,19,200,152,160,118,20,8,221,82,165,127,56,8,64,0,2,65,19,200,216,28,106,208,21,37,127,8,64,0,2,29,77,0,65,237,104,194,164,15,1,8,116,26,2,8,106,167,49,53,21,133,
0,4,58,154,0,130,218,209,132,73,31,2,16,232,52,4,16,212,78,99,106,42,10,1,8,116,52,1,4,181,163,9,147,62,4,32,208,105,8,32,168,157,198,212,84,20,2,16,232,104,2,8,106,71,19,38,125,8,64,160,211,16,64,80,
59,141,169,169,40,4,32,208,209,4,16,212,142,38,76,250,16,128,64,167,33,128,160,118,26,83,83,81,8,64,160,163,9,32,168,29,77,152,244,33,0,129,78,67,0,65,237,52,166,166,162,16,128,64,71,19,64,80,59,154,48,
233,67,0,2,157,134,0,130,218,105,76,77,69,33,0,129,142,38,128,160,118,52,97,210,135,0,4,58,13,1,4,181,211,152,154,138,66,0,2,29,77,0,65,237,104,194,164,15,1,8,116,26,2,8,106,167,49,53,21,133,0,4,58,154,
0,130,218,209,132,73,31,2,16,232,52,4,50,38,168,53,230,87,74,123,245,236,217,105,192,82,209,199,4,242,123,245,52,191,72,251,0,28,16,232,20,4,50,38,168,37,101,229,82,84,88,208,41,160,82,201,39,4,138,10,
251,74,73,89,217,19,15,142,32,96,49,129,140,9,234,254,67,135,100,237,242,229,22,163,164,106,126,4,214,174,88,46,251,14,30,244,187,132,31,4,172,35,144,49,65,173,188,119,79,62,220,250,169,252,250,245,215,
101,196,208,33,162,67,65,156,157,4,212,182,35,134,14,149,191,251,197,27,242,193,150,143,229,94,117,181,157,21,165,86,16,136,34,208,229,205,223,190,213,28,229,215,161,167,133,5,125,100,254,172,89,82,60,
114,148,244,206,239,213,161,121,145,120,48,4,116,206,84,135,249,218,51,69,76,131,177,1,185,6,67,32,55,211,217,86,221,187,47,159,127,253,77,166,179,37,63,8,64,0,2,29,78,32,99,67,254,14,175,9,25,64,0,2,
16,8,152,0,130,26,176,1,200,30,2,16,176,135,0,130,106,143,45,169,9,4,32,16,48,1,4,53,96,3,144,61,4,32,96,15,1,4,213,30,91,82,19,8,64,32,96,2,8,106,192,6,32,123,8,64,192,30,2,8,170,61,182,164,38,16,128,
64,192,4,16,212,128,13,64,246,16,128,128,61,4,16,84,123,108,73,77,32,0,129,128,9,32,168,1,27,128,236,33,0,1,123,8,32,168,246,216,146,154,64,0,2,1,19,64,80,3,54,0,217,67,0,2,246,16,64,80,237,177,37,53,
129,0,4,2,38,128,160,6,108,0,178,135,0,4,236,33,128,160,218,99,75,106,2,1,8,4,76,0,65,13,216,0,100,15,1,8,216,67,0,65,181,199,150,212,4,2,16,8,152,0,130,26,176,1,200,30,2,16,176,135,0,130,106,143,45,169,
9,4,32,16,48,1,4,53,96,3,144,61,4,32,96,15,1,4,213,30,91,82,19,8,64,32,96,2,8,106,192,6,32,123,8,64,192,30,2,8,170,61,182,164,38,16,128,64,192,4,16,212,128,13,64,246,16,128,128,61,4,16,84,123,108,73,77,
32,0,129,128,9,32,168,1,27,128,236,33,0,1,123,8,32,168,246,216,146,154,64,0,2,1,19,64,80,3,54,0,217,67,0,2,246,16,200,237,232,170,76,157,52,73,158,154,56,161,163,179,33,125,8,64,0,2,190,4,78,158,61,39,
39,206,156,241,189,150,110,207,14,23,84,45,112,23,243,15,7,1,8,64,192,118,2,29,46,168,122,103,200,212,221,193,118,99,81,63,8,64,32,220,4,152,67,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,
4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,
69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,
44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,
4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,
32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,
40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,
183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,
0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,
4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,
69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,
44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,4,16,212,44,50,22,69,133,0,4,194,77,0,65,13,183,125,40,29,4,32,144,69,
4,172,22,212,162,194,66,233,217,163,71,22,153,131,162,134,145,0,237,40,140,86,9,103,153,114,195,89,172,246,151,170,75,151,46,178,105,253,58,121,127,243,22,169,173,171,107,127,130,33,72,161,91,94,158,76,
158,48,94,142,159,62,35,77,77,77,237,42,209,180,73,147,100,242,248,241,82,88,88,32,55,111,223,150,67,199,142,75,249,149,43,49,105,62,53,113,162,140,47,46,150,205,159,127,30,115,173,51,120,208,142,90,183,
114,162,118,84,60,114,164,204,157,249,180,20,246,233,35,151,175,93,147,115,37,37,114,190,164,180,245,68,179,248,170,181,61,84,53,228,157,202,74,185,119,255,126,22,155,167,101,209,123,245,236,41,171,158,
123,78,114,186,182,207,108,19,198,142,145,85,75,158,147,211,231,207,203,95,62,253,76,238,220,173,148,159,188,176,86,180,39,166,78,69,100,254,172,89,242,194,138,229,242,252,210,37,162,66,222,89,29,237,
40,190,229,19,181,163,161,131,7,201,75,107,86,75,73,89,153,252,217,180,179,146,178,114,89,183,114,165,76,153,48,33,126,162,89,126,37,103,205,250,13,191,201,242,58,248,22,127,233,130,249,114,252,204,25,
71,44,70,14,27,102,132,232,89,105,110,22,217,240,252,42,89,244,204,28,25,60,104,160,211,35,123,248,240,161,19,191,71,247,238,178,120,222,92,89,182,104,161,44,156,51,71,70,12,29,38,215,110,222,144,186,
250,122,231,250,166,117,235,228,230,157,59,50,111,214,76,89,60,119,158,28,59,117,74,18,197,217,184,118,141,212,155,248,75,22,44,144,149,38,255,177,163,71,203,197,75,151,100,206,140,233,242,162,105,88,
83,77,239,175,217,20,234,198,173,91,145,58,20,152,59,185,94,211,240,227,70,143,146,7,181,181,114,183,170,202,28,143,150,53,203,151,57,83,24,227,138,71,75,147,39,222,168,17,195,101,253,170,85,242,220,252,
249,50,124,200,80,185,126,243,102,164,220,207,206,155,39,5,125,122,203,160,1,3,100,205,178,229,78,157,159,153,49,67,174,222,184,33,123,15,28,112,122,239,101,151,47,59,61,223,166,230,38,167,23,161,133,
233,217,179,135,115,67,106,54,61,225,110,121,221,228,228,185,115,145,50,118,166,3,218,209,227,246,159,74,59,210,118,222,244,168,73,190,252,118,151,211,206,110,153,239,207,208,193,131,165,87,143,158,114,
193,124,15,108,116,237,235,234,132,148,72,126,175,94,70,48,7,201,133,210,199,70,235,214,45,79,70,14,31,238,136,225,142,61,123,101,203,23,95,74,159,252,222,242,170,153,18,112,221,202,103,159,21,21,222,
157,230,250,199,95,126,41,125,11,10,68,27,145,235,250,245,43,114,4,119,240,192,129,114,194,8,181,186,132,113,250,246,149,213,75,151,202,69,115,135,254,228,203,237,142,0,255,234,167,155,100,200,192,65,
178,109,199,78,41,173,168,144,101,11,23,74,110,238,227,153,151,60,211,19,124,253,229,141,82,223,80,47,91,204,16,251,234,141,155,178,206,220,0,6,15,28,32,55,204,176,252,240,137,19,78,190,223,31,62,34,151,
175,94,117,142,135,152,122,110,92,189,90,46,153,180,180,220,205,70,20,181,94,154,150,58,21,211,137,99,199,202,188,153,179,204,80,171,68,30,60,120,32,253,138,138,164,170,234,158,115,221,253,175,242,222,
61,233,111,252,93,167,195,50,253,211,47,65,103,117,180,163,246,181,163,189,63,28,144,143,182,109,139,52,31,109,231,250,29,211,145,163,173,206,74,65,213,121,157,83,166,71,229,157,103,212,97,242,246,93,
187,164,180,188,220,233,165,109,221,190,93,6,245,239,47,163,71,140,112,108,91,91,95,39,59,246,236,113,132,169,226,202,85,211,35,59,27,25,2,187,198,215,121,160,247,63,218,28,17,182,100,226,232,156,209,
241,211,167,157,116,79,158,61,107,238,206,61,100,219,206,157,162,189,194,93,251,246,59,195,235,225,67,134,56,89,60,253,212,20,105,104,108,148,173,219,191,50,215,175,200,215,123,247,58,229,157,57,117,170,
220,175,174,150,82,51,100,82,167,194,232,54,202,5,179,103,203,41,51,116,223,181,255,123,41,171,184,108,230,58,191,144,220,156,28,153,48,102,140,19,86,255,211,97,235,251,155,55,59,61,210,250,134,6,71,108,
171,141,176,122,93,77,205,3,201,203,237,188,67,123,47,11,247,152,118,212,190,118,164,109,185,241,199,17,160,182,201,213,102,250,72,71,124,58,186,179,213,89,185,40,53,109,242,36,249,112,235,167,45,108,
246,240,209,35,185,122,253,70,196,175,202,204,173,86,153,94,153,138,170,246,238,190,218,181,219,244,90,243,69,197,75,135,199,58,63,20,61,255,170,225,188,46,153,56,87,174,93,143,68,169,121,80,235,8,161,
59,141,160,195,125,61,238,250,227,156,168,230,171,126,218,171,117,157,246,146,6,244,235,231,158,198,124,106,239,53,175,50,183,69,28,109,196,195,134,12,22,21,112,117,186,232,84,227,17,80,29,198,123,111,
54,26,70,135,251,250,135,123,66,128,118,148,158,118,212,167,119,111,217,104,230,82,187,116,233,42,127,248,243,95,204,8,172,225,9,100,203,142,172,19,84,157,79,188,103,122,115,58,239,232,117,58,87,26,45,
34,245,230,14,154,155,247,24,193,243,75,150,152,57,206,81,114,246,194,69,169,48,195,105,237,1,78,49,43,234,94,231,21,71,245,79,38,142,10,164,215,69,159,123,175,233,144,72,203,89,91,87,27,241,190,124,181,
86,26,26,26,35,231,209,7,26,71,27,168,55,206,217,11,23,156,41,2,55,108,116,185,53,124,244,118,50,61,175,175,183,183,161,187,44,146,253,164,29,137,249,46,180,191,29,105,39,65,23,60,117,65,106,199,238,221,
145,30,107,178,118,200,182,112,214,9,234,140,41,83,204,144,226,116,140,29,116,1,73,123,122,238,156,96,158,17,162,129,230,252,192,145,163,82,104,230,75,167,79,153,44,239,154,187,231,53,179,88,163,110,238,
204,153,49,105,184,195,23,189,144,108,156,152,68,90,241,208,213,246,222,166,151,252,173,153,10,112,157,246,160,243,243,123,185,167,49,159,26,71,111,30,222,56,99,71,141,146,251,53,53,145,176,141,15,91,
10,242,117,179,8,166,61,91,175,211,134,127,240,232,49,175,87,167,62,166,29,137,180,183,29,233,252,253,207,54,190,36,223,126,183,47,50,77,102,123,163,178,106,14,85,123,89,58,31,121,238,226,69,95,187,45,
152,51,219,89,0,210,33,246,252,217,179,156,21,120,157,227,116,183,33,233,252,166,110,25,210,121,213,153,211,166,74,142,153,247,137,231,82,137,19,47,45,215,255,248,153,211,206,20,132,174,232,171,83,113,
213,69,169,156,174,143,203,241,232,199,189,167,186,120,228,78,19,28,53,243,81,186,159,180,159,89,0,83,55,204,212,255,133,149,43,164,214,236,14,136,231,180,231,49,105,220,56,103,129,64,235,59,123,250,116,
233,109,166,22,116,241,12,103,118,56,208,142,210,210,142,158,121,250,105,103,186,233,132,153,122,210,14,140,251,231,126,119,108,108,107,86,245,80,167,154,197,168,51,70,44,92,225,241,26,76,23,117,238,86,
86,201,63,254,245,95,137,238,159,170,49,130,163,123,227,116,136,173,195,251,163,39,79,57,226,165,113,170,77,239,110,183,89,228,89,179,108,169,217,34,53,87,118,127,255,189,55,41,231,56,149,56,49,137,68,
121,84,154,149,119,93,169,95,109,242,85,49,215,178,233,94,209,243,165,165,78,72,45,151,238,233,123,237,165,13,178,255,208,97,249,238,224,65,103,199,65,97,65,31,249,229,171,175,56,83,26,186,216,164,59,
21,162,23,157,188,89,233,240,75,87,96,215,173,90,233,236,49,213,176,159,126,181,195,89,248,242,134,235,172,199,180,163,38,167,253,180,183,29,105,231,102,160,25,97,253,247,191,253,155,22,77,73,31,34,209,
5,96,27,93,151,55,127,251,86,203,73,190,44,174,101,191,162,190,102,91,80,109,100,15,166,91,21,221,183,185,124,241,98,249,215,119,222,117,86,192,187,155,225,191,119,145,198,13,167,119,78,189,166,123,63,
213,245,48,61,149,70,51,223,232,39,208,237,137,227,198,109,237,83,23,163,252,202,24,47,142,246,52,117,227,127,91,226,104,90,26,199,173,111,188,180,59,155,63,237,136,118,148,106,155,183,170,135,170,243,
137,137,156,174,246,63,244,172,120,123,195,171,112,122,197,165,46,137,71,86,83,137,227,205,51,222,113,91,133,81,23,187,218,26,71,243,246,214,55,94,89,58,155,63,237,168,229,150,186,100,236,79,59,122,76,
201,170,57,212,120,134,175,171,171,119,158,30,138,119,29,127,8,36,67,128,118,148,12,165,206,29,198,170,30,106,60,83,234,75,25,244,15,7,129,246,16,160,29,181,135,94,231,136,219,41,122,168,157,195,148,212,
18,2,16,8,154,0,130,26,180,5,200,31,2,16,176,134,0,130,106,141,41,169,8,4,32,16,52,1,4,53,104,11,144,63,4,32,96,13,1,4,213,26,83,82,17,8,64,32,104,2,8,106,208,22,32,127,8,64,192,26,2,8,170,53,166,164,
34,16,128,64,208,4,16,212,160,45,64,254,16,128,128,53,4,16,84,107,76,73,69,32,0,129,160,9,32,168,65,91,128,252,33,0,1,107,8,32,168,214,152,146,138,64,0,2,65,19,64,80,131,182,0,249,67,0,2,214,16,64,80,
173,49,37,21,129,0,4,130,38,128,160,6,109,1,242,135,0,4,172,33,208,41,94,223,151,170,181,30,153,159,32,233,242,227,79,60,167,154,70,208,241,244,39,163,115,204,239,249,224,130,35,64,59,10,142,125,166,115,
230,155,214,10,113,253,89,17,247,199,240,90,9,22,234,75,77,81,63,99,29,234,194,90,90,56,218,145,165,134,245,169,22,67,126,31,40,120,65,0,2,16,72,133,0,130,154,10,53,226,64,0,2,16,240,33,128,160,250,64,
193,11,2,16,128,64,42,4,16,212,84,168,17,7,2,16,128,128,15,1,4,213,7,10,94,16,128,0,4,82,33,128,160,166,66,141,56,16,128,0,4,124,8,32,168,62,80,240,130,0,4,32,144,10,1,4,53,21,106,196,129,0,4,32,224,67,
0,65,245,129,130,23,4,32,0,129,84,8,32,168,169,80,35,14,4,32,0,1,31,2,8,170,15,20,188,32,0,1,8,164,66,0,65,77,133,26,113,32,0,1,8,248,16,64,80,125,160,224,5,1,8,64,32,21,2,8,106,42,212,136,3,1,8,64,192,
135,0,130,234,3,5,47,8,64,0,2,169,16,64,80,83,161,70,28,8,64,0,2,62,4,16,84,31,40,120,65,0,2,16,72,133,0,130,154,10,53,226,64,0,2,16,240,33,128,160,250,64,193,11,2,16,128,64,42,4,16,212,84,168,17,7,2,
16,128,128,15,1,4,213,7,10,94,16,128,0,4,82,33,128,160,166,66,141,56,16,128,0,4,124,8,32,168,62,80,240,130,0,4,32,144,10,1,4,53,21,106,196,129,0,4,32,224,67,0,65,245,129,130,23,4,32,0,129,84,8,32,168,
169,80,35,14,4,32,0,1,31,2,8,170,15,20,188,32,0,1,8,164,66,0,65,77,133,26,113,32,0,1,8,248,16,64,80,125,160,224,5,1,8,64,32,21,2,8,106,42,212,136,3,1,8,64,192,135,0,130,234,3,5,47,8,64,0,2,169,16,64,80,
83,161,70,28,8,64,0,2,62,4,16,84,31,40,120,65,0,2,16,72,133,0,130,154,10,53,226,64,0,2,16,240,33,128,160,250,64,193,11,2,16,128,64,42,4,16,212,84,168,17,7,2,16,128,128,15,1,4,213,7,10,94,16,128,0,4,82,
33,128,160,166,66,141,56,16,128,0,4,124,8,32,168,62,80,240,130,0,4,32,144,10,1,4,53,21,106,196,129,0,4,32,224,67,0,65,245,129,130,23,4,32,0,129,84,8,32,168,169,80,35,14,4,32,0,1,31,2,8,170,15,20,188,32,
0,1,8,164,66,0,65,77,133,26,113,32,0,1,8,248,16,64,80,125,160,224,5,1,8,64,32,21,2,8,106,42,212,136,3,1,8,64,192,135,0,130,234,3,5,47,8,64,0,2,169,16,64,80,83,161,70,28,8,64,0,2,62,4,16,84,31,40,120,65,
0,2,16,72,133,0,130,154,10,53,226,64,0,2,16,240,33,128,160,250,64,193,11,2,16,128,64,42,4,16,212,84,168,17,7,2,16,128,128,15,1,4,213,7,10,94,16,128,0,4,82,33,128,160,166,66,141,56,16,128,0,4,124,8,32,
168,62,80,240,130,0,4,32,144,10,1,4,53,21,106,196,129,0,4,32,224,67,0,65,245,129,130,23,4,32,0,129,84,8,32,168,169,80,35,14,4,32,0,1,31,2,8,170,15,20,188,32,0,1,8,164,66,0,65,77,133,26,113,32,0,1,8,248,
16,64,80,125,160,224,5,1,8,64,32,21,2,8,106,42,212,136,3,1,8,64,192,135,0,130,234,3,5,47,8,64,0,2,169,16,64,80,83,161,70,28,8,64,0,2,62,4,16,84,31,40,120,65,0,2,16,72,133,0,130,154,10,53,226,64,0,2,16,
240,33,128,160,250,64,193,11,2,16,128,64,42,4,114,83,137,212,89,226,52,55,55,75,83,83,83,86,87,87,235,128,11,150,0,237,40,88,254,153,204,29,65,109,133,118,78,174,5,120,186,50,8,105,197,196,25,185,68,59,
202,8,230,80,100,194,183,45,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,
172,72,29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,
138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,
72,29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,176,90,80,139,10,11,165,103,143,30,161,0,77,33,
178,151,0,237,40,123,109,151,233,146,91,240,195,243,254,200,186,116,233,34,155,214,175,147,247,55,111,145,218,186,58,255,64,89,230,219,45,47,79,38,79,24,47,199,79,159,145,166,166,166,118,149,126,218,164,
73,50,121,252,120,41,44,44,144,155,183,111,203,161,99,199,165,252,202,149,72,154,227,139,139,229,153,153,79,75,126,175,94,114,245,250,117,57,119,177,68,206,149,148,68,174,119,150,3,218,81,235,150,78,212,
142,188,177,215,44,91,42,13,141,141,178,99,247,30,175,183,85,199,214,246,80,139,71,142,148,59,149,149,114,239,254,125,107,12,214,171,103,79,89,245,220,115,146,211,181,125,102,155,48,118,140,172,90,242,
156,156,62,127,94,254,242,233,103,114,231,110,165,252,228,133,181,162,61,49,117,42,162,47,172,88,110,132,251,180,124,184,245,83,41,45,175,144,245,207,175,146,81,195,135,89,195,50,217,138,208,142,226,147,
74,212,142,188,49,159,154,56,81,148,101,94,110,158,215,219,186,227,156,53,235,55,252,198,186,90,153,10,45,93,48,95,142,159,57,227,136,197,200,97,195,140,16,61,43,205,205,34,27,140,48,44,122,102,142,12,
30,52,208,233,145,61,124,248,208,169,126,143,238,221,101,241,188,185,178,108,209,66,89,56,103,142,140,24,58,76,174,221,188,33,117,245,245,206,245,77,235,214,201,205,59,119,100,222,172,153,178,120,238,
60,57,118,234,148,36,138,179,113,237,26,169,55,241,151,44,88,32,43,77,254,99,71,143,150,139,151,46,201,156,25,211,229,197,149,43,101,170,105,100,205,166,80,55,110,221,138,152,160,160,79,31,231,154,134,
31,55,122,148,60,168,173,149,187,85,85,230,120,180,172,89,190,204,153,194,24,87,60,90,154,60,241,70,141,24,46,235,87,173,146,231,230,207,151,225,67,134,202,245,155,55,35,229,126,118,222,60,41,232,211,
91,6,13,24,32,107,150,45,119,234,252,204,140,25,114,245,198,13,217,123,224,128,211,123,47,187,124,217,233,249,54,53,55,201,229,107,215,100,236,168,81,114,191,166,90,126,56,114,84,234,76,239,254,206,221,
187,50,115,234,84,169,184,122,77,110,25,6,157,201,209,142,30,183,255,84,218,145,219,78,250,154,81,144,126,111,46,94,42,19,29,101,93,48,223,1,91,93,251,186,58,33,165,162,61,172,193,131,6,201,133,210,199,
134,235,214,45,79,70,14,31,238,24,117,199,158,189,178,229,139,47,165,79,126,111,121,213,76,9,184,110,229,179,207,138,10,239,78,115,253,227,47,191,148,190,5,5,162,141,200,117,253,250,21,57,130,59,120,224,
64,57,97,132,90,93,194,56,125,251,202,234,165,75,229,98,89,153,124,242,229,118,71,128,127,245,211,77,50,100,224,32,217,182,99,167,148,86,84,200,178,133,11,37,55,247,241,204,75,158,105,108,175,191,188,
81,234,27,234,101,203,231,159,27,209,187,41,235,204,13,96,240,192,1,114,195,12,203,15,159,56,225,228,251,253,225,35,114,249,234,85,231,120,136,169,231,198,213,171,229,146,73,75,203,221,108,68,81,235,165,
105,169,83,49,157,56,118,172,204,155,57,75,206,155,33,251,131,7,15,164,95,81,145,84,85,221,115,174,187,255,85,222,187,39,253,141,191,186,51,23,46,200,183,251,246,75,87,211,19,238,87,212,87,150,154,155,
76,93,67,131,148,152,122,116,38,71,59,106,95,59,210,182,162,109,104,205,178,101,242,213,174,221,166,19,208,190,105,170,108,104,123,86,10,170,206,235,156,58,119,174,197,60,163,14,147,183,239,218,101,134,
175,229,78,47,109,235,246,237,50,168,127,127,25,61,98,132,99,167,218,250,58,217,177,103,143,35,76,21,87,174,202,201,115,103,35,67,96,215,144,133,166,247,248,254,71,155,35,194,150,76,28,157,119,212,161,
179,10,222,201,179,103,165,151,89,36,219,182,115,167,104,175,112,151,17,45,157,163,27,62,100,136,147,197,211,79,77,113,230,152,182,110,255,202,92,191,34,95,239,221,235,148,87,123,135,247,171,171,165,180,
172,220,9,167,194,168,211,25,234,22,204,158,45,167,204,208,125,215,254,239,165,172,226,178,108,254,252,11,201,205,201,145,9,99,198,56,215,245,63,29,106,189,191,121,179,211,35,173,55,194,168,98,91,109,
132,213,235,106,106,30,196,12,199,6,244,235,39,255,109,211,38,167,119,122,236,228,41,35,244,13,222,40,214,31,211,142,218,223,142,180,83,162,237,85,71,89,157,193,89,185,40,53,109,242,36,103,238,207,107,
192,135,143,30,153,197,149,27,17,175,42,51,183,90,101,122,101,42,170,42,118,122,7,237,147,159,239,136,135,14,143,117,126,40,122,254,85,195,121,93,50,113,174,92,187,30,137,82,243,160,214,17,66,119,26,65,
135,251,122,172,119,113,117,154,175,250,105,175,214,117,218,75,82,97,139,231,180,247,154,87,153,219,34,78,163,153,198,24,54,100,176,35,224,26,79,23,157,106,60,2,218,108,22,180,162,23,181,180,247,16,221,
131,208,169,136,255,249,111,111,27,65,30,97,230,84,87,136,153,49,49,211,0,71,226,21,197,58,127,218,81,251,218,145,182,155,161,102,4,165,55,243,206,226,172,19,84,157,79,188,103,122,115,209,119,68,157,43,
141,22,145,122,179,226,152,155,247,24,193,243,75,150,152,57,206,81,114,246,194,69,51,87,120,213,17,190,41,102,69,221,235,188,226,168,254,201,196,81,129,244,186,232,115,239,53,29,250,107,57,107,235,106,
35,222,151,175,214,74,67,67,99,228,60,250,64,227,104,207,209,27,231,172,25,178,235,20,129,235,162,203,173,225,163,183,147,233,121,125,253,227,30,168,138,116,181,233,177,170,8,43,51,157,251,210,30,191,
206,221,118,22,65,165,29,137,249,46,180,175,29,233,218,65,117,77,141,179,126,160,109,81,167,186,242,204,247,109,249,162,69,206,104,208,109,159,54,125,90,39,168,51,166,76,49,11,70,167,99,108,164,11,72,
218,211,115,23,85,242,140,16,13,52,231,7,204,194,75,161,153,47,157,62,101,178,188,251,231,191,200,53,179,88,163,110,238,204,153,49,105,104,207,207,117,201,198,113,195,39,243,169,171,237,189,77,47,89,231,
47,93,167,61,232,252,252,94,238,105,204,167,198,209,155,135,55,206,227,69,165,154,72,216,198,135,45,5,249,186,233,121,170,104,122,157,246,142,15,30,61,230,120,233,162,155,78,49,124,241,205,55,145,32,42,
172,237,221,93,16,73,44,11,14,104,71,242,227,226,100,234,237,232,244,249,11,45,110,220,218,134,180,67,241,240,209,147,239,81,22,52,133,54,21,209,170,57,84,237,101,233,124,228,185,139,23,125,33,44,152,
51,219,89,0,210,33,246,252,217,179,156,21,120,157,227,116,133,66,231,55,117,78,83,231,85,103,78,155,42,57,102,46,50,158,75,37,78,188,180,92,255,227,103,78,59,83,16,186,162,175,78,197,85,23,165,114,186,
62,46,199,35,211,32,213,233,226,145,59,77,112,212,236,54,208,253,164,253,204,2,152,186,97,166,254,47,172,92,33,181,102,119,64,60,167,61,143,73,227,198,57,139,112,90,223,217,211,167,75,111,51,181,160,139,
103,234,116,241,73,167,60,198,152,213,126,189,62,98,216,80,153,106,230,165,221,235,241,210,181,197,159,118,148,158,118,180,255,208,33,103,29,64,215,2,156,245,128,138,114,103,218,205,123,243,183,165,205,
184,245,176,170,135,170,95,122,93,161,118,133,199,173,164,126,106,143,235,110,101,149,252,227,95,255,149,152,219,164,212,24,193,249,179,217,131,169,67,108,93,224,57,106,22,93,84,188,212,233,48,101,183,
89,228,209,141,200,139,231,206,149,221,223,127,239,248,123,255,75,37,142,55,190,223,113,165,89,121,215,149,250,213,38,95,21,115,45,155,238,21,61,95,90,234,4,215,114,169,216,189,246,210,6,217,127,232,176,
124,119,240,160,179,227,160,176,160,143,252,242,213,87,156,225,185,46,54,233,78,133,232,69,39,111,126,37,102,113,107,239,15,7,100,221,170,149,206,54,22,13,251,233,87,59,28,70,26,78,119,19,232,86,151,141,
107,86,59,105,170,120,171,112,239,59,120,200,155,140,181,199,180,163,38,167,253,180,183,29,89,219,64,90,169,88,151,55,127,251,86,203,73,190,86,2,135,253,146,110,241,121,96,22,126,220,69,31,183,188,58,
247,183,124,241,98,249,215,119,222,117,86,192,187,155,225,191,119,145,198,13,167,189,78,189,166,123,63,213,245,48,61,214,70,51,223,232,39,208,237,137,227,198,109,237,83,23,163,252,202,24,47,142,246,36,
117,227,127,91,226,104,90,26,199,173,111,116,218,42,164,218,75,86,33,143,158,127,142,14,107,211,57,237,40,189,237,200,166,182,145,168,46,86,245,80,117,62,49,145,211,213,254,135,158,21,111,111,120,21,78,
175,184,232,166,246,68,46,149,56,137,210,212,235,109,21,70,157,155,106,107,28,205,199,91,95,61,247,58,21,209,232,157,14,222,235,182,30,211,142,90,110,169,75,198,206,173,181,163,100,226,219,18,198,170,
57,212,120,70,169,171,171,119,158,30,138,119,29,127,8,36,67,128,118,148,12,165,206,29,198,170,30,106,60,83,234,227,148,250,135,131,64,123,8,208,142,218,67,175,115,196,237,20,61,212,206,97,74,106,9,1,8,
4,77,0,65,13,218,2,228,15,1,8,88,67,0,65,181,198,148,84,4,2,16,8,154,0,130,26,180,5,200,31,2,16,176,134,0,130,106,141,41,169,8,4,32,16,52,1,4,53,104,11,144,63,4,32,96,13,1,4,213,26,83,82,17,8,64,32,104,
2,8,106,208,22,32,127,8,64,192,26,2,8,170,53,166,164,34,16,128,64,208,4,16,212,160,45,64,254,16,128,128,53,4,16,84,107,76,73,69,32,0,129,160,9,32,168,65,91,128,252,33,0,1,107,8,32,168,214,152,146,138,
64,0,2,65,19,64,80,131,182,0,249,67,0,2,214,16,232,20,175,239,75,213,90,143,204,79,144,116,49,111,173,207,102,167,63,25,157,99,126,144,16,23,28,1,218,81,112,236,51,157,51,223,180,86,136,235,207,138,184,
63,134,215,74,176,80,95,106,138,250,25,235,80,23,214,210,194,209,142,44,53,172,79,181,178,187,251,229,83,33,188,32,0,1,8,4,69,0,65,13,138,60,249,66,0,2,214,17,64,80,173,51,41,21,130,0,4,130,34,128,160,
6,69,158,124,33,0,1,235,8,32,168,214,153,148,10,65,0,2,65,17,64,80,131,34,79,190,16,128,128,117,4,16,84,235,76,74,133,32,0,129,160,8,32,168,65,145,39,95,8,64,192,58,2,8,170,117,38,165,66,16,128,64,80,
4,16,212,160,200,147,47,4,32,96,29,1,4,213,58,147,82,33,8,64,32,40,2,8,106,80,228,201,23,2,16,176,142,0,130,106,157,73,169,16,4,32,16,20,1,4,53,40,242,228,11,1,8,88,71,0,65,181,206,164,84,8,2,16,8,138,
0,130,26,20,121,242,133,0,4,172,35,128,160,90,103,82,42,4,1,8,4,69,0,65,13,138,60,249,66,0,2,214,17,64,80,173,51,41,21,130,0,4,130,34,128,160,6,69,158,124,33,0,1,235,8,32,168,214,153,148,10,65,0,2,65,
17,64,80,131,34,79,190,16,128,128,117,4,16,84,235,76,74,133,32,0,129,160,8,32,168,65,145,39,95,8,64,192,58,2,8,170,117,38,165,66,16,128,64,80,4,16,212,160,200,147,47,4,32,96,29,1,4,213,58,147,82,33,8,
64,32,40,2,8,106,80,228,201,23,2,16,176,142,0,130,106,157,73,169,16,4,32,16,20,1,4,53,40,242,228,11,1,8,88,71,0,65,181,206,164,84,8,2,16,8,138,0,130,26,20,121,242,133,0,4,172,35,128,160,90,103,82,42,4,
1,8,4,69,0,65,13,138,60,249,66,0,2,214,17,64,80,173,51,41,21,130,0,4,130,34,128,160,6,69,158,124,33,0,1,235,8,32,168,214,153,148,10,65,0,2,65,17,64,80,131,34,79,190,16,128,128,117,4,16,84,235,76,74,133,
32,0,129,160,8,32,168,65,145,39,95,8,64,192,58,2,8,170,117,38,165,66,16,128,64,80,4,16,212,160,200,147,47,4,32,96,29,1,4,213,58,147,82,33,8,64,32,40,2,8,106,80,228,201,23,2,16,176,142,0,130,106,157,73,
169,16,4,32,16,20,1,4,53,40,242,228,11,1,8,88,71,0,65,181,206,164,84,8,2,16,8,138,0,130,26,20,121,242,133,0,4,172,35,128,160,90,103,82,42,4,1,8,4,69,0,65,13,138,60,249,66,0,2,214,17,64,80,173,51,41,21,
130,0,4,130,34,128,160,6,69,158,124,33,0,1,235,8,32,168,214,153,148,10,65,0,2,65,17,64,80,131,34,79,190,16,128,128,117,4,16,84,235,76,74,133,32,0,129,160,8,32,168,65,145,39,95,8,64,192,58,2,8,170,117,
38,165,66,16,128,64,80,4,16,212,160,200,147,47,4,32,96,29,1,4,213,58,147,82,33,8,64,32,40,2,8,106,80,228,201,23,2,16,176,142,0,130,106,157,73,169,16,4,32,16,20,1,4,53,40,242,228,11,1,8,88,71,0,65,181,
206,164,84,8,2,16,8,138,0,130,26,20,121,242,133,0,4,172,35,128,160,90,103,82,42,4,1,8,4,69,0,65,13,138,60,249,66,0,2,214,17,64,80,173,51,41,21,130,0,4,130,34,144,27,84,198,217,144,111,115,115,179,52,53,
53,101,67,81,227,150,81,235,128,11,150,0,237,40,88,254,153,204,29,65,109,133,118,78,174,5,120,186,50,8,105,197,196,25,185,68,59,202,8,230,80,100,194,183,45,20,102,160,16,16,128,128,13,4,16,84,27,172,72,
29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,
1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,64,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,
32,0,129,80,16,64,171,116,210,192,0,0,0,95,73,68,65,84,80,67,97,6,10,1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,64,80,67,97,6,10,
1,1,8,216,64,0,65,181,193,138,212,1,2,16,8,5,1,4,53,20,102,160,16,16,128,128,13,4,16,84,27,172,72,29,32,0,129,80,16,248,255,2,88,102,178,12,91,213,216,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* Editor::bg_png = (const char*) resource_Editor_bg_png;
const int Editor::bg_pngSize = 16629;

// JUCER_RESOURCE: extendToggle_png, 239, "../Resource/extendToggle.png"
static const unsigned char resource_Editor_extendToggle_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,12,0,0,0,12,8,6,0,0,0,86,117,92,231,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,56,
101,88,73,102,77,77,0,42,0,0,0,8,0,1,135,105,0,4,0,0,0,1,0,0,0,26,0,0,0,0,0,2,160,2,0,4,0,0,0,1,0,0,0,12,160,3,0,4,0,0,0,1,0,0,0,12,0,0,0,0,48,196,216,103,0,0,0,101,73,68,65,84,40,21,99,96,160,4,252,255,
255,95,28,136,147,128,152,137,40,115,128,10,21,128,24,4,46,0,177,57,65,77,64,69,48,13,32,77,255,128,120,17,16,139,225,212,8,148,68,214,0,228,130,193,71,32,89,12,196,236,24,26,129,130,216,52,128,117,1,
137,187,64,236,65,156,231,48,140,134,10,224,176,129,104,39,145,228,105,162,131,149,180,136,195,229,55,100,113,0,143,22,183,161,32,159,104,32,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* Editor::extendToggle_png = (const char*) resource_Editor_extendToggle_png;
const int Editor::extendToggle_pngSize = 239;

// JUCER_RESOURCE: button_png, 1224, "../Resource/button.png"
static const unsigned char resource_Editor_button_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,126,0,0,0,30,8,6,0,0,0,234,215,170,210,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,56,101,
88,73,102,77,77,0,42,0,0,0,8,0,1,135,105,0,4,0,0,0,1,0,0,0,26,0,0,0,0,0,2,160,2,0,4,0,0,0,1,0,0,0,126,160,3,0,4,0,0,0,1,0,0,0,30,0,0,0,0,154,108,66,49,0,0,4,62,73,68,65,84,104,5,237,91,75,75,28,65,16,
174,29,215,247,131,28,69,193,93,240,125,16,247,224,65,5,9,136,120,81,136,254,130,232,47,72,254,65,246,39,248,15,162,191,96,13,40,30,246,98,14,94,68,48,43,34,42,40,81,65,20,21,214,55,190,83,95,179,179,
51,246,56,236,204,62,116,178,211,5,147,233,233,174,233,234,170,175,186,170,122,214,4,40,69,115,115,115,95,185,249,157,175,136,222,167,238,69,101,129,63,172,205,212,232,232,232,12,180,10,224,31,6,253,39,
223,38,208,86,84,244,22,152,102,240,39,3,243,243,243,19,47,47,47,0,94,145,79,44,16,8,4,38,53,6,253,155,79,244,85,106,166,44,0,204,53,110,171,156,238,63,151,136,0,120,69,62,180,128,2,222,135,160,67,101,
5,188,2,222,167,22,240,169,218,255,205,142,47,43,43,163,186,186,58,42,45,45,125,87,168,62,74,110,161,149,12,22,80,192,30,159,23,163,247,247,247,179,227,227,227,201,88,44,246,137,141,56,198,71,137,40,203,
12,57,149,219,208,208,64,157,157,157,84,81,81,65,143,143,143,20,12,6,233,244,244,148,214,215,215,233,250,250,90,76,211,212,212,68,237,237,237,20,143,199,45,211,14,12,12,208,241,241,49,109,111,111,139,
177,161,161,33,42,47,47,183,240,161,131,191,105,164,251,115,145,139,245,54,54,54,210,202,202,10,37,147,201,244,156,94,106,20,4,120,6,247,55,131,52,6,192,117,101,83,237,105,118,128,89,6,111,150,157,226,
179,62,102,119,15,133,66,2,80,128,124,116,116,68,207,207,207,84,85,85,37,28,161,191,191,159,22,23,23,233,225,225,65,188,206,243,217,77,67,242,216,214,214,22,29,28,28,216,242,103,43,23,114,186,187,187,
69,100,90,90,90,162,219,219,91,91,25,31,61,80,136,80,191,39,131,110,86,18,14,128,113,238,219,51,247,203,237,146,146,18,1,250,230,230,38,29,30,30,10,208,193,115,115,115,67,171,171,171,180,179,179,99,187,
115,229,185,228,103,68,142,187,187,59,203,5,190,108,229,106,154,70,61,61,61,132,212,224,117,208,161,103,222,129,103,175,143,154,119,58,132,200,132,113,240,201,253,230,231,218,218,90,145,207,1,186,76,216,
249,187,187,187,116,117,117,245,106,168,178,178,146,228,11,128,200,132,58,65,230,211,107,135,108,228,226,221,190,190,62,225,52,203,203,203,244,244,244,36,139,244,220,115,222,67,61,114,186,19,45,193,199,
6,179,253,141,160,186,186,90,236,114,236,78,39,4,227,15,14,14,58,97,165,182,182,54,113,153,153,17,250,215,214,214,200,173,92,56,22,210,14,194,60,138,207,154,154,26,139,67,154,229,120,165,157,119,224,51,
237,118,93,113,240,241,175,130,250,163,229,206,142,65,48,42,46,236,112,153,96,104,174,37,210,221,200,245,200,249,50,245,246,246,202,93,132,244,33,231,120,93,134,91,185,72,13,151,151,151,34,253,192,1,34,
145,136,8,245,230,181,89,22,224,129,14,107,28,204,113,81,168,222,157,76,145,137,15,185,28,132,93,36,19,156,97,120,120,152,194,225,240,171,33,128,38,95,111,1,128,80,44,243,233,145,197,173,92,188,135,154,
3,114,18,137,4,33,85,180,180,180,188,90,151,23,31,242,14,60,142,108,78,20,205,196,135,163,218,197,197,133,5,92,204,93,95,95,47,142,117,103,103,103,78,68,185,226,113,43,23,128,235,206,133,154,3,199,198,
214,214,214,55,29,214,213,66,10,204,156,119,224,217,8,63,50,237,102,140,131,47,147,110,8,201,56,79,119,116,116,164,63,220,96,71,33,71,163,232,67,136,205,134,80,15,200,197,29,158,117,202,69,46,78,27,231,
231,231,34,228,35,50,121,149,242,158,227,89,209,48,27,150,177,141,113,26,55,206,241,186,1,0,58,198,193,167,247,217,221,79,78,78,8,85,114,87,87,23,53,55,55,167,63,224,236,239,239,211,198,198,134,221,107,
25,251,223,42,238,240,210,194,194,130,168,39,114,149,139,144,143,15,71,144,3,39,242,34,5,184,192,50,42,164,252,174,240,47,79,23,229,162,235,23,28,32,5,248,23,244,241,21,230,203,21,225,124,140,47,110,8,
197,122,33,230,106,130,44,153,63,74,110,150,203,117,252,90,33,129,119,188,8,197,248,254,22,240,110,18,122,127,91,248,74,162,2,222,87,112,27,202,42,224,13,91,248,170,165,128,247,21,220,134,178,248,243,
234,132,241,168,90,126,176,0,48,231,111,12,218,148,31,148,85,58,26,22,0,230,218,200,200,200,52,119,205,24,221,170,85,228,22,152,1,230,34,199,243,255,165,154,224,95,187,38,85,216,47,94,200,129,45,48,6,
214,208,242,31,69,176,41,15,56,184,38,221,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* Editor::button_png = (const char*) resource_Editor_button_png;
const int Editor::button_pngSize = 1224;


//[EndFile] You can add extra defines here...
//[/EndFile]

