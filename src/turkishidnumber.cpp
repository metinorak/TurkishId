#include "turkishidnumber.h"
#include <string>
#include <stdlib.h>
#include <stdexcept>


TurkishIdNumber::TurkishIdNumber(std::string number)
{


    if(!this->isValid(number)){
        throw std::invalid_argument("Invalid Turkish ID Number");
    }

    this->value = number;

}


bool TurkishIdNumber::isValid(std::string str){
    if(str.length() != length){
        return false;
    }
    if(str[0] == '0'){
        return false;
    }

    if(!isNumber(str)){
        return false;
    }

    int first_sum = 0;
    int second_sum = 0;


    for(int i = 0; i < 4; i++){
        first_sum += getDigit(str, i * 2);
        second_sum += getDigit(str, i * 2 + 1);
    }
    first_sum += getDigit(str, 8);

    int n = 7 * first_sum - second_sum;
    
    if(n < 0){
        n += 10;
    }

    if(n % 10 != getDigit(value, 9)){
        return false;
    }

    int first_ten_sum = first_sum + second_sum + getDigit(value, 9);

    return first_ten_sum % 10 == getDigit(value, 10);
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


void TurkishIdNumber::changeValue(std::string value){
    if(!this->isValid(value)){
        throw std::invalid_argument("Invalid Turkish ID Number");
    }
    else{
        this->value = value;
    }
}

