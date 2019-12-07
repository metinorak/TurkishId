# TurkishIdNumber Class

This is a class that contains a string for Turkish id number. It gets the value if it is valid, otherwise throws an exception.
Generating an object using this class, you can keep the Turkish id numbers as objects and validate its value at the same time.

## Usage
* You must add `turkishidnumber.h` header file

## Examples
```
    TurkishIdNumber *tid = NULL;
    try{
        tid = new TurkishIdNumber("10000000146");

    }
    catch(invalid_argument& ia){
        cerr<< "Invalid argument: " << ia.what()<<endl;
    }

```

* You can also change the value later:

```
    try{
        tid->setValue("10000000148");

    }
    catch(invalid_argument& ia){
        cerr<< "Invalid argument: " << ia.what()<<endl;
    }
```

* And get the value using `toString method.`

* You don't have to create an object. If you just want to validate the value, use static isValid method. 

```
if(TurkishIdNumber::isValid("10000000146"){
    cout<<"The value is valid."<<endl;
}
```
