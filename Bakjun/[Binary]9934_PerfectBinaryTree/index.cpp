#include <iostream>
#include <vector>

using namespace std;

vector<int> answer[11];
vector<int> nums;
    
void search(int s, int e, int depth){
    
    if(s == e) {
        answer[depth].push_back(nums[s]);
        return;
    }
    
    int mid = (e+s)/2;
    answer[depth].push_back(nums[mid]);
    
    search(s, mid-1, depth+1);
    search(mid+1, e, depth+1);
}
int main()
{
    int K,temp;
    cin >> K;
    
    while(cin >> temp){
        nums.push_back(temp);
    }
    search(0,nums.size()-1,0);
    for(int i = 0 ; i < K ; i++){
        for(int j = 0 ; j < answer[i].size(); j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
