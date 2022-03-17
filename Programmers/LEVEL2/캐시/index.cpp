#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

string toLowerCase(string city){
    string answer = "";
    
    for(int i = 0 ; i < city.size() ; i++){
        if(isupper(city[i])){
            answer += tolower(city[i]);
        }
        else{
            answer += city[i];
        }
    }
    
    return answer;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cityQue;
    
    for(int i = 0 ; i < cities.size() ; i++){
        string city = toLowerCase(cities[i]);
        auto searchResult = find(cityQue.begin(), cityQue.end(),city);
        if(searchResult != cityQue.end()){
        answer++;
        cityQue.erase(searchResult);
        }
        else if(cityQue.size() == cacheSize && cacheSize != 0){
        answer+=5;
        cityQue.erase(cityQue.begin());
        }
        else{
        answer+=5;
        }
        if(cacheSize != 0){
            cityQue.push_back(city);
        }

    }
    return answer;
}