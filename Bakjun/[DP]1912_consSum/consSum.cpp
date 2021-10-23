#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, temp, sum = 0;
    vector<int> nums,dp;
    cin >> N;
    
    for(int i = 0 ; i < N ;i++){
        cin >> temp;
        nums.push_back(temp);
        dp.push_back(temp);
    }

    sum = nums[0];

    for(int i = 1 ; i < N; i++){
        dp[i] = max(dp[i], dp[i-1]+nums[i]);
        
        if(dp[i]> sum){
            sum = dp[i];
        }
    }
    cout << sum;
    return 0;
}

