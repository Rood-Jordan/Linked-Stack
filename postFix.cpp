//Jordan Rood
//Homework 2 - Linked Stack 
//09-20-2021

#include <iostream>
#include <string>
#include "linkedStack.h"

using namespace std;

void numOrOperator(string& , int , linkedStack<char>& , string&);
void pushOperator(linkedStack<char>& , char , string&);
int evaluatePostFix(linkedStack<int>& , string& , int );
void copyCtor();

int main(){

    try{
        string infixForm, postFixString;
        int stringLength, postStringLength;

        linkedStack<char> operatorStack;
        linkedStack<int> numberStack;

        cout << "Enter an infix form expression to be evaluated (Only single digits, no spaces, and no parenthesis):" << endl;
        cin >> infixForm;

        stringLength = infixForm.length();
        numOrOperator(infixForm, stringLength, operatorStack, postFixString);
    
        cout << "Postfix Form: " << postFixString << endl;

        postStringLength = postFixString.length();

        cout << "Result: " << evaluatePostFix(numberStack, postFixString, postStringLength) << endl;

    }
    catch(const char* e){
        cout << e << endl;
    }
    return 0;
}

void numOrOperator(string& infixString, int stringLength, linkedStack<char>& operatorStack, string& postFixString){

    for(int i = 0; i < stringLength; i++){
        if(infixString[i] == '*' ||  infixString[i]== '/' ||  infixString[i]== '+' ||  infixString[i]== '-' || infixString[i]=='%'){

            char operation = infixString[i];
            pushOperator(operatorStack, operation, postFixString);
        }
        else{
            postFixString += infixString[i];
        }
    }
    
    while(!operatorStack.isEmpty()){
        char pushOperator = operatorStack.peek();
        postFixString += pushOperator;
        operatorStack.pop();
    }
}

void pushOperator(linkedStack<char>& operatorStack, char currOperator, string& postFixString){
    //determine precedence of operators and push to postfix * / + -

    if(operatorStack.isEmpty()){
        operatorStack.push(currOperator);
    }
    else if(currOperator=='+' || currOperator=='-' && operatorStack.peek()=='*' || operatorStack.peek()=='/' || operatorStack.peek()=='%'){
        char higherOperator = operatorStack.peek();
        operatorStack.pop();
        postFixString += higherOperator;
        operatorStack.push(currOperator);

    }
    else{
        operatorStack.push(currOperator);
    }
}

int evaluatePostFix(linkedStack<int>& numStack, string& postFixString, int postFixStringLength){
    int num1, num2, result;

    for(int i = 0; i < postFixStringLength; i++){
        if(postFixString[i] == '*' ||  postFixString[i]== '/' ||  postFixString[i]== '+' ||  postFixString[i]== '-' || postFixString[i]=='%'){
            // pop two operands from the stack
            num2 = numStack.peek();
            numStack.pop();
            num1 = numStack.peek();
            numStack.pop();

            //evaluate the expression
            switch(postFixString[i]){
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    //cout << result << endl << endl;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                case '%':
                    result = num1 % num2;
                    break;
            }
            //push resulting value onto the stack
            numStack.push(result);
        }
        else{
            //else if number, push onto number stack
            numStack.push((int)postFixString[i] - 48);
        }
    }
    return numStack.peek();
    numStack.pop();
}

/*void copyCtor(){
    linkedStack<int> newStack;
    newStack.push(4);
    newStack.push(3);
    newStack.push(2);
    newStack.push(1);

    linkedStack<int> copyStack(newStack);
    while(!newStack.isEmpty()){
        cout << newStack.peek() << endl;
        newStack.pop();
    }
}*/
//copy constructor test function