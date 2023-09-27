#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;


int main(void) {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int num;
        cin >> num;
        int arr[num + 1];
        //초기화
        for(int i = 1; i <= num; i++) {
            arr[i] = i;
        }

        //소수 찾기
        for(int i = 2; i <= num; i++) {
            if(arr[i] == 0) continue;
            for(int j = i + i; j <= num; j += i) {
                if(arr[j] != 0) arr[j] = 0;
            }
        }

        vector<int> prime; 
        for(int i = 2; i <= num; i++) {
            if(arr[i] != 0) {
                prime.push_back(arr[i]);
            }
        }
        
        for(int value : prime) {
            cout << value << " ";
        }
        
        vector<int> result;
        int min = INT_MAX;
        for(int i = 0; i < prime.size(); i++) {
            for(int j = i + 1; j < prime.size(); j++) {
                if(prime[i] + prime[j] == num) {
                    int minus = abs(prime[i] - prime[j]);
                    cout << "minus: " << minus << endl;
                    if(minus < min) {
                        cout << "enter" << endl;
                        min = minus;
                        result.clear();
                        result.push_back(prime[i]);
                        result.push_back(prime[j]);
                    }
                }
            }
        }
        //출력
        cout << result[0] << " " << result[1] << endl;
    }
}

// 8: 3, 5
// 10: 5, 5
// 16: 5, 11
// num까지의 수에서 소수를 찾아야함 정렬하고 작은 거부터 더하기 해서 해당되는 거 출력