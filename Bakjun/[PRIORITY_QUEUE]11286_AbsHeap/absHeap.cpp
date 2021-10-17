#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct compare{
    bool operator()(int A, int B){
        if(abs(A) != abs(B)){
            return abs(A) > abs(B); 
        }
        else{
            return A > B;
        }    
    }
};
int main()
{
    int N, temp;
    priority_queue<int,vector<int>, compare> nums;
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        if(temp == 0){
            if(nums.empty()) printf("%d\n",0);
            else{
                printf("%d\n",nums.top());
                //cout << nums.top() << endl;
                nums.pop();                
            }
        }
        else{
             nums.push(temp); 
        }        
    }
    
    return 0;
}
