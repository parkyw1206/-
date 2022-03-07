#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;
bool isPrime(long long n) { 
    if(n < 2) return false;
        
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0, remainder;
    string checkNumStr;
    stack<int> numStack;
     while (n >= k) {
         remainder = n % k;     
         n = n / k;
         numStack.push(remainder);
    }
    if(n > 0) numStack.push(n);
    while(!numStack.empty() && numStack.top() != 0){
        checkNumStr += to_string(numStack.top());
        numStack.pop();
    }
    if(checkNumStr != ""  && isPrime(stoll(checkNumStr)))  answer++;
    checkNumStr = "";
    
    while(!numStack.empty()){
        if(numStack.top() == 0){
            if(checkNumStr != "" && isPrime(stoll(checkNumStr))) answer++;
            checkNumStr = "";
        }
        else{
            checkNumStr += to_string(numStack.top());
        }
        numStack.pop();
    }
    if(checkNumStr !=  "" && isPrime(stoll(checkNumStr))) answer++;

    return answer;
}