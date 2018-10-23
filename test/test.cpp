#include <iostream>
#include "turkishidnumber.h"

using namespace std;

int main()
{
    TurkishIdNumber *tid = NULL;
    try{
        tid = new TurkishIdNumber("10000000146");

    }
    catch(invalid_argument& ia){
        cerr<< "Invalid argument: " << ia.what()<<endl;
    }


    try{
        tid->changeValue("10000000148");

    }
    catch(invalid_argument& ia){
        cerr<< "Invalid argument: " << ia.what()<<endl;
    }


    cout<<tid->getValue();



}
