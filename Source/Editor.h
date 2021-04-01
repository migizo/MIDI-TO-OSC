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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Knob.h"
#include "ExtendToggle.h"
#include "AnimatorByCount.h"
#include "PingThread.h"
typedef juce::AudioProcessorValueTreeState::SliderAttachment KnobAttachment;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Editor  : public juce::AudioProcessorEditor,
                private juce::Timer,
                public juce::TextEditor::Listener,
                public juce::Slider::Listener,
                public juce::Button::Listener
{
public:
    //==============================================================================
    Editor (MIDITOOSCAudioProcessor& p, juce::AudioProcessorValueTreeState& vts);
    ~Editor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void textEditorTextChanged(juce::TextEditor& t) override{}
    void textEditorReturnKeyPressed(juce::TextEditor& t) override;
    void textEditorEscapeKeyPressed(juce::TextEditor& t) override{}
    void textEditorFocusLost(juce::TextEditor& t) override;
    void onChangeTextEdit(juce::TextEditor& t);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* bg_png;
    static const int bg_pngSize;
    static const char* extendToggle_png;
    static const int extendToggle_pngSize;
    static const char* button_png;
    static const int button_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    void timerCallback() override;

    MIDITOOSCAudioProcessor& processor;
    Knob knob;

    juce::AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<KnobAttachment> parameter01Attachment;
    std::unique_ptr<KnobAttachment> parameter02Attachment;
    std::unique_ptr<KnobAttachment> parameter03Attachment;
    std::unique_ptr<KnobAttachment> parameter04Attachment;

    float successButtonBgAlpha = 0.0f;
    float errorButtonBgAlpha = 0.0f;
    AnimatorByCount successAlphaAnimator;
    AnimatorByCount errorAlphaAnimator;

    // extendToggle
    ExtendToggle extendToggleLookAndFeel;
    double defaultHeight = 338.0;
    double extendHeight = 581.0;
    AnimatorByCount animator;
    PingThread ping;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> parameter01;
    std::unique_ptr<juce::Slider> parameter02;
    std::unique_ptr<juce::Slider> parameter03;
    std::unique_ptr<juce::Slider> parameter04;
    std::unique_ptr<juce::ImageButton> extendToggle;
    std::unique_ptr<juce::TextEditor> portTextEditor;
    std::unique_ptr<juce::TextEditor> hostTextEditor;
    std::unique_ptr<juce::TextEditor> idTextEditor;
    std::unique_ptr<juce::ImageButton> checkButton;
    juce::Image cachedImage_bg_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Editor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

