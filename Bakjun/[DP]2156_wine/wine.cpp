#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    int N, temp;
    vector<int> wines, dp;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        wines.push_back(temp);
        dp.push_back(temp);
    }
    
    
    dp[0] = wines[0];
    dp[1] = wines[0]+wines[1]; 
    
    
    for(int i = 2; i < N ; i++){
        dp[i] = max(dp[i-2]+wines[i],dp[i-3]+wines[i-1]+wines[i]);
        dp[i] = max(dp[i],dp[i-1]);
        
    }
    cout << dp[N-1];
    return 0;
}
