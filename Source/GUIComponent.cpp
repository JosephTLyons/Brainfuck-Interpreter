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
    brainfuckCodeEditor->setColour (TextEditor::highlightColourId, Colour (0xbfffffff));
    brainfuckCodeEditor->setText (String());

    addAndMakeVisible (inputEditor = new TextEditor ("inputEditor"));
    inputEditor->setMultiLine (false);
    inputEditor->setReturnKeyStartsNewLine (false);
    inputEditor->setReadOnly (false);
    inputEditor->setScrollbarsShown (true);
    inputEditor->setCaretVisible (true);
    inputEditor->setPopupMenuEnabled (true);
    inputEditor->setColour (TextEditor::textColourId, Colours::white);
    inputEditor->setColour (TextEditor::highlightColourId, Colour (0xbfffffff));
    inputEditor->setText (String());

    addAndMakeVisible (outputEditor = new TextEditor ("outputEditor"));
    outputEditor->setMultiLine (false);
    outputEditor->setReturnKeyStartsNewLine (false);
    outputEditor->setReadOnly (true);
    outputEditor->setScrollbarsShown (true);
    outputEditor->setCaretVisible (false);
    outputEditor->setPopupMenuEnabled (true);
    outputEditor->setColour (TextEditor::textColourId, Colours::white);
    outputEditor->setColour (TextEditor::highlightColourId, Colour (0xbfffffff));
    outputEditor->setText (String());

    addAndMakeVisible (errorMessagesEditor = new TextEditor ("errorMessagesEditor"));
    errorMessagesEditor->setMultiLine (true);
    errorMessagesEditor->setReturnKeyStartsNewLine (true);
    errorMessagesEditor->setReadOnly (true);
    errorMessagesEditor->setScrollbarsShown (true);
    errorMessagesEditor->setCaretVisible (false);
    errorMessagesEditor->setPopupMenuEnabled (true);
    errorMessagesEditor->setColour (TextEditor::textColourId, Colours::white);
    errorMessagesEditor->setColour (TextEditor::highlightColourId, Colour (0xbfffffff));
    errorMessagesEditor->setText (String());

    addAndMakeVisible (executeCodeButton = new TextButton ("executeCodeButton"));
    executeCodeButton->setButtonText (TRANS("Execute"));
    executeCodeButton->addListener (this);

    addAndMakeVisible (brainfuckCodeLabel = new Label ("brainfuckCodeLabel",
                                                       TRANS("Brainfuck Code:")));
    brainfuckCodeLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    brainfuckCodeLabel->setJustificationType (Justification::centredLeft);
    brainfuckCodeLabel->setEditable (false, false, false);
    brainfuckCodeLabel->setColour (TextEditor::textColourId, Colours::black);
    brainfuckCodeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (inputLabel = new Label ("inputLabel",
                                               TRANS("Input:")));
    inputLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    inputLabel->setJustificationType (Justification::centredLeft);
    inputLabel->setEditable (false, false, false);
    inputLabel->setColour (TextEditor::textColourId, Colours::black);
    inputLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputLabel = new Label ("outputLabel",
                                                TRANS("Output:")));
    outputLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputLabel->setJustificationType (Justification::centredLeft);
    outputLabel->setEditable (false, false, false);
    outputLabel->setColour (TextEditor::textColourId, Colours::black);
    outputLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (errorsAndWarningsLabel = new Label ("errorsAndWarningsLabel",
                                                           TRANS("Errors and Warnings:")));
    errorsAndWarningsLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    errorsAndWarningsLabel->setJustificationType (Justification::centredLeft);
    errorsAndWarningsLabel->setEditable (false, false, false);
    errorsAndWarningsLabel->setColour (TextEditor::textColourId, Colours::black);
    errorsAndWarningsLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 470);


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
    brainfuckCodeLabel = nullptr;
    inputLabel = nullptr;
    outputLabel = nullptr;
    errorsAndWarningsLabel = nullptr;


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

    brainfuckCodeEditor->setBounds (0, 100, 600, 100);
    inputEditor->setBounds (0, 35, 600, 30);
    outputEditor->setBounds (0, 235, 600, 100);
    errorMessagesEditor->setBounds (0, 370, 600, 100);
    executeCodeButton->setBounds (225, 205, 150, 25);
    brainfuckCodeLabel->setBounds (0, 70, 150, 25);
    inputLabel->setBounds (0, 5, 150, 25);
    outputLabel->setBounds (0, 205, 150, 25);
    errorsAndWarningsLabel->setBounds (0, 340, 150, 25);
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

        outputEditor->clear();
        errorMessagesEditor->clear();


        interpreter.setInputText (inputEditor->getText());
        interpreter.parseText (brainfuckCodeEditor->getText());
        outputEditor->setText (interpreter.getOutputText());
        errorMessagesEditor->setText (interpreter.getWarningText());
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
                 fixedSize="1" initialWidth="600" initialHeight="470">
  <BACKGROUND backgroundColour="ff505050"/>
  <TEXTEDITOR name="brainfuckCodeEditor" id="59d491ad053b0a3f" memberName="brainfuckCodeEditor"
              virtualName="" explicitFocusOrder="0" pos="0 100 600 100" textcol="ffffffff"
              hilitecol="bfffffff" initialText="" multiline="1" retKeyStartsLine="1"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="inputEditor" id="ce63d681197cb556" memberName="inputEditor"
              virtualName="" explicitFocusOrder="0" pos="0 35 600 30" textcol="ffffffff"
              hilitecol="bfffffff" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="outputEditor" id="e6b0e684a57da253" memberName="outputEditor"
              virtualName="" explicitFocusOrder="0" pos="0 235 600 100" textcol="ffffffff"
              hilitecol="bfffffff" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="errorMessagesEditor" id="d9c721f19ad3d913" memberName="errorMessagesEditor"
              virtualName="" explicitFocusOrder="0" pos="0 370 600 100" textcol="ffffffff"
              hilitecol="bfffffff" initialText="" multiline="1" retKeyStartsLine="1"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTBUTTON name="executeCodeButton" id="e8581b84cdf8cec8" memberName="executeCodeButton"
              virtualName="" explicitFocusOrder="0" pos="225 205 150 25" buttonText="Execute"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="brainfuckCodeLabel" id="5421b93948ba369c" memberName="brainfuckCodeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 70 150 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Brainfuck Code:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="inputLabel" id="e04ec47e05f2378c" memberName="inputLabel"
         virtualName="" explicitFocusOrder="0" pos="0 5 150 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Input:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="outputLabel" id="f84f3698f64703b8" memberName="outputLabel"
         virtualName="" explicitFocusOrder="0" pos="0 205 150 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Output:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="errorsAndWarningsLabel" id="af33826739efbb85" memberName="errorsAndWarningsLabel"
         virtualName="" explicitFocusOrder="0" pos="0 340 150 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Errors and Warnings:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
