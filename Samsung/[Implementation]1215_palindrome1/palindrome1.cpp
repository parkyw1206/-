#include <iostream>
#include <vector>

using namespace std;
char puzzle[8][8] = {0,};
int  wordLength, cnt = 0, currentLength;
string currentString;

bool check(string str){
    for(int i = 0 ; i < wordLength/2 ; i++){
        if(currentString[i] != currentString[wordLength-i-1])
            return false;
    }
    return true;
}
void countRows(){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j <= 8 - wordLength ;j++){
            for(int k = j ; k < j + wordLength; k++){
                currentString += puzzle[i][k];   
            }
            if(check(currentString)){
                cnt ++;
            }
            currentString = "";
        }
    }
}
void countCols(){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j <= 8 - wordLength ;j++){
            for(int k = j ; k < j + wordLength; k++){
                currentString += puzzle[k][i];   
            }
            if(check(currentString)){
                cnt ++;
            }
            currentString = "";
        }
    }
}
int main()
{
    int TEST_CASE = 10;
    char temp;
    
    for(int i = 0 ; i < TEST_CASE ; i++){
        cnt = 0;
        cin >> wordLength;
        for(int j = 0 ; j < 8; j++){
            for(int k = 0 ; k < 8; k++){
                cin >> temp;
                puzzle[j][k] = temp;
            }
        }
        countRows();
        countCols();
        cout << "#" << i+1 << " "<<cnt << endl;
    }
    return 0;
}
