#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    string line;
    stack<char> chars;
    
    cin >> T;
    cin.ignore();
    for(int i = 0 ; i < T ; i++){
        getline(cin, line);
        for(int j = 0 ; j < line.size() ; j++){
            if(line[j] == '(') chars.push('(');
            else{
                if(chars.empty()){
                    chars.push('-');
                    j = line.size();
                }
                else{
                    chars.pop();
                }
            }
        }
        if(chars.empty()){
            printf("YES \n");
        }
        else{
            printf("NO \n");
        }
        chars =stack<char>();
    }
    return 0;
}
