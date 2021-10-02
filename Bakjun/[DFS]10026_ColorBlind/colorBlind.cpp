#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> visitMap,visitMapCB;
int N;

bool checkValid(int i, int j){
    return i >= 0 && i < N && j >= 0 && j < N;
}
void search(int i , int j, char color, vector<vector<char>> totalMap ){

    visitMap[i][j] = true;
    
    if(checkValid(i-1,j) && totalMap[i-1][j] == color && visitMap[i-1][j] == false) {
        search(i-1,j,color,totalMap);
    }
    if(checkValid(i,j-1) && totalMap[i][j-1] == color && visitMap[i][j-1] == false) {
        search(i,j-1,color,totalMap);
    }
    if(checkValid(i+1,j) && totalMap[i+1][j] == color && visitMap[i+1][j]== false) {
        search(i+1,j,color,totalMap);
    }
    if(checkValid(i,j+1) && totalMap[i][j+1] == color && visitMap[i][j+1] == false) {
        search(i,j+1,color,totalMap);
    }
}

void searchColorBlind(int i , int j, char color, vector<vector<char>> totalMap ){

    visitMapCB[i][j] = true;
    char acceptColor[2] ;
    
    if(color == 'B') {
        acceptColor[0] = 'B';
        acceptColor[1] = 'W';
    }else { 
        acceptColor[0] = 'R';
        acceptColor[1] = 'G';
    }
    
    if(checkValid(i-1,j) && ( acceptColor[0] == totalMap[i-1][j] || acceptColor[1] == totalMap[i-1][j] )  && visitMapCB[i-1][j] == false) {
        searchColorBlind(i-1,j,color,totalMap);
    }
    if(checkValid(i,j-1)  && ( acceptColor[0] == totalMap[i][j-1] || acceptColor[1] == totalMap[i][j-1] ) && visitMapCB[i][j-1] == false) {
        searchColorBlind(i,j-1,color,totalMap);
    }
    if(checkValid(i+1,j) &&  ( acceptColor[0] == totalMap[i+1][j] || acceptColor[1] == totalMap[i+1][j] )  && visitMapCB[i+1][j]== false) {
        searchColorBlind(i+1,j,color,totalMap);
    }
    if(checkValid(i,j+1) &&  ( acceptColor[0] == totalMap[i][j+1] || acceptColor[1] == totalMap[i][j+1] )  && visitMapCB[i][j+1] == false) {
        searchColorBlind(i,j+1,color,totalMap);
    }        
}

int main(int argc, char** argv)
{
    int returnCount = 0, returnColorBlind = 0;
    vector<vector<char>> totalMap;
    char temp;
    
    cin >> N;
    for(int i = 0 ; i < N; i++){
        totalMap.push_back(vector<char>());
        visitMap.push_back(vector<bool>());
        visitMapCB.push_back(vector<bool>());
        for(int j = 0 ; j < N ; j++){
            cin >> temp;
            totalMap[i].push_back(temp);
            visitMap[i].push_back(false);
            visitMapCB[i].push_back(false);
        }
    }    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!visitMap[i][j]){
                search(i,j,totalMap[i][j],totalMap);
                returnCount++;
            }
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!visitMapCB[i][j])
            {
                searchColorBlind(i,j,totalMap[i][j],totalMap);
                returnColorBlind++;
            }
        }
    }
    cout << returnCount << " " << returnColorBlind;
    return 0;
}
