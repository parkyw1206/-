#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t,n;
    string temp;
    vector<string> nums;
    
    cin >> t;
    
    for(int i = 0 ; i < t ; i++){
        cin >> n;

        for(int j = 0 ; j < n; j++){
            cin >> temp;
            nums.push_back(temp);
        }
        sort(nums.begin(), nums.end());
        for(int j = 0 ; j < n-1 ; j++){
            string string1 = nums[j+1];
            string string2 = nums[j];
            int pos = string1.find(string2);
            
            if(pos == 0){
                cout << "NO" << endl;
                j = n;
            }
            else if(j == n-2){
                cout << "YES" << endl;
            }
        }
        nums.clear();

    }
    
    return 0;
}
