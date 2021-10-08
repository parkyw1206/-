#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, spicy, moreSpicy,count = 0;
    priority_queue<int, vector<int>,greater<int>> scovilleQue;
    
    for(int i = 0 ; i < scoville.size() ; i++){
        scovilleQue.push(scoville[i]);
    }
    while(scovilleQue.size() > 1){
        spicy  = scovilleQue.top();
        scovilleQue.pop();
        moreSpicy = scovilleQue.top();
        scovilleQue.pop();
        if(spicy > K) return count;
        scovilleQue.push(spicy + moreSpicy * 2);
        count++;
    }
    if(scovilleQue.top() < K) 
        return -1;
    else
        return count;
}
