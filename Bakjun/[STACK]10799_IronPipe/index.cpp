#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    char oneStr;
    int curr = 0, count = 0;
    stack<int> arrows;
    
    while(cin >> oneStr){
        if(oneStr == '('){
            arrows.push(curr);
        }
        else if(arrows.top() == curr - 1){
            arrows.pop();
            count += arrows.size();
        }
        else{
            count += 1;
            arrows.pop();

        }
        curr++;
    }
    cout << count << endl;
    return 0;
}
