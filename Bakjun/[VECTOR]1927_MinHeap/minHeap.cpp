#include <iostream>
#include <queue>
#include<stdio.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N;
priority_queue<int,vector<int>,greater<int>> nums;

int main()
{
    fastio;

    cin >> N;
    for(int i = 0 ; i < N ;i++){
        int temp;
        cin >> temp;
        
        if(temp == 0){
            if(nums.empty()){
                cout << "0\n";
            }
            else{
                cout << nums.top() << "\n";
                nums.pop();
            }
        }
        else{
            nums.push(temp);
        }
    }
    
    return 0;
}
