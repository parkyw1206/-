#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int TEST_CASE = 10;
const int WIDTH = 100;
int main()
{
    int temp, dump;
    vector<int> buildings;
    
    for(int i = 0 ; i < TEST_CASE ; i++){
        cin >> dump;
        buildings = {};
        for(int j = 0 ; j < WIDTH ; j++){
            cin >> temp;
            buildings.push_back(temp);
        }
        sort(buildings.begin(), buildings.end());
        for(int j = 0 ; j < dump;j++){
            buildings[0]++;
            buildings[WIDTH-1]--;
            sort(buildings.begin(), buildings.end());

        }
        cout << "#" << i+1 << " " << buildings[WIDTH-1] - buildings[0] << endl;
    }
    return 0;
}
