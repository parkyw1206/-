#include <iostream>

using namespace std;

int main()
{
    int n,remain = 0,countCoins = 0;
    
    cin >> n;
    int modFive = n % 5;
    
    if(n == 1 || n == 3){
        countCoins = -1;
    }
    else if(modFive % 2 == 0){
        countCoins = n / 5 + (n % 5) / 2;
    }
    else{
        countCoins = n / 5;
        n %= 5;
        
        countCoins += (n+5) / 2 -1;
        n %= 2;        
    }

    
    cout << countCoins;
    return 0;
}
