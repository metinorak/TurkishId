#ifndef TURKISHIDNUMBER_H
#define TURKISHIDNUMBER_H

#include<string>


class TurkishIdNumber
{
private:
    const static unsigned int length = 11;
    std::string value;
    static bool isNumber(std::string str);
    static int getDigit(std::string str, int index);
public:
    TurkishIdNumber(std::string value);
    static bool isValid(std::string str);
    std::string getValue();
    void setValue(std::string value);
};

#endif // TURKISHIDNUMBER_H
