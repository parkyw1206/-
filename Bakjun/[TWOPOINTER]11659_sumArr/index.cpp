#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int N,M,j,k,num,sum = 0;
    vector<int> numList,addList;
    cin >> N >> M;
    
    addList.push_back(0);
    
    for(int i = 0 ; i < N ; i++){
        cin >> num;
        numList.push_back(num);
        sum += num;
        addList.push_back(sum);
    }
    
    for(int i = 1 ; i <= M ; i++){
        cin >> j >> k;
        printf("%d \n",addList[k] - addList[j-1]);
    }
    return 0;
}
