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
    const int TAPE_ARRAY_SIZE = 30000;
    int tapeArrayIndex;

    String outputText, warningText, inputText;
    int inputTextIndex;

    int openingBracketIndex, closingBracketIndex;
    int brainfuckCodeIndex;

    // Methods for operators
    void incrementCellValue();
    void decrementCellValue();
    void incrementIndex();
    void decrementIndex();
    void acceptInput();
    void addToOutputText();
    void loop (const String &brainfuckCode, const int &openBracketIndex);

public:
    Interpreter();
    ~Interpreter();

    void zeroOut();

    void parseText (const String &brainfuckCode);
    void setInputText (const String &input);
    String getOutputText();
    String getWarningText();
    void reset();
};

#endif /* Interpreter_hpp */
