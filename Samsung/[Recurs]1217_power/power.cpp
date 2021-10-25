#include <iostream>

using namespace std;
int recurse(int base, int up){
    if(up == 0) return 1;
    return recurse(base,up-1)*base;
}
int main()
{
    int TEST_CASE = 10, cnt, result = 1, base, up;
    for(int i = 0 ; i < TEST_CASE ; i++){
        cin >> cnt;
        cin >> base >> up;
        cout << "#" << cnt << " " << recurse(base, up) << endl;
    }
    return 0;
}
