#include <iostream>
#include <vector>

using namespace std;
char puzzle[100][100] = {0,};
int  wordLength = 1, cnt = 0, maxLength = 0, currentLength;
string currentString;
bool requireCalc = false;

bool check(string str){
    for(int i = 0 ; i < wordLength/2 ; i++){
        if(currentString[i] != currentString[wordLength-i-1])
            return false;
    }
    return true;
}
void countRows(){
    if(requireCalc) return;
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j <= 100 - wordLength ;j++){
            for(int k = j ; k < j + wordLength; k++){
                currentString += puzzle[i][k];   
            }
            if(check(currentString)){
                if(maxLength < wordLength){
                    maxLength = wordLength;
                    requireCalc = true;
                    return;
                }
            }
            currentString = "";
        }
    }
}
void countCols(){
    if(requireCalc) return;
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j <= 100 - wordLength ;j++){
            for(int k = j ; k < j + wordLength; k++){
                currentString += puzzle[k][i];   
            }
            if(check(currentString)){
                if(maxLength < wordLength){
                    maxLength = wordLength;
                    requireCalc = true;
                    return;
                }
            }
            currentString = "";
        }
    }
}
int main()
{
    int TEST_CASE = 10,tempNum;
    char temp;
    
    for(int i = 0 ; i < TEST_CASE ; i++){
        cnt = 0;
        maxLength=0;
        cin >> tempNum;
        for(int j = 0 ; j < 100; j++){
            for(int k = 0 ; k < 100; k++){
                cin >> temp;
                puzzle[j][k] = temp;
            }
        }
        for(wordLength = 1 ; wordLength < 100 ; wordLength++ ){
            requireCalc = false;
            countRows();
            countCols();            
        }
        cout << "#" << i+1 << " "<<maxLength << endl;
    }
    return 0;
}
