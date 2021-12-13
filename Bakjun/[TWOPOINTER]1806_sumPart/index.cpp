#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,num;
    long S;
    vector<int> numList;
    
    cin >> N >> S;
    for(int i = 0 ; i < N ; i++){
        cin >> num;
        numList.push_back(num);
    }
    
    int left = 0, right = 0, sum = 0, minLength = 100001;
    while(left <= right && right <= N){
        if(sum < S){
            sum += numList[right++];
        }
        else{
            if(minLength > right - left){
                minLength = right - left;
            }
            sum -= numList[left++];
        }
    }
    if(minLength == 100001)
        cout << 0;
    else
        cout << minLength;
    
    return 0;
}
