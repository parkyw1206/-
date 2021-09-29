 
#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<bool>> visited;

void dfs(int pointY, int pointX, vector<vector<int>> totalMap){
    int nextPointY, nextPointX;
    visited[pointY][pointX] = true;

    for(int i = -1 ; i < 2 ; i++){
        for(int j = -1 ; j < 2 ; j++){
            nextPointY=pointY + i;
            nextPointX = pointX + j;
            if((i == 0 && j == 0) ||
                nextPointY < 0 || nextPointY >= totalMap.size() ||
                nextPointX < 0 || nextPointX >= totalMap[0].size())
                continue;
            if(totalMap[nextPointY][nextPointX] && !visited[nextPointY][nextPointX] ){ 
                dfs(nextPointY, nextPointX, totalMap);
            }
        }
    }
}
int main(int argc, char** argv)
{
	int width =1 , height =1, temp, returnCout = 0;
	vector<vector<int>> totalMap;
	while(!(width == 0 && height == 0)){
        cin >> width >> height;
	    returnCout = 0 ;
        totalMap = {};
        visited = {};
        for(int i = 0 ; i < height; i ++){
            totalMap.push_back(vector<int>());
            visited.push_back(vector<bool>());
            for(int j = 0 ; j < width; j++){
                cin >> temp;
                totalMap[i].push_back(temp);
                visited[i].push_back(false);
            }
        }
        
        for(int i = 0 ; i < height ; i++){
            for(int j = 0 ; j < width ; j++){
                if(totalMap[i][j] && !visited[i][j]){
                    dfs(i,j,totalMap);    
                    returnCout++;
                }
            }
        }
        
        if(!(width == 0 && height == 0)){
         cout << returnCout << endl;
        }
	}

	return 0;
}
