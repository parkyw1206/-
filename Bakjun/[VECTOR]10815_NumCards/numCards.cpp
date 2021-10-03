#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N,M,temp;
    vector<int> myCards, yourCards;
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        myCards.push_back(temp);
    }
    
    cin >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> temp;
        yourCards.push_back(temp);
    }
    sort(myCards.begin(), myCards.end());
    for(int i = 0 ; i < M ; i++){
        if(binary_search(myCards.begin(), myCards.end(),yourCards[i])){
            cout << 1;
        }
        else{
            cout << 0;
        }
        if(i < M - 1)  cout << " ";
    }
    return 0;
}
