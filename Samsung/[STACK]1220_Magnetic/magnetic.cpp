#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N, TEST_CASE = 10,temp,count=0;
    vector<vector<int>> arr;
    stack<int> micro;
    for(int m = 0 ; m < TEST_CASE ; m++){
        cin >> N;
        count = 0 ;
        arr.clear();
        for(int i = 0 ; i < 100 ; i++){
            arr.push_back(vector<int>());
            for(int j = 0 ; j < 100 ; j++){
                cin >> temp;
                arr[i].push_back(temp);
            }
        }
        for(int j = 0 ; j < 100; j++){
            for(int i = 0 ; i < 100; i++){
                if(arr[i][j] == 1){
                    if(!micro.empty() && micro.top() == 2){
                        count++;
                        micro.pop();
                    }
                    else if(!micro.empty() && micro.top() == 1){
                        continue;
                    }
                    else {
                        micro.push(1);
                    }
                }
                else if(arr[i][j] == 2){
                    if(!micro.empty() && micro.top() == 1){
                        count++;
                        micro.pop();
                    }
                    else if(!micro.empty() &&micro.top() != 2){
                        micro.push(2);
                    }
                }
            }
            micro = stack<int>();
        }
        cout << "# " << m+1 << " " <<  count<< endl;

    }
    return 0;
}
