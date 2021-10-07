#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,M;
long long count;

vector<vector<char>> field; // W: White B: Blue
vector<vector<bool>> visited;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int currX, int currY, char color){
    int nextX, nextY;
    count ++;
    visited[currY][currX] = true;
    
    for(int i = 0 ; i < 4;i++){
        nextX = currX + dx[i];
        nextY = currY + dy[i];
        if(nextX < 0 || nextX >= N|| nextY < 0 || nextY >= M)
            continue;

        if(!visited[nextY][nextX] && field[nextY][nextX] == color)
            dfs(nextX, nextY,color);
    }
    return;
}
int main(int argc, char** argv)
{
    char temp;
    long long countW = 0 , countB = 0;
    cin >> N >> M;

    for(int i = 0 ; i < M ; i++){
        field.push_back(vector<char>());
        visited.push_back(vector<bool>());
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            field[i].push_back(temp);
            visited[i].push_back(false);
        }
    }

    for(int i = 0 ; i < M ; i++){
        for(int j = 0; j < N ; j++){
            count = 0;
            if(!visited[i][j]){
                dfs(j,i,field[i][j]);
                if(field[i][j] == 'W'){
                    countW += count*count;
                }
                else{
                    countB += count*count;
                }
            }

        }
    }    
    cout << countW << " " << countB ;
    return 0;
}
