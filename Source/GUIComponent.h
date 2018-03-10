/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Interpreter.hpp"
#include "CodeEditor.hpp"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUIComponent  : public Component,
                      public Button::Listener
{
public:
    //==============================================================================
    GUIComponent ();
    ~GUIComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    Interpreter interpreter;
    ScopedPointer<CodeEditor> codeEditor;
    StringRef charactersToRemove = " \r\n";

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextEditor> inputEditor;
    ScopedPointer<TextEditor> outputEditor;
    ScopedPointer<TextEditor> errorMessagesEditor;
    ScopedPointer<TextButton> executeCodeButton;
    ScopedPointer<Label> brainfuckCodeLabel;
    ScopedPointer<Label> inputLabel;
    ScopedPointer<Label> outputLabel;
    ScopedPointer<Label> errorsAndWarningsLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
