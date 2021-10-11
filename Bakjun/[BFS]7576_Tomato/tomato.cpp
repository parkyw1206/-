#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> tomatos;
vector<vector<bool>> visitedTom;
queue<pair<int,int>> que;

int N, M;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void initVisit(){
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            visitedTom[i][j] = false;
        }
    }
}
void search(){

    initVisit();
    
    while(!que.empty()){
        int currX = que.front().second;
        int currY = que.front().first;
        que.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];
            if(nextX < 0 || nextX >= N || 
                nextY < 0 || nextY >= M)
                continue;
            
            if(tomatos[nextY][nextX] == 0 
                || (tomatos[nextY][nextX] != -1 && !visitedTom[nextY][nextX] && tomatos[nextY][nextX] > tomatos[currY][currX] + 1)){
                tomatos[nextY][nextX] = tomatos[currY][currX] + 1;
                visitedTom[currY][currX] = true;
                que.push({nextY,nextX});
            }
            
        }
    }
}

int main(int argc, char** argv)
{
    int temp, maxNum = 0;
    cin >> N >> M ;
    for(int i = 0 ; i < M ; i++){
        tomatos.push_back(vector<int>());
        visitedTom.push_back(vector<bool>());
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            tomatos[i].push_back(temp);
            visitedTom[i].push_back(false);
        }
    }
    
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(tomatos[i][j] == 1){
                que.push({i,j});
            }
        }
    }
    
    search();
    for(int i = 0 ; i < M ; i++){
        for(int j = 0; j < N ; j++){
            if(tomatos[i][j] == 0){
                cout << -1 ;
                return 0;
            }
            if(maxNum < tomatos[i][j])
                maxNum = tomatos[i][j];
        }
    }
    cout << maxNum -1 ;
    return 0;
}
