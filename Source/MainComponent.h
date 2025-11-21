#pragma once
#include <JuceHeader.h>
class MainComponent : public juce::Component
{
    public:
        MainComponent();
        ~MainComponent() override = default;

        void paint(juce::Graphics& g) override;
        void resized() override;

    private:
        juce::Slider slider;
        juce::Label valueLabel;
        void updateLabel();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};