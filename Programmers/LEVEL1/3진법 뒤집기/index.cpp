#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long convertTenToThree(long long n){
    string result = "";
    long long remainder;
    
    while (n > 0) {
        remainder = n % 3;     
        n = n / 3;
        result+=to_string(remainder);
    }
    return stoll(result);
}
long long convertThreeToTen(long long n){
    
    string strN = to_string(n);
    long long result = 0, mul = 1;

    for(long long i = strN.size()-1; i >= 0; i--){
        result += (strN[i]-48)*mul;
        mul *= 3;
    }
    
    return result;
}
int solution(int n) {
    long long answer = 0;
    
    answer = convertTenToThree(n);
    answer = convertThreeToTen(answer);
    return answer;
}