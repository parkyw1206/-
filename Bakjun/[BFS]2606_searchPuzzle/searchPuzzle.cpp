#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> puzzle;
vector<vector<int>> path;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int N, M;
    
void search(int currY, int currX){
    queue<pair<int,int>> que;
    que.push({currY, currX});
    path[currY][currX] = 1;
    
    while(!que.empty()){
        pair<int,int> current = que.front();
        que.pop();
        for(int i = 0 ; i < 4; i++){
            int nextX = current.second + dx[i];
            int nextY = current.first + dy[i];
            
            if(nextX < 0 || nextX >= M 
                || nextY < 0 || nextY >= N)
                continue;
            
            if(puzzle[nextY][nextX] == '1' && path[nextY][nextX] == 0){
                path[nextY][nextX] = path[current.first][current.second] + 1;
                que.push({nextY, nextX});
            }
        }
    }
}
int main(int argc, char** argv)
{
    char temp;
    
    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        puzzle.push_back(vector<char>());
        path.push_back(vector<int>());
        for(int j = 0 ; j < M ; j++){
            cin >> temp;
            puzzle[i].push_back(temp);
            path[i].push_back(0);
        }
    }
    
    search(0,0);
    cout << path[N-1][M-1];
    return 0;
}
