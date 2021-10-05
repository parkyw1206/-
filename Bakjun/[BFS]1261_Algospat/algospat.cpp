#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> puzzle;
vector<vector<int>>path;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void search(int startX, int startY){
    queue<pair<int,int>> que;
    que.push(make_pair(startX,startY));
    path[startY][startX] = 0;
    
    while(!que.empty()){
        pair<int,int> now = que.front();
        que.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nextX = now.first + dx[i];
            int nextY = now.second + dy[i];
            if(nextY<0 || nextY >= path.size() || nextX < 0 || nextX >= path[0].size()){
                continue;
            }
            if(puzzle[nextY][nextX] == '1'){
                if(path[nextY][nextX] > path[now.second][now.first]+1){
                    path[nextY][nextX] = path[now.second][now.first]+1;
                    que.push(make_pair(nextX,nextY));
                }
            }
            else if(puzzle[nextY][nextX] == '0'){
                if(path[nextY][nextX] > path[now.second][now.first]){
                    path[nextY][nextX] = path[now.second][now.first];
                    que.push(make_pair(nextX,nextY));
                }
            }
        }
        
    }
}
int main(int argc, char** argv)
{
    int N,M;
    char temp;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        puzzle.push_back(vector<char> ());
        path.push_back(vector<int> ());
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            puzzle[i].push_back(temp);
            path[i].push_back(99999);
        }
    }
    search(0,0);
    cout << path[M-1][N-1];
    return 0;
}
