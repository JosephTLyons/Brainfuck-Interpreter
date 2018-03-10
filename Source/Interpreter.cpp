//
//  Interpreter.cpp
//  Brainfuck Interpreter - App
//
//  Created by Joseph Lyons on 12/19/17.
//

#include "Interpreter.hpp"

Interpreter::Interpreter()
{
    tapeArray.resize (TAPE_ARRAY_SIZE);
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
    brainfuckCodeIndex = 0;
}

void Interpreter::incrementCellValue()
{
    if (tapeArray[tapeArrayIndex] == 255)
        warningText += "Warning: Positive overflow occured at cell " + (String) tapeArrayIndex + ".\n";

    tapeArray.set (tapeArrayIndex, tapeArray[tapeArrayIndex] + 1);
}

void Interpreter::decrementCellValue()
{
    if (tapeArray[tapeArrayIndex] == 0)
        warningText += "Warning: Negative overflow occured at cell " + (String) tapeArrayIndex + ".\n";
    
    Logger::writeToLog((String) tapeArray[tapeArrayIndex]);

    tapeArray.set (tapeArrayIndex, tapeArray[tapeArrayIndex] - 1);
}

void Interpreter::incrementIndex()
{
    if (tapeArrayIndex == TAPE_ARRAY_SIZE - 1)
        warningText += "Error: Attemping to access cell 300000, index adjusted to remain at cell 29999.\n";

    else
        tapeArrayIndex++;
}

void Interpreter::decrementIndex()
{
    if (tapeArrayIndex == 0)
        warningText += "Error: Attemping to access cell -1, index adjusted to remain at cell 0.\n";

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

void Interpreter::loop (const String &brainfuckCode, int i)
{
    openingBracketIndex = i;
    
    int j, numberOfIncorrectEndBrackets = 0;

    // Search for correct closing bracket
    for (j = i + 1; ; j++)
    {
        if (brainfuckCode[j] == '[')
            numberOfIncorrectEndBrackets++;
        
        if (brainfuckCode[j] == ']' && numberOfIncorrectEndBrackets == 0)
            break;
        
        // if not found, report error and leave looping function
        if (j == brainfuckCode.length() - 1)
        {
            warningText += "Missing ']'.";
            return;
        }
    }

    closingBracketIndex = j;

    // Loop through the code inside brackets
    while (tapeArray[tapeArrayIndex] != 0)
        parseText (brainfuckCode.substring(openingBracketIndex + 1, closingBracketIndex));

    // Assign the closingBracketIndex so that when we return to the parsing method
    // We don't execute the code in the loop one more time
    brainfuckCodeIndex = closingBracketIndex;
}

void Interpreter::parseText (const String &brainfuckCode)
{
    for (brainfuckCodeIndex = 0; brainfuckCodeIndex < brainfuckCode.length(); brainfuckCodeIndex++)
    {
        if (brainfuckCode[brainfuckCodeIndex] == '+')
            incrementCellValue();

        else if (brainfuckCode[brainfuckCodeIndex] == '-')
            decrementCellValue();

        else if (brainfuckCode[brainfuckCodeIndex] == '>')
            incrementIndex();

        else if (brainfuckCode[brainfuckCodeIndex] == '<')
            decrementIndex();

        else if (brainfuckCode[brainfuckCodeIndex] == ',')
            acceptInput();

        else if (brainfuckCode[brainfuckCodeIndex] == '.')
            addToOutputText();

        else if (brainfuckCode[brainfuckCodeIndex] == '[')
            loop (brainfuckCode, brainfuckCodeIndex);
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
