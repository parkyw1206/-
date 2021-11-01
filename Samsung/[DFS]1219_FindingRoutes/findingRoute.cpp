#include <iostream>
#include <vector>
using namespace std;

bool successGoal = false;
int graph[100][100] = {0};
bool visited[100]= {false};

void search(int curr){
    visited[curr] = true;
    if(curr == 99){
        successGoal = true;
        return;
    }
    
    for(int i = 0 ; i < 100; i++){
        if(graph[curr][i] == 1 && !visited[i]){
            search(i);
        }
    }
}
int main()
{
    
    int test_case = 1, num, V,from,to;
    for(int i  = 0; i < test_case; i++){
        for(int j = 0 ; j < 100 ; j ++){
            visited[j] = false;
            for(int k = 0 ; k < 100 ; k++){
                graph[j][k] = 0;
            }
        }
        
        cin >> num >> V;
        for(int j = 0 ; j < V; j++){
            cin >> from >> to;
            graph[from][to] = 1;
        }
        
        successGoal= false;
        search(0);
        
        if(successGoal == true)
            cout << "#" << num << " 1" <<endl;
        else
            cout << "#" << num << " 0" <<endl;
    }
    return 0;
}
