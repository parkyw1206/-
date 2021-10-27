#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int arr[10001] = {0,};
bool visited[10001] = {0,};
vector<int> nums;
void search(int cnt){
    if(cnt == m){
        for(int i = 0 ; i < m ; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[nums[i]]){
            visited[nums[i]] = true;
            arr[cnt] = nums[i];
            search(cnt+1);
            visited[nums[i]] = false;
        }
    }
}
int main()
{
    int temp;
    
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    search(0);
    return 0;
}
