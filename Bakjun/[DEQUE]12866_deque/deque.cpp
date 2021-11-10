#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,num;
    string str,script;
    deque<int> chars;
    cin >> N;
    cin.ignore();
    
    for(int i = 0 ; i < N ; i++){
        getline(cin, str);
        int loc = 0;
        script="";
        for(loc = 0 ; loc < str.size() && str[loc] != ' '; loc++){
            script += str[loc];
        }
        if(script == "push_front"){
            num = stoi(str.substr(loc+1));
            chars.push_front(num);
        }
        if(script == "push_back"){
            num = stoi(str.substr(loc+1));
            chars.push_back(num);
        }
        else if(script == "pop_front"){
            if(chars.empty()) printf("-1\n");
            else{
                printf("%d\n",chars.front());
                chars.pop_front();   
            }
        }
        else if(script == "pop_back"){
            if(chars.empty()) printf("-1\n");
            else{
                printf("%d\n",chars.back());
                chars.pop_back();   
            }
        }
        else if(script == "size"){
            printf("%d\n",chars.size());
        }
        else if(script == "empty"){
            if(chars.empty()) printf("1\n");
            else printf("0\n");
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
        

    }
    return 0;
}
