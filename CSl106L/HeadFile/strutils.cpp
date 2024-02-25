#include"strutils.h"
#include<cctype>
#include<sstream>

string ConverToUpperCase(string input){
    for(int i = 0;i<input.size();++i){
        input[i]=toupper(input[i]);
    }
    return input;
}

string ConverLowerCase(string input){
    for(int i = 0;i<input.size();++i){
        input[i] = tolower(input[i]);
    }
    return input;
}

string IntegerToString(int value){
    stringstream converter;
    converter<<value;
    return converter.str();
}

string DoubleTString(double value){
    stringstream converter;
    converter<<value;
    return converter.str();
}