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
    Array<unsigned char> tapeArray;
    int index;
    
    String outputText;
    
    // Methods for operators
    void incrementCellValue();
    void decrementCellValue();
    void incrementIndex();
    void decrementIndex();
    void acceptInput();
    void addToInterpretedText();
    void openBracket();
    void closedBracket();
    
    void zeroOutTapeArray();
    void clearOutputText();
    
public:
    Interpreter();
    ~Interpreter();
    
    void parseText (const String &brainfuckCode);
    String getOutputText();
    void reset();
};

#endif /* Interpreter_hpp */
