#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,M,num;
    vector<int> nums;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> num;
        nums.push_back(num);
    }

    int left = 0 , middle = 1 , right =2, sum = -300000;
    
    // while(left < middle && middle < right && right < N){
    //     cout << "CHECK " << left << ", " << middle << ", " <<right << "->"<<nums[left] + nums[middle] + nums[right] << endl;
    //     if(nums[left] + nums[middle] + nums[right] <= M &&
    //         M - nums[left] - nums[middle] - nums[right] <  M - sum){
    //         sum = nums[left] + nums[middle] + nums[right];
    //         cout << left << " , " << middle << " , " << right <<" = "<< sum <<endl;
    //     }
        
    //     if(middle == right - 1 && right < N){
    //         if(middle == right -1 && right == N-1 && left< middle)
    //             left++;
    //         else
    //           right++;  
    //     } 
    //     else if(left == middle - 1 && middle < right ){ 
    //         middle++;
    //     }
    //     else left++;
    // }
    for(left = 0 ; left < N ; left++){
        for(middle = left+1 ; middle< N ; middle++){
            for(right = middle + 1; right < N ; right++){
        if(nums[left] + nums[middle] + nums[right] <= M &&
            M - nums[left] - nums[middle] - nums[right] <  M - sum){
            sum = nums[left] + nums[middle] + nums[right];
        }
            }
        }
    }
    cout << sum;
    return 0;
}
