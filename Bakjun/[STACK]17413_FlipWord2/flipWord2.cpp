#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void flipWord(stack<char> wordStack){
    while(!wordStack.empty()){
        cout << wordStack.top();
        wordStack.pop();
    }
}
int main()
{
    string S;
    queue<char> alphabetStack;
    stack<char> tempStack;
    getline(cin,S);
    for(int i = 0 ; i < S.size() ; i++){
        alphabetStack.push(S[i]);
    }
    while(!alphabetStack.empty()){
        if(alphabetStack.front() == ' '){
            flipWord(tempStack);
            tempStack = stack<char>();
            cout << " ";
            alphabetStack.pop();
        }
        else if(alphabetStack.front() == '<'){
            if(!tempStack.empty()){
                flipWord(tempStack);
                tempStack = stack<char>();
            }
            while(alphabetStack.front() != '>'){
                cout << alphabetStack.front();
                alphabetStack.pop();
            }
            cout << ">";
            alphabetStack.pop();
        }
        else{
            tempStack.push(alphabetStack.front());
            alphabetStack.pop();
        }
        
    }
    flipWord(tempStack);
    return 0;
}
