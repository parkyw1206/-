#include <iostream>
#include <cstring>


using namespace std;

int nums[10] = {0};
const char* constNum[10] = {"ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN"};

int main()
{
    int TEST_CASE, wordCount;
    string tempStr;

    cin >> TEST_CASE;
    for(int i = 0 ; i < TEST_CASE ; i++){
        cin.ignore();
        getline(cin, tempStr);
        wordCount = stoi(tempStr.substr(tempStr.find(' ')+1));
        for(int j = 0 ; j < wordCount; j++){
            getline(cin, tempStr, ' ');
            for(int k = 0 ; k < 10; k++){
                if(strcmp(tempStr.c_str(),constNum[k]) == 0){
                    nums[k]++;
                    k=wordCount;
                }                
            }

        }
        cout << "#" << i+1<< endl;
        for(int j = 0 ; j < 10; j++){
            for(int k = 0; k < nums[j] ; k++){
                cout << constNum[j] << " ";
            }
            nums[j] = 0;
        }
        cout << endl;
    }
    return 0;
}
