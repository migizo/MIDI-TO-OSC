/*
  ==============================================================================

    Parameter.h
    Created: 15 Mar 2021 8:22:11pm
    Author:  migizo

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Parameter : public juce::AudioProcessorParameter {
    
public:
    
    Parameter () {}
    Parameter(juce::String paramName) : name(paramName) {}
    Parameter(juce::String paramName, float minVal, float maxVal, float defaultVal)
    : name(paramName), minValue(minVal), maxValue(maxVal), defaultValue(defaultVal) {}

    bool isChanged() {
        bool lastStandbyChanged = isStandbyChanged;
        isStandbyChanged = false;
        return lastStandbyChanged;
    }
    // getter
    float getValue () const override {return value; }
    float getDefaultValue () const override {return defaultValue;}
    juce::String getName (int maximumStringLength) const override {return name;}
    juce::String getLabel () const override {return juce::String();}
    float getValueForText (const juce::String &text) const override {
        return juce::jmin(maxValue, juce::jmax(minValue, text.getFloatValue()));
    }
    
    // setter
    void setValue(float newValue) override {
        value = juce::jmap(newValue, 0.0f, 1.0f, minValue, maxValue);
        isStandbyChanged = true;
    }
    void setMin(float minVal) {minValue = minVal;}
    void setMax(float maxVal) {maxValue = maxVal;}
    void setDefault(float defVal) {
        defaultValue = defVal;
        setValueNotifyingHost(defVal);
    }

private:
    bool isStandbyChanged = false;
    juce::String name = "";
    float value = 0.0f;
    float minValue = 0.0f;
    float maxValue = 1.0f;
    float defaultValue = 0.0f;
    
};
