/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Tyler Goldsmith
 */

#include "std_lib_facilities.h"

string nums[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string operation = "NONE";

//Checks if a given string is an integer by checking that each section is exclusively a number, or if
//the word spells a number from the array of strings called nums
int getInteger(string inStr){
    //Checks if each character in the string is a number
    for (int i = 0; i < inStr.length(); i++){
        if (isdigit(inStr[i]) == true)
            return stoi(inStr);
    }
        //Checks if the in string is one of the numbers from array of nums
        for(int i=0; i<10; i++){
            if(nums[i]==inStr)
                return i;
        }
        return -1;
}

//Checks if a given string is an integer by checking that each section is exclusively a number
bool isOperator(string str){
    for (int i = 0; i < str.length(); i++)
        if (str=="+"||str=="-"||str=="/"||str=="*")
            return true;
        return false;
}

//returns result of operation and updates global operative variable
int getOperator(string str, int num1, int num2){
    String ret;
    if(str=="+"){
        operation= "sum";
        return num1+num2;
    }
    if(str=="-"){
        operation= "difference";
        return num1-num2;
    }
    if(str=="/"){
        operation= "quotient";
        return num1/num2;
    }
    if(str=="*"){
        operation= "product";
        return num1*num2;
    }
}


int main(){
    string op;
    string num1;
    string num2;
    
    cout <<"Please enter an operator (+,-,/,or *): ";
    cin >> op ;
    while (!isOperator(op)){
        cout <<"Invalid input try again: ";
        cin >> op;
    }

    cout <<"Please enter the first Integer: ";
    cin >> num1 ;
    while (getInteger(num1)==-1){
        cout <<"Invalid input try again: ";
        cin >> num1;
    }

    cout <<"Please enter the second Integer: ";
    cin >> num2 ;
    while (getInteger(num2)==-1){
        cout <<"Invalid input try again: ";
        cin >> num2;
    }

    int result= getOperator(op,getInteger(num1),getInteger(num2));
    cout <<"The "<<operation <<" of "<<getInteger(num1) <<" and " <<getInteger(num2) <<" is "<< result;
}
