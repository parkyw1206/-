#include <iostream>
#include <queue>

using namespace std;

int T, count = 0;

void takesTime(int timePer){
    if(T >= timePer){
        T -= timePer;
        count ++;
        takesTime(timePer);
    }
    
}
int main()
{
    vector<int> counts;
    bool countChange = false;
    cin >> T;
    
    takesTime(300);
    counts.push_back(count);

    count = 0;
    takesTime(60);
    counts.push_back(count);

    count = 0;
    takesTime(10);
    counts.push_back(count);

    if(T == 0){
        printf("%d %d %d", counts[0], counts[1], counts[2]);
    }
    else{
        cout << -1;
    }
    return 0;
}