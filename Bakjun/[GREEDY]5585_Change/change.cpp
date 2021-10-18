#include <iostream>

using namespace std;

int count = 0, change;
void payby(int currMoney){
    if(change >= currMoney){
        count++;
        change -= currMoney;
        payby(currMoney);
    }
}
int main()
{
    int money;
    cin >> money;
    change = 1000 - money;
    payby(500);
    payby(100);
    payby(50);
    payby(10);
    payby(5);
    payby(1);
    cout << count <<endl;
    return 0;
}
