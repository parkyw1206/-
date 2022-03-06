#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> waringList;
    map<string, int> warningCount, reportCount;
    
    string reporter = "", reportee = "";
    
    
    for(int i = 0 ; i < report.size() ; i++){
        int loc = report[i].find( " ", 0 );
        reporter = report[i].substr(0,loc);
        reportee =  report[i].substr(loc+1);
        if(find(waringList[reportee].begin(), waringList[reportee].end(), reporter) == waringList[reportee].end()){
            waringList[reportee].push_back(reporter);
            warningCount[reportee]++;            
        }
    }
    for(int i = 0 ; i < id_list.size() ; i++){
        if(warningCount[id_list[i]] >= k){
            for(int j = 0 ; j <waringList[id_list[i]].size() ; j++){
                reportCount[waringList[id_list[i]][j]]++;
            }
        }
    }
    for(int i = 0 ; i < id_list.size() ; i++){
        answer.push_back(reportCount[id_list[i]]);
    }
    return answer;
}