#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[201] = {0, };
vector<int> path;
int N,M,past,temp;

int getParent(int node){
    if(visited[node] == node) return node;
    visited[node] = getParent(visited[node]);
    return visited[node];
}

//두 노드를 작은값을 기준으로 연결합니다. 
void unionParent(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1 == node2) return;
	visited[node2] = node1;
	getParent(node2);
}
int main()
{
    bool canArrive = true;

    cin >> N >> M;
    for(int i = 0 ; i <= 200 ; i++) visited[i] = i;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> temp;
            if(temp == 1)
                unionParent(i,j);
        }
    }
    
    cin >> past;
    for(int i = 1 ; i < M ; i++){
        cin >> temp;
        if(!canArrive) continue;
        if(getParent(past) != getParent(temp)) canArrive = false;
        past = temp;;
    }
    
    if(canArrive) cout << "YES";
    else cout << "NO";
    return 0;
}
