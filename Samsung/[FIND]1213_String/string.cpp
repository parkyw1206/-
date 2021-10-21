#include <iostream>
#include <string>
using namespace std;

int main()
{
    int TEST_CASE=10,T,pos=0,curr=0,count = 0;
    string searchString,wholeSentence;
    for(int i = 0 ; i < TEST_CASE; i++){
        count = 0;
        cin >> T;
        cin.ignore();
        getline(cin,searchString);
        getline(cin,wholeSentence);
        pos=wholeSentence.find(searchString);
        while(pos != string::npos){
            count ++;
            pos=wholeSentence.find(searchString,pos+1);
        }
        cout << "#"<< T << " " << count  << endl;
    }
    return 0;
}
