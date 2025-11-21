#include <JuceHeader.h>
#include "MainComponent.h"

class JuceSliderDemoApplication : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override { return "Juce Slider Demo"; }
    const juce::String getApplicationVersion() override { return "0.0.1";
}
    bool moreThanOneInstanceAllowed() override { return true; }

    void initialise(const juce::String&) override
    {
        mainWindow = std::make_unique<MainWindow>(getApplicationName());
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted(const juce::String&) override {}

    class MainWindow : public juce::DocumentWindow
    {
    public:
        MainWindow(juce::String name)
            : juce::DocumentWindow(name,
                                    juce::Colours::black,
                                    DocumentWindow::allButtons)
        {   
            setUsingNativeTitleBar(true);
            setResizable(true, true);

            setContentOwned(new MainComponent(), true);

            centreWithSize(getWidth(), getHeight());
            setVisible(true);
        }
        void closeButtonPressed() override
        {
            juce::JUCEApplication::getInstance()->systemRequestedQuit();
        }
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};
START_JUCE_APPLICATION(JuceSliderDemoApplication)