#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
    long M,sum,material,count = 0;
    vector<long> materials;
    map<long,bool> matSet;
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        cin >> material;
        materials.push_back(material);
        matSet[material] = true;
    }
    sort(materials.begin(), materials.end());
    for(int i = 0 ; i < N ; i++){
        if(matSet[M-materials[i]]) count++;
    }
    materials.clear();
    cout << count/2;
    return 0;
}
