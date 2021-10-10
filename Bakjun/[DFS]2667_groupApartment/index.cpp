#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>>field;
vector<vector<bool>> groupField;
int N, count = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void search(int curY, int curX){
    groupField[curY][curX] = true;
    count++;
    for(int i = 0 ; i < 4 ; i++){
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];
        
        if(nextY < 0 || nextY >= N 
        || nextX < 0 || nextX >= N 
        || groupField[nextY][nextX] == true
        || field[nextY][nextX] == '0')
            continue;
            
        search(nextY, nextX);
    }    
}
int main(int argc, char** argv)
{
    char temp;
    priority_queue<int,vector<int>, greater<int>> que;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        field.push_back(vector<char>());
        groupField.push_back(vector<bool>());
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            field[i].push_back(temp);
            groupField[i].push_back(false);
        }
        
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(field[i][j] == '1' && groupField[i][j]== false){
                count = 0;
                search(i,j);
                que.push(count);
            }
        }
    }
    cout << que.size() <<endl;
    while(!que.empty()){
        cout << que.top() << endl;
        que.pop();
    }
    return 0;
}
