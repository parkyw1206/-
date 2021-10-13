#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N,temp, mult = 0, minMul = 10000;
    vector<int> aRow, bRow;
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        aRow.push_back(temp);
    }
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        bRow.push_back(temp);
    }
    
    sort(aRow.begin(), aRow.end(),greater<int>());
    sort(bRow.begin(), bRow.end());
    for(int i = 0 ; i < N ; i++){
        mult += aRow[i] * bRow[i];
    }
    // do{
    //     mult = 0;
        
    //     for(int i = 0 ; i < N ; i++){
    //         if(minMul < mult) continue;
    //         mult += aRow[i] * bRow[i];
    //     }
        
    //     if(minMul > mult) minMul = mult;
        
    // }while(next_permutation(aRow.begin(), aRow.end()));
    
    cout<<mult;

    return 0;
}
