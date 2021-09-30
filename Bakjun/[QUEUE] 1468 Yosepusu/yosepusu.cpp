/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    int N, K;
    cin >> N >> K;
    queue<int> person;
    for(int i = 1 ; i <= N ; i++){
        person.push(i);
    }
    
    cout << "<";
    while(person.size() > 1){
        for(int i = 0 ; i < K -1 ; i++){
            person.push(person.front());
            person.pop();
        }
        cout << person.front() << ", ";
        person.pop();
    }
    cout << person.front() << ">" ;
    return 0;
}
