#include <iostream>

using namespace std;
bool isPrime(int n) { 
    if (n < 2) return false; 
    for (int i = 2; i * i <= n; i++) 
    { 
        if (n % i == 0) 
        { 
            return false; 
        } 
    } 
    return true;
}

int main()
{
    int T,n,left;
    
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        cin >> n;
        
        left = n/2;
        while(left > 0){
            while(!isPrime(left)){
                left--;
            }
            if(isPrime(n - left)){
                printf("%d %d\n",left, n-left);
                break;
            }
            left--;
        }
    }
    return 0;
}
