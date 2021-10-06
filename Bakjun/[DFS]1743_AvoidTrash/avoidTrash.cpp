#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,M,K, count = 0, maxTrah = 0;
vector<vector<int>> field; // 0 : empty 2: trash
vector<vector<bool>> visited;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int currX, int currY){
    int nextX, nextY;
    count ++;
    visited[currY][currX] = true;
    
    for(int i = 0 ; i < 4;i++){
        nextX = currX + dx[i];
        nextY = currY + dy[i];
        if(nextX <= 0 || nextX > M || nextY <= 0 || nextY > N)
            continue;
            
        if(!visited[nextY][nextX] && field[nextY][nextX])
            dfs(nextX, nextY);
    }
    return;
}
int main(int argc, char** argv)
{
    int r,c;
    
    cin >> N >> M >> K;
    for(int i = 0 ; i <= N ; i++){
        field.push_back(vector<int>());
        visited.push_back(vector<bool>());
        for(int j = 0 ; j <= M ; j++){
            if(i == 0) visited[0].push_back(true);
            else{
                field[i].push_back(0);
                visited[i].push_back(false);                
            }
        }
    }
    for(int i = 0 ; i < K ; i++){
        cin >> r >> c;
        field[r][c] = 2;
    }
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(!visited[i][j] && field[i][j] == 2){
                count = 0;
                dfs(j,i);                
                if(maxTrah < count) maxTrah = count;
                
            }
        }
    }

    cout<< maxTrah;
    return 0;
}
