#include "turkishidnumber.h"
#include <string>
#include <stdlib.h>
#include <stdexcept>

TurkishIdNumber::TurkishIdNumber(std::string value)
{
    this->setValue(value);
}

bool TurkishIdNumber::isValid(std::string value){
    if(value.length() != length){
        return false;
    }
    if(value[0] == '0'){
        return false;
    }

    if(!isNumeric(value)){
        return false;
    }

    int firstSum = 0;
    int secondSum = 0;

    for(int i = 0; i < 4; i++){
        firstSum += getDigit(value, i * 2);
        secondSum += getDigit(value, i * 2 + 1);
    }
    firstSum += getDigit(value, 8);

    int checkSum = (7 * firstSum - secondSum) % 10;
    
    if(checkSum < 0){
        checkSum += 10;
    }

    if(checkSum != getDigit(value, 9)){
        return false;
    }

    int firstTenSum = firstSum + secondSum + getDigit(value, 9);

    return firstTenSum % 10 == getDigit(value, 10);
}

int TurkishIdNumber::getDigit(std::string value, int index){
    return value[index] - '0';
}

bool TurkishIdNumber::isNumeric(std::string value){
    for(unsigned int i = 0; i < value.length(); i++){
        if(!std::isdigit(value[i])){
            return false;
        }
    }
    return true;
}

std::string TurkishIdNumber::toString(){
    return this->value;
}

void TurkishIdNumber::setValue(std::string value){
    if(!this->isValid(value)){
        throw std::invalid_argument("Invalid Turkish ID Number");
    }
    else{
        this->value = value;
    }
}