#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int temp, total = 0;
    
    vector<pair<int,int>> nums;
    vector<int> numPicked;
    
    for(int i = 0 ; i < 8 ; i++){
        cin >> temp;
        nums.push_back({temp,i+1});
    }
    sort(nums.begin(), nums.end());
    for(int i = 7 ; i >= 3 ; i--){
        total += nums[i].first;
        numPicked.push_back(nums[i].second);
    }
    
    sort(numPicked.begin(), numPicked.end());
    
    cout << total <<endl;
    for(int i = 0 ; i < 5 ; i++){
        cout << numPicked[i] << " ";
    }
    return 0;
}
