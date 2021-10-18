#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    int N, count = 0;
    
    cin >> N;
    
    while(N % 5 != 0){
        if(N < 3){
            cout << -1;
            return 0;
        }
        N -= 3;
        count ++;
    }
    count += N / 5;
    
    cout << count;
    return 0;
}
