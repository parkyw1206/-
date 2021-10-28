#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int V,E;
long long check[10001] = {0, };
vector<pair<long long ,pair<int,int>>> nums;

int getParent(int node){
    if(check[node] == node) return node;
    return getParent(check[node]);
}

//두 노드를 작은값을 기준으로 연결합니다. 
void unionParent(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1<node2) check[node2] = node1;
	else check[node1] = node2;
}

//싸이클이 존재하면 true, 아니면 false를 반환
bool isCycle(int node1 , int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if(node1 == node2) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int from,to,value;
    cin >> V>> E;
    
    for(int i = 0 ; i < E; i++){
        cin >> from >> to >> value;
        nums.push_back({value,{from,to}});
    }
    sort(nums.begin(), nums.end());
    for(int i = 1 ; i <= V; i++)
        check[i] = i;
        
    long long  sum = 0;
    for(int i = 0 ; i < E; i++) {
        if(!isCycle(nums[i].second.first, nums[i].second.second)){
			unionParent(nums[i].second.first, nums[i].second.second);
            sum += nums[i].first;
        }
    }
    cout << sum;
    return 0;
}
