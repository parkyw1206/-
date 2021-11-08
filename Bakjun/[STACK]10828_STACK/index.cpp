#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,num;
    string str,script;
    stack<int> chars;
    cin >> N;
    cin.ignore();
    for(int i = 0 ; i < N ; i++){
        getline(cin, str);
        int loc = 0;
        script="";
        for(loc = 0 ; loc < str.size() && str[loc] != ' '; loc++){
            script += str[loc];
        }
        if(script == "push"){
            num = stoi(str.substr(loc+1));
            chars.push(num);
        }
        else if(script == "top"){
            if(chars.empty()) printf("-1\n");//cout << "-1" << endl;
            else
                printf("%d\n",chars.top());
        }
        else if(script == "size"){
            printf("%d\n",chars.size());
        }
        else if(script == "pop"){
            if(chars.empty()) printf("-1\n");
            else{
                printf("%d\n",chars.top());
                chars.pop();   
            }
        }
        else if(script == "empty"){
            if(chars.empty()) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
s