//
//  Interpreter.cpp
//  Brainfuck Interpreter - App
//
//  Created by Joseph Lyons on 12/19/17.
//

#include "Interpreter.hpp"

Interpreter::Interpreter()
{
    tapeArray.resize (30000);
    zeroOut();
}

Interpreter::~Interpreter()
{
    
}

void Interpreter::zeroOut()
{
    tapeArray.fill (0);
    
    tapeArrayIndex = 0;
    inputTextIndex = 0;
    
    openingBracketIndex = 0;
    closingBracketIndex = 0;
}

void Interpreter::incrementCellValue()
{
    if (tapeArray[tapeArrayIndex] == 255)
        warningText += "Positive overflow occured at cell " + (String) tapeArrayIndex + "\n";
    
    tapeArray.set (tapeArrayIndex, tapeArray[tapeArrayIndex] + 1);
}

void Interpreter::decrementCellValue()
{
    if (tapeArray[tapeArrayIndex] == 0)
        warningText += "Negative overflow occured at cell " + (String) tapeArrayIndex + "\n";
    
    tapeArray.set (tapeArrayIndex, tapeArray[tapeArrayIndex] - 1);
}

void Interpreter::incrementIndex()
{
    if (tapeArrayIndex == tapeArray.size())
        warningText += "Attemping to go access cell 300000, index adjusted to stay at cell 29999\n";
    
    else
        tapeArrayIndex++;
}

void Interpreter::decrementIndex()
{
    if (tapeArrayIndex == 0)
        warningText += "Attemping to go access cell -1, index adjusted to stay at cell 0\n";
    
    else
        tapeArrayIndex--;
}

void Interpreter::acceptInput()
{
    tapeArray.set (tapeArrayIndex, inputText[inputTextIndex++]);
}

void Interpreter::addToOutputText()
{
    outputText += (char) tapeArray[tapeArrayIndex];
}

void Interpreter::openBracket (const String &brainfuckCode, int i)
{
    openingBracketIndex = i;
    
    // Search for closing bracket
    for (; brainfuckCode[i] != ']'; i++)
    {
    }
    
    closingBracketIndex = i;
    
    while (tapeArray[tapeArrayIndex] != 0)
    {
        parseText (brainfuckCode.substring(openingBracketIndex + 1, closingBracketIndex - 1));
    }
}

void Interpreter::closedBracket()
{
    if (tapeArray[tapeArrayIndex - 1] != 0)
    {
        // Go back to index of
    }
}

void Interpreter::parseText (const String &brainfuckCode)
{
    for (int i = 0; i < brainfuckCode.length(); i++)
    {
        if (brainfuckCode[i] == '+')
            incrementCellValue();
        
        else if (brainfuckCode[i] == '-')
            decrementCellValue();
        
        else if (brainfuckCode[i] == '>')
            incrementIndex();
        
        else if (brainfuckCode[i] == '<')
            decrementIndex();
        
        else if (brainfuckCode[i] == ',')
            acceptInput();
        
        else if (brainfuckCode[i] == '.')
            addToOutputText();
        
        else if (brainfuckCode[i] == '[')
            openBracket (brainfuckCode, i);
        
        else if (brainfuckCode[i] == ']')
            closedBracket();
    }
}

void Interpreter::setInputText (const String &input)
{
    inputText = input;
}

String Interpreter::getOutputText()
{
    return outputText;
}

String Interpreter::getWarningText()
{
    return warningText;
}

void Interpreter::reset()
{
    zeroOut();
    
    outputText.clear();
    warningText.clear();
    inputText.clear();
}
