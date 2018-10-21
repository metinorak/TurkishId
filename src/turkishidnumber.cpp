#include "turkishidnumber.h"
#include <string>
#include <stdlib.h>
#include <stdexcept>


TurkishIdNumber::TurkishIdNumber(std::string number)
{
    this->value = number;

    if(!this->isValid(number)){
        throw std::invalid_argument("Invalid Turkish ID Number");
    }

}


bool TurkishIdNumber::isValid(std::string str){
    if(str.length() != this->length){
        return false;
    }
    if(str[0] == '0'){
        return false;
    }

    if(!this->isNumber(str)){
        return false;
    }

    int first_sum = 0;
    int second_sum = 0;


    for(int i = 0; i < 4; i++){
        first_sum += this->getDigit(str, i * 2);
        second_sum += this->getDigit(str, i * 2 + 1);
    }
    first_sum += this->getDigit(str, 8);

    if((7 * first_sum - second_sum) % 10 != this->getDigit(str, 9)){
        return false;
    }

    int first_ten_sum = first_sum + second_sum + this->getDigit(str, 9);

    if(first_ten_sum % 10 != this->getDigit(str, 10)){
        return false;
    }

    return true;
}



int TurkishIdNumber::getDigit(std::string str, int index){
    return str[index] - '0';
}


bool TurkishIdNumber::isNumber(std::string str){
    for(unsigned int i = 0; i < str.length(); i++){
        if(!std::isdigit(str[i])){
            return false;
        }
    }
    return true;
}

std::string TurkishIdNumber::getValue(){
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

