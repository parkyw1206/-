#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv)
{
    int M , N;
    cin >> M >> N;
    vector<int> nums(N+1,0);
    for(int i = 2 ; i <= N; i++){
        nums[i] = i;
    }
    for(int i = 2 ; i*i<= N ; i++){
        if(nums[i] == 0) continue;
        for(int j = 2*i ; j <= N ; j+=i){
            if(nums[j] == 0) continue;
            else nums[j] = 0;
        }
    }
    for(int i = M ; i <= N ; i++){
        if(nums[i] != 0) printf("%d\n", i);
    }
    return 0;
}
