//
//  Interpreter.hpp
//  Brainfuck Interpreter - App
//
//  Created by Joseph Lyons on 12/19/17.
//

#ifndef Interpreter_hpp
#define Interpreter_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class Interpreter
{
private:
    Array<char> tapeArray;
    int index;
    
public:
    Interpreter();
    
    void parseText (const String &brainfuckCode);
    
    void incrementCellValue();
    void decrementCellValue();
    void incrementIndex();
    void decrementIndex();
    void acceptInput();
    void printOutput();
    void openBracket();
    void closedBracket();
    
};

#endif /* Interpreter_hpp */
