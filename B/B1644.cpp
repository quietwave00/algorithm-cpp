#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    int arr[N + 1];
    
    //초기화
    for(int i = 1; i <= N; i++) {
        arr[i] = i;
    }


    //소수 찾기
    for(int i = 2; i <= N; i++) {
        if(arr[i] == 0) continue;
        for(int j = i + i; j <= N; j += i) {
            if(arr[j] != 0) arr[j] = 0;
        }
    }
    vector<int> prime;
    for(int i = 2; i <= N; i++) {
        if(arr[i] != 0) {
            prime.push_back(arr[i]);
        }
    }

    //연속된 소수 찾기
    int count = 0;
    int n = prime.size();
    for (int start = 0; start < n; ++start) {
        int currentSum = 0;
        for (int end = start; end < n; ++end) {
            currentSum += prime[end];
            if (currentSum == N) {
                count++;
            }
        }
    }
    cout << count << endl;
}

//20: 0
//3: 1
//41: 3
//53: 2