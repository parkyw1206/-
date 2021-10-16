#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, temp, sum = 0;
    vector<int> nums;
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j <= i; j++){
            sum += nums[j];
        }
    }
    cout << sum;
    return 0;
}