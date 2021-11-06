#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string str1,str2,longStr1,longStr2;
    getline(cin,str1);
    getline(cin,str2);
    for(int i = 0 ; i < 50 ; i++){
        longStr1 += str1;
        longStr2 += str2;
    }
    
    if(longStr1.size() < longStr2.size()){
        if(longStr2.substr(0,longStr1.size()) == longStr1){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else {
        if(longStr1.substr(0,longStr2.size()) == longStr2){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}
