#include "MainComponent.h"

MainComponent::MainComponent()
{
    slider.setRange(0.0, 100.0, 1.0);
    slider.setValue(50.0);
    slider.setSliderStyle(juce::Slider::LinearHorizontal);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    slider.onValueChange = [this]() { updateLabel(); };

    addAndMakeVisible(slider);

    valueLabel.setText("Valeur : 50", juce::dontSendNotification);
    valueLabel.setJustificationType(juce::Justification::centred);
    valueLabel.setFont(juce::Font(18.0f));

    addAndMakeVisible(valueLabel);
    
    setSize(400, 200);

    updateLabel();
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);

    g.setColour(juce::Colours::white);
    g.setFont(juce::Font(20.0f, juce::Font::bold));
    g.drawFittedText("Demo JUCE : Slider + Label",
                    getLocalBounds().removeFromTop(40),
                    juce::Justification::centred,
                    1);
}

void MainComponent::resized()
{

    auto area = getLocalBounds().reduced(20);
    area.removeFromTop(40);

    auto labelArea = area.removeFromTop(40);
    valueLabel.setBounds(labelArea);
    
    auto sliderArea = area.removeFromTop(60);
    slider.setBounds(sliderArea);
}

void MainComponent::updateLabel()
{
    auto value = slider.getValue();
    valueLabel.setText("Valeur : " + juce::String(value),
juce::dontSendNotification);
}