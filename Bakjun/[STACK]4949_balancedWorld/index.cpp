#include <iostream>
#include <stack>

using namespace std;

stack<char> words;

int main()
{
    string str;
    bool checkBalance = true;
    while(1){
        getline(cin,str);
        if(str == ".") break;
        checkBalance = true;
        
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == '(' || str[i] == '['){
                words.push(str[i]);
            }
            else if(str[i] == ')' || str[i] == ']'){
                if(words.empty() 
                    || str[i] == ')' && words.top() != '(' 
                    || str[i] == ']' && words.top() != '['
                    ){
                    checkBalance = false;
                    i = str.size();
                }

                if(!words.empty())
                    words.pop();
            }
        }
        
        while(!words.empty()) {
            checkBalance = false;
            words.pop();
        }
        checkBalance == true ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}
