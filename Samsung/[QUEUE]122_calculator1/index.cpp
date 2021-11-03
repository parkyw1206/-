#include <iostream>
#include <queue>
#include <string> //need this

using namespace std;

int main()
{
    int TEST_CASE = 10, length,sum = 0;
    char temp;
    queue<char> que;
    char op[1] = {'+'};
    for(int i = 0 ; i < TEST_CASE ; i++){
        cin >> length;        
        sum = 0;
        for(int j = 0 ; j < length; j++){
            cin >> temp;
            que.push(temp);
        }
        while(!que.empty()){
            if(int(que.front()) < 58 && int(que.front()) > 47){
                sum += ( int(que.front()) - 48);
            }
            que.pop();
        }
        cout << "#" << i+1 << " " << sum  << endl;
    }

    return 0;
}
