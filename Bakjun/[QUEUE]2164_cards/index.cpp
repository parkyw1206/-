#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    queue<int> cards;
    
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cards.push(i);
    }
    
    while(cards.size() > 1){
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }
    cout << cards.front();
    return 0;
}