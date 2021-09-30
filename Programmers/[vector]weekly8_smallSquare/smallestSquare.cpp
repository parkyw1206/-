#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width = 0 , height = 0;
    for(int i = 0 ; i < sizes.size() ; i++){
        if(sizes[i][0] > sizes[i][1]){
            if(height < sizes[i][0]) height = sizes[i][0];
            if(width < sizes[i][1]) width = sizes[i][1];
        }
        else{
            if(height < sizes[i][1]) height = sizes[i][1];
            if(width < sizes[i][0]) width = sizes[i][0];
        }
    }
    answer = width * height;
    return answer;
}