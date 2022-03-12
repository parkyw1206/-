#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long binaryToDecimal (string binary){
    long long pointIndex = 0, returnAnswer = 0;
    for(int i = binary.size()-1 ; i >= 0 ; i--){
        returnAnswer += (int)(binary[i]-48)*pow(2,pointIndex);
        pointIndex++;
    }
    return returnAnswer;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long number,remainder, changeIndex = 0;
    string binary = "", newBinary = "";
    for(int i = 0 ; i < numbers.size() ; i++){
        binary= "";
        newBinary = "";
        changeIndex = 0;
        number = numbers[i];
        
        while (number != 0) {
            remainder = number % 2;
            binary+= to_string(remainder);
            number = number / 2;
        }
        
        for(int j = 0 ; j < binary.size() ; j++){
            if(binary[j] == '0'){
                j = binary.size();
            }else{
                changeIndex++;
            }
        }
        if(changeIndex == binary.size()){
            binary += '0';
        }
        for(int i = binary.size()-1; i >= 0; i--){
            if(i == changeIndex || i == changeIndex-1){
                if(binary[i] == '0'){
                    newBinary += '1';  
                }else{
                    newBinary += '0';
                }

            }
            else{
                newBinary += binary[i];
            }
        }
        number = binaryToDecimal(newBinary);
        answer.push_back(number);
    }
    return answer;
}