#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int N;
    string str;
    map<string,int> runner;
    vector<string> runnerList;
    
    cin >> N;
    cin.ignore();
    while(getline(cin,str)){
        if(runner[str] == 0){
            runnerList.push_back(str);
            runner[str]++;
        }
        else {
            runner[str]++;
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        if(runner[runnerList[i]] % 2 == 1){
            cout << runnerList[i]; 
            break;
        }
    }
    return 0;
}
