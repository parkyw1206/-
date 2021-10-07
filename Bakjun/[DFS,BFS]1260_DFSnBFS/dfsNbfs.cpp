#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N,M,V;

vector<vector<int>> field, fieldBFS; 
vector<vector<bool>> visited, visitedBFS;
vector<int> returnDFS, returnBFS;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int currPoint){
    returnDFS.push_back(currPoint);
    
    for(int i = 1 ; i <= N ; i++){
        if(!visited[currPoint][i] && field[currPoint][i] == 1 
            && find(returnDFS.begin(), returnDFS.end(), i) == returnDFS.end()) {
            visited[currPoint][i] = true;
            visited[i][currPoint] = true;
            dfs(i);
        }
    }
}

void bfs(int currPoint){
    queue<int> que;
    que.push(currPoint);
    returnBFS.push_back(currPoint);
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int i = 1 ; i <= N; i++){
            if(!visitedBFS[now][i] && fieldBFS[now][i] == 1 
                && find(returnBFS.begin(), returnBFS.end(), i) == returnBFS.end()){
                visitedBFS[now][i] = true;
                visitedBFS[i][now] = true;
                returnBFS.push_back(i);
                que.push(i);   
            }
        }
    }
}
int main(int argc, char** argv)
{
    int tempX,tempY;
    cin >> N >> M >> V;
    for(int i = 0 ; i <= N ; i++){
        field.push_back(vector<int>());
        visited.push_back(vector<bool>());
        for(int j = 0 ; j <= N ; j++){
            field[i].push_back(0);
            visited[i].push_back(false);
            if(i == 0) visited[0][j] = true;
            if(i == j) visited[i][i] = true;
        }
    }
    for(int i = 0 ; i < M ; i++){
        cin >> tempX >> tempY;
        field[tempX][tempY] = 1;
        field[tempY][tempX] = 1;
    }
    fieldBFS = field;
    visitedBFS = visited;
    
    dfs(V);
    for(int i = 0 ; i < returnDFS.size(); i++){
        cout << returnDFS[i] << " ";
    }
    cout << endl;
    
    bfs(V);
    for(int i = 0 ; i < returnBFS.size() ; i++){
        cout << returnBFS[i] << " ";
    }
    return 0;
}
