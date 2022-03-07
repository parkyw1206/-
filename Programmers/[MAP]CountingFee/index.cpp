#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int timeDiff(string A, string B){
    int returnDiff;
    int returnHour, returnMin;    
    int hourA = stoi(A.substr(0,2));
    int hourB = stoi(B.substr(0,2));
    int minA = stoi(A.substr(3,2));
    int minB = stoi(B.substr(3,2));
    
    if(minA < minB){
        hourA--;
        returnMin = minA + 60 - minB;
    }
    else{
        returnMin = minA - minB;
    }
    
    returnHour = hourA - hourB;
    
    returnDiff = returnMin + returnHour * 60;
    return returnDiff;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> feeChecker;
    map<string, int> feeAdder;
    
    for(int i = 0 ; i < records.size() ; i++){
        string time = records[i].substr(0,5);
        string carNumber = records[i].substr(6,4);
        
        if(feeChecker[carNumber] != ""){
            feeAdder[carNumber] += timeDiff(time,feeChecker[carNumber]);
            feeChecker[carNumber] = "";            
        }
        else{
            feeChecker[carNumber] = time;            
        }
    }
    for(auto itr=feeChecker.begin(); itr!=feeChecker.end(); ++itr) {
        if(itr->second != ""){
            feeAdder[itr->first] += timeDiff("23:59",itr->second);
            feeChecker[itr->first] = "";            
        }
    }
    int fee;
    for(auto itr=feeAdder.begin(); itr!=feeAdder.end(); ++itr) {
        if(fees[0] > itr->second){
            fee = fees[1];
        }
        else{
            double calc = (itr->second - fees[0])/double(fees[2]);
            fee = fees[1] + ceil(calc) * fees[3];
        }
        answer.push_back(fee);

    }    
    return answer;
}