#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

vector<vector<int>> puzzle, clearPuzzle, path,clearPath;

int dx[3] = {-1,1,0};
int dy[3] = {0,0,1};

int search(int startPoint){
    queue<pair<int,int>> que;
    que.push({startPoint, 0});
    path[0][startPoint] = 1;

    while(!que.empty()){
        int currX = que.front().first;
        int currY = que.front().second;
        que.pop();
        if(currY == 99) return path[currY][currX];
        
        for(int i = 0 ; i < 3; i++){
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];
            if(nextX < 0 || nextX >= 100 || nextY < 0 || nextY >= 100)
                continue;

            if(puzzle[nextY][nextX] == 1 && path[nextY][nextX] == 0){
                path[nextY][nextX] = path[currY][currX] + 1;
                que.push({nextX,nextY});
                i = 3;
            }
        }
    }
    return 0;
}
int main()
{
    fastio;
    int TEST_CASE=10, T,temp;
    queue<int> startX;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i = 0 ; i < TEST_CASE; i++){
        cin >>T;
        for(int j = 0 ; j < 100;j++){
            puzzle.push_back(vector<int>());
            path.push_back(vector<int>());
            for(int k = 0 ; k < 100; k++){
                cin >> temp;
                puzzle[j].push_back(temp);
                path[j].push_back(0);
                
                if(j == 0 && temp == 1){
                    startX.push(k);
                }
            }        
        }
        clearPath = path;
        clearPuzzle = puzzle;
        while(!startX.empty()){
            int curr = search(startX.front());
            pq.push({curr,startX.front()});
            path = clearPath;
            puzzle = clearPuzzle;
            startX.pop();
        }
        cout <<  "#" << T << " " << pq.top().second << endl;   
        
        pq = {};
        puzzle = {};
        path = {};
    }
    return 0;
}
