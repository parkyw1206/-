#include <iostream>
#include <vector>

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
    long N;
    vector<long> primes;
    cin >> N;
    
    for(long i = 2 ; i <= N ; i++){
        if(isPrime(i)){
            primes.push_back(i);
        }    
    }
    
    long cnt = 0, high = 0, low = 0, sum = 0;
    
    while(1){
        if(sum >= N)
            sum -= primes[low++];
        else if(high == primes.size()) break;
        else 
            sum += primes[high++];
        if(sum == N) cnt++;
    }
    cout << cnt;
    return 0;
}
