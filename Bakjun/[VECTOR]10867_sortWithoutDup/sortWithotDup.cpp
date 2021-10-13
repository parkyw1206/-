#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N, temp, maxNum = -1000;
    vector<int> nums;
    
    cin >> N;
    
    for(int i = 0 ; i < N ;i++){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()),nums.end());
    for(int i = 0 ; i < nums.size(); i++){
        //if(nums[i] > maxNum){
            cout << nums[i] <<" ";
        //    maxNum = nums[i];
        //}
    }
    return 0;
}
