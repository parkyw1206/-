#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            printf(" ");
        }
        for(int j = 2*(N-i) -1 ; j > 0 ;j--){
            printf("%c",'*');
        }
        printf("\n");
    }
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < N-i -1 ; j++){
            printf(" ");
        }
        for(int j = 0 ; j < 2*i + 1 ;j++){
            printf("%c",'*');
        }
        printf("\n");
    }
    return 0;
}
