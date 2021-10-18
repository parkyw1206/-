#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> nums;
priority_queue<int> pq;

int main()
{
    int N, temp;
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        nums.push(temp);
    }
    while(!nums.empty()){
        pq.push(nums.top()*nums.size());
        nums.pop();
    }
    cout << pq.top();
    return 0;
}