#include <iostream>

using namespace std;

int main()
{
    int N,alphabet[26] = {0,},countAlpha = 0;
    string str;
    
    cin >> N;
    cin.ignore();
    
    getline(cin,str);
    
    int left = 0, right = 0 , maxLength = 0;
    while(left <= right && right < str.size()){
        if(alphabet[str[right]-97] == 0){
            if(countAlpha < N){
                alphabet[str[right++]-97]++;
                countAlpha++;
                if(maxLength < right - left ){
                    maxLength = right - left;
                }
            }
            else{
                while(alphabet[str[left]-97] > 0){
                    alphabet[str[left]-97]--;
                    if(alphabet[str[left]-97] > 0) left++;
                    else {
                        left++;
                        break;};
                }
                countAlpha--;
            }
        }
        else{
            alphabet[str[right++]-97]++;
        }
        if(maxLength < right - left ){
            maxLength = right - left ;
        }


    }
    cout << maxLength;
    return 0;
}
