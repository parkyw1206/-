#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,K, temp, returnCoin = 0;
    vector<int> coinVari;
    cin >> N >> K;
    
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        coinVari.push_back(temp);
    }
    
    for(int i = N-1 ; i >= 0; i--){
        if(coinVari[i] <= K){
            returnCoin += K / coinVari[i];
            K %= coinVari[i];
        }
    }
    cout << returnCoin;
    return 0;
}
