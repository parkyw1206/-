#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool myComp(pair<int,double> a , pair<int,double> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return  a.second < b.second;
    
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> failRate;
    int totalStudent = 0;
    
    failRate.push_back(make_pair(0,0));
    for(int i = 1 ; i <= N ; i++){
        failRate.push_back(make_pair(i,0));
    }
    for(int i = 0 ; i < stages.size() ; i++){
        if(stages[i] <= N){
            failRate[stages[i]].second++;            
        }

        totalStudent++;
    }
    for(int i = 1 ; i <= N ; i++){
        int failStudent = failRate[i].second;        
        if(totalStudent == 0)
            failRate[i].second = 0;
        else
            failRate[i].second /= totalStudent;
        totalStudent -= failStudent;
    }
    sort(failRate.begin(), failRate.end(),myComp);
    
    for(int i = N ; i >= 0 ; i--){
        if(failRate[i].first != 0 ) answer.push_back(failRate[i].first);
    }
    
    
    return answer;
}