#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int X,N,ppl;
    vector<int> visitors, sumVisitors;
    
    cin >> N >> X;
    for(int i = 0 ; i < N ; i++){
        cin >> ppl;
        visitors.push_back(ppl);
        sumVisitors.push_back(ppl);
    }
    
    int left = 0,countX = 0,sum = 0;
    
    for(int i = 0 ; i < N ; i++){
        if(countX < X-1) {
            sum += visitors[i];
            countX++;
        }
        else if(countX == X-1){
            sum += visitors[i];
            sumVisitors[i] = sum;
            countX++;
        }
        else if(countX == X){
            sum -= visitors[left++];
            sum += visitors[i];
            sumVisitors[i] = sum;
        }
     }
    
    sort(sumVisitors.begin(), sumVisitors.end(),greater<int>());
    
    int maxNum = sumVisitors[0], count = 0;
    if(maxNum == 0) {
        cout << "SAD";
        return 0;
    }
    for(int i = 0 ; i < N; i++){
        if(maxNum == sumVisitors[i]) count++;
    }
    cout << maxNum << '\n' << count;
    return 0;
}
