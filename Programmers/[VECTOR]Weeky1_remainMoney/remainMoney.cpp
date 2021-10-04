using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long payTotal = 0;
    
    for(int i = 1 ; i <= count ; i++){
        payTotal += i *price;
    }
    answer = payTotal - money;
    if(answer < 0) return 0;
    return answer;
}