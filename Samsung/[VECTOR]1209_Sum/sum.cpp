#include <iostream>

using namespace std;

int main()
{
    int TEST_CASE = 1,T,nums[100][100], maxNum = -1,sum = 0;
    for(int i = 0 ; i < TEST_CASE ; i++){
        cin >> T;
        maxNum = -1;
        for(int j = 0 ; j < 100; j++){
            sum = 0;
            for(int k = 0 ; k < 100 ; k++){
                cin >> nums[j][k];
                sum += nums[j][k];
            }
            if(sum > maxNum){
                maxNum = sum;
            }
        }
        for(int j = 0; j < 100; j++){
            sum = 0;
            for(int k = 0 ; k < 100; k++){
                sum += nums[k][j];
            }
            if(sum > maxNum){
                maxNum = sum;
            }
        }
        sum = 0;
        for(int i = 0 ; i < 100; i++){
            sum += nums[i][i];
        }
        if(sum > maxNum){
            maxNum = sum;
        }
        sum = 0;
        for(int i = 0 ; i < 100; i++){
            sum += nums[i][100-i-1];
        }
        if(sum > maxNum){
            maxNum = sum;
        }
        cout << maxNum << endl;
    }
    return 0;
}
