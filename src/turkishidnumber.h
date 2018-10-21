#ifndef TURKISHIDNUMBER_H
#define TURKISHIDNUMBER_H

#include<string>


class TurkishIdNumber
{
private:
    const static unsigned int length = 11;
    std::string value;
    bool isNumber(std::string str);
    int getDigit(std::string str, int index);
public:
    bool isValid(std::string str);
    TurkishIdNumber(std::string value);
    std::string getValue();
    void setValue(std::string value);
};

#endif // TURKISHIDNUMBER_H
