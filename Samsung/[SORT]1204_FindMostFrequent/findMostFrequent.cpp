#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int fullScore = 100;
const int studentNum = 1000;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    int T, test_case, temp;
    vector<pair<int,int>> scores;
    cin >> T;
    
    for(int i = 0 ; i < T; i++){
        cin >> test_case;
        scores = {};
        
        for(int j = 0 ; j < fullScore; j++){
            scores.push_back({j,0});
        }
        for(int j = 0 ; j < studentNum ; j++){
            cin >> temp;
            scores[temp].second ++;
        }
        
        sort(scores.begin(), scores.end(), comp);
        cout << "#" << test_case << " " << scores[99].first <<endl;
    }
    return 0;
}
