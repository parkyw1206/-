#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long N,M,num;
    vector<long long> aVector,bVector;
    
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> N >> M;
    for(long long i = 0 ; i < N ; i++){
        cin >> num;
        aVector.push_back(num);
    }
    for(long long i = 0 ; i < M ; i++){
        cin >> num;
        bVector.push_back(num);
    }
    
    long long curA = 0, curB = 0, currVal = -1000000000;
    
    while(1){
        if(currVal <= aVector[curA] && currVal <= bVector[curB]){
            if(aVector[curA] <= bVector[curB]){
                currVal = aVector[curA++];
            } 
            else
                currVal = bVector[curB++];
        } 
        else if (curA == N && curB < M){
            currVal = bVector[curB++];
        }
        else if (curA < N && curB == M){
            currVal = aVector[curA++];
        }
        else {
            break;
        }
        cout << currVal << " ";
    }
    return 0;
}
