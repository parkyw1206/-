#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    int totalCard;
    queue<int> card;

    cin >> totalCard;
    for(int i = 1 ; i <= totalCard ; i++){
        card.push(i);
    }
    while(card.size() > 1){
        cout << card.front() << " ";
        card.pop();
        card.push(card.front());
        card.pop();
    }
    cout << card.front();
    return 0;
}
