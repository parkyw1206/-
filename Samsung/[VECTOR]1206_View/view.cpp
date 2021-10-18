#include <iostream>
#include <vector>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int seeHeight(int currHeight, int leftleft, int left, int right, int rightright){
    int temp1, temp2, maxNum;
    
    temp1 = max(leftleft, left);
    temp2 = max(right,rightright);
    maxNum = max(temp1, temp2);
    
    return currHeight - maxNum > 0 ? currHeight - maxNum : 0;
}
int main()
{
    fastio;
    
    int TEST_CASE = 10,T, answer = 0,temp;
    vector<int> buildings;
    
    for(int i = 0 ; i < TEST_CASE ; i++){
        cin >> T;
        answer  = 0;
        buildings={};
        
        for(int j = 0 ; j < T; j++){
            cin >> temp;
            buildings.push_back(temp);
        }
        
        answer += seeHeight(buildings[0], 0,0,buildings[1], buildings[2]);
        answer += seeHeight(buildings[1], 0,buildings[0],buildings[2], buildings[3]);
        for(int j = 2 ; j < T - 2 ; j++){
            answer += seeHeight(buildings[j], buildings[j-2],buildings[j-1],buildings[j+1], buildings[j+2]);
        }
        answer += seeHeight(buildings[T-2], buildings[T-4],buildings[T-3],buildings[T-1], 0);
        answer += seeHeight(buildings[T-1], buildings[T-3],buildings[T-2],0, 0);
        
        cout << "#" << i+1 << " " << answer << endl; 
    }
    
    return 0;
}
