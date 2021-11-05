#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long nums, result;
    cin >> nums;
    result = sqrt(nums);
    if(nums > result*result) result++;
    cout << result << endl;
    return 0;
}
