#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int addPeople(int N , int K){
    if(N == 0) return K;
    if(K == 1) return 1;
    if(N > 0) {
        return addPeople(N-1,K) + addPeople(N,K-1);
    }
}
int main(int argc, char** argv)
{
    int N,K;
    int TEST_CASE;
    cin >> TEST_CASE;
    
    for(int i = 0 ; i < TEST_CASE;i++){
        cin >> N >> K;
        cout << addPeople(N,K) << endl;
    }
    
    
    return 0;
}

