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
        if (tapeArray[i] == '+')
            incrementCellValue();
        
        else if (tapeArray[i] == '-')
            decrementCellValue();
        
        else if (tapeArray[i] == '>')
            incrementIndex();
        
        else if (tapeArray[i] == '<')
            decrementIndex();
        
        else if (tapeArray[i] == ',')
            acceptInput();
        
        else if (tapeArray[i] == '.')
            printOutput();
        
        else if (tapeArray[i] == '[')
            openBracket();
        
        else if (tapeArray[i] == ']')
            closedBracket();
    }
}

void Interpreter::incrementCellValue()
{
    
}

void Interpreter::decrementCellValue()
{
    
}

void Interpreter::incrementIndex()
{
    
}

void Interpreter::decrementIndex()
{
    
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
