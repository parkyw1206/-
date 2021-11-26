#include <iostream>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;

map<string,int> dictionary;
priority_queue<string,vector<string>,greater<string>> sortedWords;
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int count = 0, wordSize;
    float ratio;
    string word;
    
	while(getline(cin,word)){
        if(dictionary[word] == 0){
            sortedWords.push(word);
            dictionary[word] = 1;
        }
        else{
            dictionary[word]++;
        }
	    count++;
	}
	
	wordSize = sortedWords.size();
	
    cout << fixed << setprecision(4);
	for(int i = 0 ;  i < wordSize ; i++){
	    ratio = dictionary[sortedWords.top()] * 100.0 / count ;
	    
	    cout << sortedWords.top() << " " << ratio << endl;
	    sortedWords.pop();
	}
    return 0;
}
