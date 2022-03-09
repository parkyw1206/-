#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string doStepOne(string new_id){
    string returnStr = "";
    for(int i = 0 ; i < new_id.size() ; i++){
        if(isupper(new_id[i])){
            returnStr += char(new_id[i]+32);
        }
        else returnStr += new_id[i];
    }
    return returnStr;
}
string doStepTwo(string new_id){
    string returnStr = "";
    for(int i = 0 ; i < new_id.size() ; i++){
        if(isdigit(new_id[i]) || isalpha(new_id[i]) 
           || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' ){
            returnStr += new_id[i];
        }
    }
    return returnStr;
}
string doStepThree(string new_id){
    string returnStr = "";
    for(int i = 0 ; i < new_id.size() ; i++){
        if(new_id[i] == '.'){
            returnStr += '.';
            for(int j = i+1 ; j < new_id.size() ; j++){
                if(new_id[j] == '.'){
                    i++;
                }
                else break;
            }
        } 
        else{
            returnStr += new_id[i];
        }
    }
    return returnStr;
}
string doStepFour(string new_id){
    string returnStr = "";
    // check First
    for(int i = 0 ; i < new_id.size();i++){
        if(new_id[i] != '.') {
            for(int j = i; j < new_id.size() ;j++){
                returnStr += new_id[j];                
            }
        i = new_id.size();
        }
    }
    // check Last
    for(int i =returnStr.size()-1; i > 0 ; i--){
        if(returnStr[i] == '.') {
            returnStr.pop_back();                
        }else{
        i = 0;
        }
    }
    
    return returnStr;
}
string doStepFive (string new_id){
    if(new_id == "") return "a";
    else return new_id;
}
string doStepSix (string new_id){
    string returnStr = "";
    if(new_id.size() >= 16) returnStr = new_id.substr(0,15);
    else returnStr = new_id;
    returnStr = doStepFour(returnStr);
    return returnStr;
}
string doStepSeven(string new_id){
    if(new_id.size() < 3){
        string returnStr = new_id;
        char lastChar = new_id[new_id.size()-1];
        for(int i = new_id.size()-1 ; i < 2; i++){
            returnStr += lastChar;
        }
        return returnStr;
    }
    else{
        return new_id;
    }
}
string solution(string new_id) {
    string answer = "";
    
    new_id = doStepOne(new_id);
    new_id = doStepTwo(new_id);
    new_id = doStepThree(new_id);
    new_id = doStepFour(new_id);
    new_id = doStepFive(new_id);
    new_id = doStepSix(new_id);
    new_id = doStepSeven(new_id);
    
    answer= new_id;
    return answer;
}