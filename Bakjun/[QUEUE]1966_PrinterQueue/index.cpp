#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int T,N,M,pri,count;
    queue<pair<int,int>> printer;
    priority_queue<int> prios;
    cin >> T;
    for(int i = 0 ; i < T; i++){
        cin >> N >> M;
        count = 1;
        for(int j = 0 ; j < N; j++){
            cin >> pri;
            printer.push({pri,j});
            prios.push(pri);
        }
        while(!printer.empty()){
            if(printer.front().first == prios.top() && printer.front().second == M){
                printer = queue<pair<int,int>> ();
                prios = priority_queue<int> ();
                cout << count << endl;
                break;
            }

            if(printer.front().first == prios.top()){
                printer.pop();
                prios.pop();
                count++;
            }
            else{
                printer.push(printer.front());
                printer.pop();
            }
        }
    }
    return 0;
}
