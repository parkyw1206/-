#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> network;
vector<int> visited;
int numComputers, count = 0;

void search(int currLocation){
    visited[currLocation] = true;
    count ++;
    for(int i = 1 ; i <= numComputers; i++){
        if(i == currLocation || visited[i]) continue;

        if(network[i][currLocation] == 1)
            search(i);
    }
}

int main(int argc, char** argv)
{
    int pairNetWork, first, second;
    cin >> numComputers;
    cin >> pairNetWork;
    
    for(int i = 0 ; i <= numComputers ; i++){
        network.push_back(vector<int>());
        visited.push_back(false);
        for(int j = 0 ; j <= numComputers ; j++){
            network[i].push_back(0);
        }
    }
    visited[0] = true;
    for(int i = 0 ; i < pairNetWork; i++){
        cin >> first >> second;
        network[first][second] = 1;
        network[second][first] = 1;
    }
    
    search(1);
    cout << count-1;
    return 0;
}
