#include <iostream>

using namespace std;

int main()
{
    string order;
    char dumpChar;
    int cups[3] = {1,0,0};
    
    getline(cin, order);
    
    for(int i = 0 ; i < order.size() ; i++){
        if(order[i] == 'A'){
            dumpChar = cups[1];
            cups[1] = cups[0];
            cups[0] = dumpChar;
        }
        else if(order[i] == 'B'){
            dumpChar = cups[2];
            cups[2] = cups[1];
            cups[1] = dumpChar;
        }else{
            dumpChar = cups[2];
            cups[2] = cups[0];
            cups[0] = dumpChar;
        }
    }
    if(cups[0] == 1) cout << 1;
    else if(cups[1] == 1) cout << 2;
    else cout << 3;
    
    return 0;
}
