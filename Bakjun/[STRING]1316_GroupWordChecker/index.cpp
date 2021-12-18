#include <iostream>
#include <map>

using namespace std;

int main()
{
    int T,countSuccess=0;
    map<int,int> words;
    bool checkSuccess = true;
    string str;
    char currChar;
    
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> T;
    
    cin.ignore();
    for(int i = 0 ; i < T; i++){
        getline(cin,str);
        checkSuccess = true;
        for(int j = 0 ; j < str.size() ; j++){
            if(words[str[j]] == 0){
                words[str[j]]++;
                currChar = str[j];
            }
            else if(words[str[j]] > 0 && currChar != str[j]){
                checkSuccess = false;
                break;
            }
        }
        if(checkSuccess) countSuccess++;
        words.clear();
    }
    cout << countSuccess;
    return 0;
}
