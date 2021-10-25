#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1, stemina = 0, cnt;
    vector<int> nums;
    
    for(int i = 0 ; i < dungeons.size() ;i++){
        nums.push_back(i);
    }
    do{
        stemina = k;
        cnt = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(stemina >= dungeons[nums[i]][0]){
                stemina -= dungeons[nums[i]][1];
                cnt++;
            }
            else{
                i = nums.size();
            }
        }
        if(cnt!= 0 && cnt > answer) {
            answer = cnt;
        }
    }while(next_permutation(nums.begin(), nums.end()));
    
    return answer == 0 ? -1 : answer;
}