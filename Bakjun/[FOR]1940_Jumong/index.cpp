#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    long M,sum,material,count = 0;
    vector<long> materials;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> material;
        materials.push_back(material);
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = i+1; j < N ; j++){
            if(materials[i]+materials[j] == M)
                count++;
        }
    }
    cout << count;
    return 0;
}
