#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,num;
    string str,script;
    queue<int> chars;
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
        else if(script == "front"){
            if(chars.empty()) printf("-1\n");
            else
                printf("%d\n",chars.front());
        }
        else if(script == "back"){
            if(chars.empty()) printf("-1\n");
            else
                printf("%d\n",chars.back());
        }
        else if(script == "size"){
            printf("%d\n",chars.size());
        }
        else if(script == "pop"){
            if(chars.empty()) printf("-1\n");
            else{
                printf("%d\n",chars.front());
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