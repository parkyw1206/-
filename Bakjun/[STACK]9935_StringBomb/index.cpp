#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str,bomb;
    char strResult[1000001];
    int loc,idx = 0;
    
    getline(cin, str);
    getline(cin, bomb);

    for(int i = 0 ; i < str.length() ; i++){
        strResult[idx++] = str[i];
        if(strResult[idx - 1] == bomb[bomb.size()-1]){
            if(idx - bomb.size() < 0) continue;
            
            bool detected = true;
            for(int j = 0 ; j < bomb.size(); j++){
                if(strResult[idx-j-1] != bomb[bomb.size() - j - 1]){
                    detected = false;
                    break;
                }
            }
            if(detected) idx -= bomb.size();
        }
    }
    if(idx == 0){
        cout << "FRULA";
    }
    else{
        for(int i = 0;i < idx ; i++){
            cout << strResult[i];
        }
    }
    return 0;
}
