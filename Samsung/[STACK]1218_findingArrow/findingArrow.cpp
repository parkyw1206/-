#include <iostream>
#include <stack>

using namespace std;

stack<char> dict;
    
bool popDict(char thisChar){
    char firstChar = dict.top();
    dict.pop();
    switch(thisChar){
        case ')':
            if(firstChar != '(') return false;
            break;
        case ']':
            if(firstChar != '[') return false;
            break;
        case '}':
            if(firstChar != '{') return false;
            break;
        case '>':
            if(firstChar != '<') return false;
            break;
    }
    return true;
}
int main()
{
    int TEST_CASE = 10, wordLength;
    char temp;
    string tempStr;
    
    for(int i = 0; i < TEST_CASE ; i++){
        dict=stack<char>();
        cin >> wordLength;
        for(int j = 0 ; j < wordLength; j++){
            cin >> temp;
            if(temp == '(' || temp == '[' || temp == '{' || temp == '<')
                dict.push(temp);
            else if(!popDict(temp)){
                cout << "#" << i+1 << " " << "0" << endl;
                j = wordLength;
                getline(cin,tempStr);
            }
            if(j == wordLength-1)
                cout <<"#" << i+1 << " " <<  "1" <<endl;   
        }
    }
    return 0;
}
