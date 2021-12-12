#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
 
    int N;
    long num, compNum =2000000000 , num1, num2;
    vector<long> nums;
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    
    int left = 0, right = N-1;
    while(left < right){
        if(compNum > abs(nums[left] + nums[right])){
                compNum = abs(nums[left] + nums[right]);
                num1 = nums[left];
                num2 = nums[right];
                if(nums[left] + nums[right] == 0) break;
        }
        if(nums[left] + nums[right] < 0) left++;
        else right--;
    }
    printf("%d %d",num1,num2);
    return 0;
}
