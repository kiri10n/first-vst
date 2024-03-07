/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class FirstVSTAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FirstVSTAudioProcessorEditor (FirstVSTAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~FirstVSTAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FirstVSTAudioProcessor& audioProcessor;
    
    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef juce::AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
    
    juce::AudioProcessorValueTreeState& valueTreeState;
    juce::Slider gainSlider;
    std::unique_ptr<SliderAttachment> gainSliderAttachment;
    juce::Slider panAngleSlider;
    std::unique_ptr<SliderAttachment> panAngleSliderAttachment;
    juce::ComboBox panRuleBox;
    std::unique_ptr<ComboBoxAttachment> panRuleBoxAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FirstVSTAudioProcessorEditor)
};
