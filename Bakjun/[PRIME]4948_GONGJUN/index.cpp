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
    int N,count=0;
    
    while(cin >> N && N != 0){
        count = 0;
        for(int i = N+1 ; i <= 2*N ; i++){
            if(isPrime(i)) count++;
        }
        cout << count << '\n';
    }
    return 0;
}
