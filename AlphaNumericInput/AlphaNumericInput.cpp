#include <iostream>
#include <string>

class TextInput
{
public:
    std::string value;

    virtual void add(char c) {
        value += c;
    }

    std::string getValue() {
        return value;
    }
};

class NumericInput : public TextInput {
    
public:
    virtual void add(char c) {
        if(isdigit(c))
            TextInput::add(c);
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif