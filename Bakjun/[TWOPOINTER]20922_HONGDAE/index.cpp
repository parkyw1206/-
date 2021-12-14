#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int N,K,num;
    vector<int> numList;
    map<int,int> numCheckList;
    
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
        cin >> num;
        numList.push_back(num);
    }
    
    int left = 0 , right = 0 ,maxLength = 0;
    
    while(left <= right && right < N){
        if(numCheckList[numList[right]] < K){
            numCheckList[numList[right]]++;
            right++;
            if(maxLength < right - left){
                maxLength = right - left;
            }
        }
        else{
            while(numList[left] != numList[right]){
                numCheckList[numList[left++]]--;
            }
            numCheckList[numList[left++]]--;
        }
        
        if(right == N-1 && left == right){
            break;
        }
    }
    cout << maxLength;
    return 0;
}
