#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M,N;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<vector<int>> family;
vector<bool> path;
int depth[101];

void bfs(int personOne){
    
    queue<int> que;    
    int tempFront;
    
    path[personOne] = true;
    que.push(personOne);
    
    while(!que.empty()){
        tempFront = que.front();
        que.pop();
        for(int i = 1 ; i <= N ; i++){
            if(family[tempFront][i] == 1 && !path[i]){
                path[i] = true;
                depth[i] = depth[tempFront]+1;
                que.push(i);
            }
        }
    }
}
int main(int argc, char** argv)
{
    int personOne, personTwo, parent, child;
    
    cin >> N;
    for(int i = 0 ; i <= N ; i++){
        family.push_back(vector<int>());
        path.push_back(false);
        for(int j = 0 ; j <= N ; j++){
            family[i].push_back(0);
        }
    }
    path[0] = true;
    
    cin >> personOne >> personTwo;
    cin >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> parent >> child;
        family[parent][child] = 1;
        family[child][parent] = 1;
    }
    bfs(personOne);
    if(depth[personTwo] > 0)
        cout << depth[personTwo] << endl;
    else
        cout << "-1" << endl;
    return 0;
}
