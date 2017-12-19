/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUIComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUIComponent::GUIComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (brainfuckCodeEditor = new TextEditor ("brainfuckCodeEditor"));
    brainfuckCodeEditor->setMultiLine (true);
    brainfuckCodeEditor->setReturnKeyStartsNewLine (true);
    brainfuckCodeEditor->setReadOnly (false);
    brainfuckCodeEditor->setScrollbarsShown (true);
    brainfuckCodeEditor->setCaretVisible (true);
    brainfuckCodeEditor->setPopupMenuEnabled (true);
    brainfuckCodeEditor->setColour (TextEditor::textColourId, Colours::white);
    brainfuckCodeEditor->setText (String());

    addAndMakeVisible (inputEditor = new TextEditor ("inputEditor"));
    inputEditor->setMultiLine (false);
    inputEditor->setReturnKeyStartsNewLine (false);
    inputEditor->setReadOnly (false);
    inputEditor->setScrollbarsShown (true);
    inputEditor->setCaretVisible (true);
    inputEditor->setPopupMenuEnabled (true);
    inputEditor->setColour (TextEditor::textColourId, Colours::white);
    inputEditor->setText (String());

    addAndMakeVisible (outputEditor = new TextEditor ("outputEditor"));
    outputEditor->setMultiLine (false);
    outputEditor->setReturnKeyStartsNewLine (false);
    outputEditor->setReadOnly (false);
    outputEditor->setScrollbarsShown (true);
    outputEditor->setCaretVisible (true);
    outputEditor->setPopupMenuEnabled (true);
    outputEditor->setColour (TextEditor::textColourId, Colours::white);
    outputEditor->setText (String());

    addAndMakeVisible (errorMessagesEditor = new TextEditor ("errorMessagesEditor"));
    errorMessagesEditor->setMultiLine (true);
    errorMessagesEditor->setReturnKeyStartsNewLine (true);
    errorMessagesEditor->setReadOnly (false);
    errorMessagesEditor->setScrollbarsShown (true);
    errorMessagesEditor->setCaretVisible (true);
    errorMessagesEditor->setPopupMenuEnabled (true);
    errorMessagesEditor->setColour (TextEditor::textColourId, Colours::white);
    errorMessagesEditor->setText (String());

    addAndMakeVisible (executeCodeButton = new TextButton ("executeCodeButton"));
    executeCodeButton->setButtonText (TRANS("Execute"));
    executeCodeButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUIComponent::~GUIComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    brainfuckCodeEditor = nullptr;
    inputEditor = nullptr;
    outputEditor = nullptr;
    errorMessagesEditor = nullptr;
    executeCodeButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUIComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff505050));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUIComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    brainfuckCodeEditor->setBounds (0, 64, 600, 100);
    inputEditor->setBounds (0, 198, 600, 30);
    outputEditor->setBounds (0, 246, 600, 30);
    errorMessagesEditor->setBounds (0, 294, 600, 100);
    executeCodeButton->setBounds (216, 168, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUIComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == executeCodeButton)
    {
        //[UserButtonCode_executeCodeButton] -- add your button handler code here..
        
        interpreter.parseText (brainfuckCodeEditor->getText());
        outputEditor->setText (interpreter.getOutputText());
        interpreter.reset();
        
        //[/UserButtonCode_executeCodeButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUIComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff505050"/>
  <TEXTEDITOR name="brainfuckCodeEditor" id="59d491ad053b0a3f" memberName="brainfuckCodeEditor"
              virtualName="" explicitFocusOrder="0" pos="0 64 600 100" textcol="ffffffff"
              initialText="" multiline="1" retKeyStartsLine="1" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="inputEditor" id="ce63d681197cb556" memberName="inputEditor"
              virtualName="" explicitFocusOrder="0" pos="0 198 600 30" textcol="ffffffff"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="outputEditor" id="e6b0e684a57da253" memberName="outputEditor"
              virtualName="" explicitFocusOrder="0" pos="0 246 600 30" textcol="ffffffff"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="errorMessagesEditor" id="d9c721f19ad3d913" memberName="errorMessagesEditor"
              virtualName="" explicitFocusOrder="0" pos="0 294 600 100" textcol="ffffffff"
              initialText="" multiline="1" retKeyStartsLine="1" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="executeCodeButton" id="e8581b84cdf8cec8" memberName="executeCodeButton"
              virtualName="" explicitFocusOrder="0" pos="216 168 150 24" buttonText="Execute"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
