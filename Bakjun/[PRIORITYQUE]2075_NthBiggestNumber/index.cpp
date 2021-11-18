#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<long long int> que;
    int N, temp,minNum = 0;
    
    cin >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            scanf("%d",&temp);
            
            que.push(-temp);
            if(que.size() > N) que.pop();

        }
    }
    printf("%d",-que.top());

    return 0;
}
