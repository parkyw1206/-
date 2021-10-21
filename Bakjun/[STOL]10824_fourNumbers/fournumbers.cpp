#include <iostream>
#include <string>

using namespace std;

int main()
{
    int A,B,C,D;
    string str1="",str2="";
    cin >> A>>B>>C>>D;
    
    str1 = to_string(A) + to_string(B);
    str2 = to_string(C) + to_string(D);
    
    cout << stoll(str1)+stoll(str2);
    return 0;
}
