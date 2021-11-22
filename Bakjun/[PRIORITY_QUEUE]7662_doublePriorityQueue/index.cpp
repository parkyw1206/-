#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long MAX = 1000000; 

int main()
{
    string str;
    long long num,Q, T,count;
    unordered_map<long long, int> visited;
    priority_queue<long long> max; 
    priority_queue<long long,vector<long long>,greater<long long>> min;
    cin >> T;
    
    for(long long i = 0 ; i < T ; i++){
        cin >> Q;
        cin.ignore();
        count = 0;
        for(long long j = 0 ; j < Q ; j++){
            getline(cin,str);
            if(str[0] == 'I'){  
                num = stoll(str.substr(2));
                max.push(num);
                min.push(num);
                visited[num]++;
                count ++;
            }
            else if(str[0] == 'D'){
                num = stoi(str.substr(2));
                if(num == -1 && min.size() > 0){
                    while(visited[min.top()] == 0 && min.size() > 0){
                        min.pop();
                    }
        
                    if(min.size() > 0){
                        visited[min.top()]--;
                        min.pop();
                        count--;
                    }
                }
                else if(num == 1  && max.size() > 0){
                    while(visited[max.top()] == 0 && max.size() > 0){
                        max.pop();
                    }
                    if(max.size() > 0){
                        visited[max.top()]--;
                        max.pop();
                        count--;
                    }
                }
            }
        }
        while(visited[min.top()] == 0 && min.size() > 0){
            min.pop();
        }
        while(visited[max.top()] == 0 && max.size() > 0){
            max.pop();
        }
        if(count == 0) 
            cout << "EMPTY" << endl;
        else 
            cout << max.top() << " " << min.top() << endl;
            
        max = priority_queue<long long>();
        min =priority_queue<long long,vector<long long>,greater<long long>>();
        visited.clear();
    }
    return 0;
}
