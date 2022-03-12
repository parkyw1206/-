#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int minNum = 10000000000, index = -1;
    
    for(int i = 0 ; i < answer.size(); i++){
        if(answer[i] < minNum){
            minNum = answer[i];
            index = i;
        }
    }
    if(index != -1)
        answer.erase(answer.begin()+index);

    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}