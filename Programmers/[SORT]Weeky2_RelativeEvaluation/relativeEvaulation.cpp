#include <string>
#include <vector>
#include <iostream>

using namespace std;
string answer = "";

void calcGrade(int score){
    if(score >= 90) answer.push_back('A');
    else if(score >= 80) answer.push_back('B');
    else if(score >= 70) answer.push_back('C');
    else if(score >= 50) answer.push_back('D');
    else answer.push_back('F');
}

string solution(vector<vector<int>> scores) {
    int totalScore = 0, maxScore = -1, minScore = 101,noMax = -1, noMin =101;
    for(int j = 0 ; j < scores[0].size() ; j++){
        totalScore = 0;
        maxScore = -1;
        noMax = -1;
        minScore = 101;
        noMin = 101;
        
        for(int i = 0 ; i < scores.size() ; i++){
            totalScore += scores[i][j];
            if(scores[i][j] > maxScore && scores[i][j] > noMax){
                maxScore = scores[i][j];
                noMax = scores[i][j];
            }
            else if(scores[i][j] == maxScore) maxScore = -1;
            
            if(scores[i][j] < minScore && scores[i][j] < noMin){
                minScore = scores[i][j];
                noMin = scores[i][j];
            } 
            else if(scores[i][j] == minScore) minScore = 101;
        }
        
        if(scores[j][j] == maxScore || scores[j][j] == minScore){
            totalScore -= scores[j][j];
            calcGrade(totalScore/(scores[0].size()-1));
        }
        else{
            calcGrade(totalScore/scores[0].size());
        }

    }
    return answer;
}