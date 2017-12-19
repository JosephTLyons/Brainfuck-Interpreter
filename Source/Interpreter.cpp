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

void Interpreter::parseText (const String &brainfuckCode)
{
    for (int i = 0; i < brainfuckCode.length(); i++)
    {
        if (i == '+')
            incrementCellValue();
        
        else if (i == '-')
            decrementCellValue();
        
        else if (i == '>')
            incrementIndex();
        
        else if (i == '<')
            decrementIndex();
        
        else if (i == ',')
            acceptInput();
        
        else if (i == '.')
            printOutput();
        
        else if (i == '[')
            openBracket();
        
        else if (i == ']')
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
