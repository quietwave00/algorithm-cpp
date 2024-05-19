/**
 * B1676_팩토리얼 0의 개수
*/
#include <iostream>

using namespace std;


int main() {    
    int N;
    cin >> N;

    int count = 0;
    while(N >= 5) { // N이 5로 나누어지는 경우까지만 
        count += N / 5; // 나누고 카운트 값
        N /= 5; // 나누기
    }

    cout << count << '\n';

    return 0;
}