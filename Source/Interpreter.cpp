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
    tapeArray.fill (0);
    
    index = 0;
}

Interpreter::~Interpreter()
{
    tapeArray.clear();
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
            printOutput();
        
        else if (brainfuckCode[i] == '[')
            openBracket();
        
        else if (brainfuckCode[i] == ']')
            closedBracket();
    }
}

void Interpreter::zeroOutTapeArray()
{
    tapeArray.fill (0);
}

void Interpreter::incrementCellValue()
{
    tapeArray.set(index, tapeArray[index] + 1);
}

void Interpreter::decrementCellValue()
{
    tapeArray.set(index, tapeArray[index] - 1);
}

void Interpreter::incrementIndex()
{
    index++;
}

void Interpreter::decrementIndex()
{
    index--;
}

void Interpreter::acceptInput()
{
    
}

void Interpreter::printOutput()
{
    
}

void Interpreter::openBracket()
{
    
}

void Interpreter::closedBracket()
{
    
}
