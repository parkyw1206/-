#include <iostream>
#include <algorithm>

using namespace std;

int check[1000001];

int getParent(int node){
    if(check[node] == node) return node;
    check[node] = getParent(check[node]);
    return check[node];
}

//두 노드를 작은값을 기준으로 연결합니다. 
void unionParent(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1 == node2) return;
	check[node2] = node1;
}

int main()
{
    int V,E,a,b,c;
    
    cin >> V>> E;
    
    for(int i = 1 ; i < 1000001; i++)
        check[i] = i;
        
    for(int i = 0 ; i < E; i++) {
        scanf("%d%d%d",&c,&a,&b);
        if(c == 0){
            unionParent(a,b);
        }
        else{
            if(getParent(a) == getParent(b)){
                printf("YES\n");
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}
