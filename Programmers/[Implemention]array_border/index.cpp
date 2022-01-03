#include <string>
#include <vector>
#include <iostream>

using namespace std;

int puzzle[101][101] = {0};
int minVal,tempCurVal;

void doRight(int startY, int startX, int endY, int endX, int curValue){
    if(startX == endX) return;
    tempCurVal = puzzle[startY][startX+1];    
    if(curValue == -1)
        puzzle[startY][startX+1] = puzzle[startY][startX];
    else 
        puzzle[startY][startX+1] = curValue;
    if(tempCurVal < minVal) minVal =tempCurVal;
    doRight(startY,startX+1,endY,endX,tempCurVal);
}
void doDown(int startY, int startX, int endY, int endX, int curValue){
    if(startY == endY) return;
    tempCurVal = puzzle[startY+1][startX];
    puzzle[startY+1][startX] = curValue;
    if(tempCurVal < minVal) minVal =tempCurVal;
    doDown(startY+1,startX,endY,endX, tempCurVal);
}
void doLeft(int startY, int startX, int endY, int endX, int curValue){
    if(startX == endX) return;    
    tempCurVal = puzzle[endY][endX-1];
    puzzle[endY][endX-1] = curValue;
    if(tempCurVal < minVal) minVal =tempCurVal;
    doLeft(startY,startX,endY,endX-1,tempCurVal);
}
void doUp(int startY, int startX, int endY, int endX, int curValue){
    if(startY == endY) return;    
    tempCurVal = puzzle[endY-1][endX];
    puzzle[endY-1][endX] = curValue;
    if(tempCurVal < minVal) minVal =tempCurVal;
    doUp(startY,startX,endY-1,endX,tempCurVal);
}

void doRotate(vector<int> query){
    tempCurVal = -1;
    doRight(query[0],query[1],query[0],query[3],tempCurVal);
    doDown(query[0],query[3],query[2],query[3],tempCurVal);
    doLeft(query[2],query[1],query[2],query[3],tempCurVal);
    doUp(query[0],query[1],query[2],query[1],tempCurVal);
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int cnt = 1;
    for(int i = 1 ; i <= rows; i++){
        for(int j = 1 ; j <= columns; j++){
          puzzle[i][j] = cnt++;
        }
    }
    
    for(int i = 0 ; i < queries.size() ; i++){
        minVal = 987654321;
        doRotate(queries[i]);
        answer.push_back(minVal);
    }

    return answer;
}