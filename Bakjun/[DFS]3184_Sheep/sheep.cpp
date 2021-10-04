#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> visited;
vector<vector<char>> field ;
int countSheep = 0, countWolf = 0;
int R, C;

bool checkValid (int y, int x){
    return y >= 0 && y < R && x >= 0 && x < C;
}

void searchSheep (int currY, int currX){
    visited[currY][currX] = true;
    
    if(field[currY][currX] == 'v') countWolf++;
    else if(field[currY][currX] == 'o') countSheep++;
    
    if(checkValid(currY-1,currX) && !visited[currY-1][currX]) searchSheep(currY-1, currX);
    if(checkValid(currY+1,currX) && !visited[currY+1][currX]) searchSheep(currY+1, currX);
    if(checkValid(currY,currX+1) && !visited[currY][currX+1]) searchSheep(currY, currX+1);
    if(checkValid(currY,currX-1) && !visited[currY][currX-1]) searchSheep(currY, currX-1);

}

int main(int argc, char** argv)
{

    char temp;
    
    int returnSheep = 0, returnWolf = 0;
    cin >> R >> C;
    
    for(int i = 0 ; i < R ; i++){
        field.push_back(vector<char> ());
        visited.push_back(vector<bool>());
        for(int j = 0 ; j < C ; j++){
            cin >> temp;
            field[i].push_back(temp);
            if(temp != '#')
                visited[i].push_back(false);
            else
                visited[i].push_back(true);
        }
    }

    for(int i = 0 ; i < R;i++){
        for(int j = 0 ; j < C; j++){
            if(!visited[i][j] && ( field[i][j] == 'o' || field[i][j] == 'v' )){
                countSheep = 0;
                countWolf = 0;
                searchSheep(i,j);
                
                if(countSheep <= countWolf) returnWolf += countWolf; 
                else returnSheep += countSheep;
            }
        }
    }
    cout  << returnSheep << " " << returnWolf;
    return 0;
}
