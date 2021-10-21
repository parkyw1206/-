#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int countUpper,countUnder,countNum, countBlank;
    while(getline(cin,str)){
        countBlank = 0;
        countNum = 0;
        countUnder = 0;
        countUpper = 0;
        for(int i = 0 ; i < str.size(); i++){
            if(isupper(str[i])){
                countUpper++;
            }
            else if(islower(str[i])){
                countUnder++;
            }
            else if(isblank(str[i])){
                countBlank++;
            }
            else if(isdigit(str[i])){
                countNum++;
            }
        }
        cout << countUnder << " " << countUpper << " "  
                << countNum << " " << countBlank << endl;
    }
    return 0;
}
