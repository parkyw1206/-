#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

int N;
vector<int> nums;
string str;
int temp;
stack<double>strings;
double result = 0.00;

void input(){
    cin >> N;
    cin.ignore();
    getline(cin,str);

    for(int i = 0 ; i < N ;i++){
        cin >> temp;
        nums.push_back(temp);
    }
}
void calc(char oper){
    
    double second = strings.top();
    strings.pop();
    double first = strings.top();
    strings.pop();
    
    switch(oper){
        case '+':
            strings.push(first + second);
            break;
        case '-':
            strings.push(first - second);
            break;
        case '*':
            strings.push(first * second);
            break;
        case '/':
            strings.push(first / second);
            break;
    }
}
int main()
{
    input();
    
    for(int i = 0 ; i < str.size() ; i++){
        if(!isalpha(str[i])){
            calc(str[i]);
        }
        else{
            strings.push(nums[int(str[i]) - 65]);
        }
    }
    

    cout << fixed;
    cout << setprecision(2);
    cout << strings.top();
    return 0;
}
