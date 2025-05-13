#include <iostream>
#include <vector>
#include <map>
#include "VectorParse.h"
#include "Parse.h"
#include "Project8.h"

using namespace std;
map<string, int> symbolTable;
bool isNumOpVar(const char* peek_next_token){
    int check=3;
    for(int i = 0; peek_next_token[i]; i++){
        if(peek_next_token[i] < '0' || peek_next_token[i] > '9') {
            check--;
            break;
        }
    }
    if(!symbolTable.count(peek_next_token)) {
        check--;
    }
    string op = "+";
    string op1 = "-";
    string op2 = "*";
    string op3 = "/";
    string op4 = "%";
    string op5 = "&&";
    string op6 = "||";
    string op7 = "<";
    string op8 = ">";
    string op9 = "==";
    string op10 = "!=";
    string op11 = "<=";
    string op12 = ">=";
    string op13 = "!";
    string op14 = "~";
    if (peek_next_token != op && peek_next_token != op1 && peek_next_token != op2 && peek_next_token != op3 && peek_next_token != op4 && peek_next_token != op5 && peek_next_token != op6 && peek_next_token != op7
        && peek_next_token != op8 && peek_next_token != op9 && peek_next_token != op10 && peek_next_token != op11 && peek_next_token != op12 && peek_next_token != op13 && peek_next_token != op14){
        check--;
    }
    if (check>0){
        return true;
    }else{
        return false;
    }
}

bool isNum(const char* tokenNum){
    for(int i = 0; tokenNum[i]; i++){
        if(tokenNum[i] < '0' || tokenNum[i] > '9')
            return false;
        return true;
    }
}

bool isOperator(const char* tokenComp){
    string sign = "+";
    string sign1 = "-";
    string sign2 = "*";
    string sign3 = "/";
    string sign4 = "%";
    string sign5 = "&&";
    string sign6 = "||";
    string sign7 = "<";
    string sign8 = ">";
    string sign9 = "==";
    string sign10 = "!=";
    string sign11 = "<=";
    string sign12 = ">=";
    string sign13 = "!";
    string sign14 = "~";
    if (tokenComp != sign && tokenComp != sign1 && tokenComp != sign2 && tokenComp != sign3 && tokenComp != sign4 && tokenComp != sign5 && tokenComp != sign6 && tokenComp != sign7
        && tokenComp != sign8 && tokenComp != sign9 && tokenComp != sign10 && tokenComp != sign11 && tokenComp != sign12 && tokenComp != sign13 && tokenComp != sign14){
        return false;
    }
    return true;
}

bool isValidToken(const char* tokenCheck){  // essentially combines previous 2 for ease
    if(isOperator(tokenCheck))
        return true;
    if(symbolTable.count(tokenCheck))
        return true;
    if(isNum(tokenCheck))
        return true;
    return false;
}
void text(){
    read_next_token();
    cout << next_token();
}
void output(){
    string test = next_token();
    string test2 = peek_next_token();
    string outputValueString;
    vector <string> outputVector;
    while((next_token_type != END) && isNumOpVar(peek_next_token())) {
        read_next_token();
        if(next_token_type == NAME) {
            outputVector.push_back(to_string(symbolTable[next_token()]));
//                    read_next_token();
//                    setName = next_token();
        }
        else {
            outputValueString = next_token();
            outputVector.push_back(outputValueString);
//                    read_next_token();
//                    setName = next_token();

        }
    }
    int outputVal = parse(outputVector);
    cout << outputVal;
}
void var(){
    string test1 = next_token();
    peekFalse();
    read_next_token();
    string varName = next_token();
//            read_next_token();
    string varValueString;
    vector<string> varVector;
    string test = peek_next_token();
    while((next_token_type != END) && isNumOpVar(peek_next_token())) {
        read_next_token();
        if(next_token_type == NAME) {
            varVector.push_back(to_string(symbolTable[next_token()]));
//                    read_next_token();
//                    setName = next_token();
        }
        else {
            varValueString = next_token();
            varVector.push_back(varValueString);
//                    read_next_token();
//                    setName = next_token();

        }
    }
    int varVal = parse(varVector);
    if(symbolTable.count(varName)){
        cout << "variable " << varName << " incorrectly re-initialized" << endl;
    }
    symbolTable[varName] = varVal;

}

void set(){
    peekFalse();
    read_next_token();
    string setName = next_token();
//            read_next_token();
    string setValueString;
    vector<string> setVector;
    while((next_token_type != END) && isNumOpVar(peek_next_token())) {
        read_next_token();
        if(next_token_type == NAME) {
            setVector.push_back(to_string(symbolTable[next_token()]));
//                    read_next_token();
//                    setName = next_token();
        }
        else {
            setValueString = next_token();
            setVector.push_back(setValueString);
//                    read_next_token();
//                    setName = next_token();

        }
    }
    int setVal = parse(setVector);
    if(!symbolTable.count(setName)){
        cout << "variable " << setName << " not declared" << endl;
    }
    symbolTable[setName] = setVal;

}
void run() {
    read_next_token();
    string strtext = "text";
    string stroutput = "output";
    string strset = "set";
    string strvar = "var";
    string comment = "//";
    while (next_token_type != END) {
        //string type = convertToStr(next_token());
        if(next_token() == comment) {
            skip_line();
        }else if (next_token() == strtext) {
            text();
        } else if (next_token() == stroutput) {
            output();
        } else if (next_token() == strvar) {
            var();
        } else if (string(next_token()) == "set") {
            set();
        }
        read_next_token();
    }

}
