#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> pyramid;
    int N, temp, maxNum = 0;
    priority_queue<int> nums;
    
    cin >> N;
    
    for(int i = 0 ; i < N; i++){
        pyramid.push_back(vector<int>());
        for(int j = 0; j <= i; j++){
            cin >> temp;
            pyramid[i].push_back(temp);
        }
    }
    if(N == 1){
        cout << pyramid[0][0];
        return 0;
    }

    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j == 0)
                pyramid[i][j] += pyramid[i-1][j];
            else if(j == i)
                pyramid[i][j] += pyramid[i-1][j-1];
            else
                pyramid[i][j] += max(pyramid[i-1][j-1] ,pyramid[i-1][j]);
        }
    }
    for(int i = 0 ; i <N ; i++){
        if(maxNum < pyramid[N-1][i]){
            maxNum = pyramid[N-1][i];
        }
    }
    cout << maxNum;
    return 0;
}
