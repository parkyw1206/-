#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    string sentence;
    stack<char> charStack;
    cin >> T;
    cin.ignore(256,'\n');
    
    for(int i = 0 ; i < T ; i++){
        getline(cin, sentence);
        for(int i = 0 ; i < sentence.size() ;i++){
            if(sentence[i] == ' '){
                while(!charStack.empty()){
                    cout << charStack.top();
                    charStack.pop();
                }
                cout << ' ';
                
            }
            else {
                charStack.push(sentence[i]);
            }
        }
        while(!charStack.empty()){
            cout << charStack.top();
            charStack.pop();
        }
        cout << endl;
    }

    return 0;
}
