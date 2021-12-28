#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> nums, path;
vector<int> pathLine;
int N,num;
   
void search(int startLocation, int currLocation,bool startPoint = false){
    if(startPoint){
        path[startLocation][currLocation] = 1;
        pathLine[currLocation] = 1;
    }
    for(int i = 0 ; i < N; i++){
        if(i == currLocation || nums[currLocation][i] == 0) continue;
        if(pathLine[i] == 0){
            search(startLocation,i,true);
        }
    }
}

int main()
{
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        nums.push_back(vector<int>());
        path.push_back(vector<int>());
        for(int j = 0 ; j < N ; j++){
            cin >> num;
            nums[i].push_back(num);
            path[i].push_back(0);
            pathLine.push_back(0);
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        fill(pathLine.begin(),pathLine.end(),0);
        search(i,i);
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << path[i][j]<< " " ;
        }
        cout << endl;
    }    
    
    return 0;
}
