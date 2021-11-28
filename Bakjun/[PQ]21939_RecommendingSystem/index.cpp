#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct cmp {
    bool operator()(pair<int,int>a, pair<int,int> b){
        if(a.first != b.first) return a.first > b.first;
        else{
             return a.second > b.second;   
        }
    }
};
struct cmp1 {
    bool operator()(pair<int,int>a, pair<int,int> b){
        if(a.first != b.first) return a.first < b.first;
        else{
             return a.second < b.second;   
        }
    }
};

int main()
{   

    int N,P,M,L,x;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp1> problems;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> minProblems;
    string direction, pstr,lstr;
    map<int,int> m;
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> P >> L;
        problems.push({L,P});
        minProblems.push({L,P});
        m[P] = L;
    }
    
    cin >> M;
    cin.ignore();
    
    for(int i = 0 ; i < M ; i++){
        getline(cin,direction,' ');
        if(direction == "add") {
            getline(cin,pstr,' ');
            getline(cin,lstr);
            P = stoi(pstr);
            L = stoi(lstr);
            problems.push({stoi(lstr),stoi(pstr)});
            minProblems.push({stoi(lstr),stoi(pstr)});
            m[P] = L;
        }
        else if(direction == "solved"){
            cin >> P;
            m[P] = 0;
            cin.ignore();
        }
        else{
            cin >> x;
            if(x == 1){
                while(m[problems.top().second] != problems.top().first && problems.size() > 0 ){
                    problems.pop();
                }
                if(problems.size() > 0)
                    cout << problems.top().second<<endl;
            }
            else{
                while(m[minProblems.top().second] != minProblems.top().first && minProblems.size() > 0 ){
                    minProblems.pop();
                }
                if(minProblems.size() > 0)
                    cout << minProblems.top().second<<endl;
            }
            cin.ignore();
        }
    }
    return 0;
}
