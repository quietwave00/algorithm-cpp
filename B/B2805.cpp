#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 4 7
// 20 15 10 17
int N, M, answer;
vector<int> H;

//시간초과
// int main(void) {
//     /*
//      * 입력
//      */
//     cin >> N >> M;

//     for (int i = 0; i < N; i++) {
//         int h;
//         cin >> h;
//         H.push_back(h);
//     }

//     /*
//      * 연산
//      */
//     sort(H.begin(), H.end());
//     int target = H[H.size() / 2];
//     while(target != 0) {
//         vector<int> minus(N);
//         for(int j = 0; j < N; j++) {
//             if(H[j] > target) {
//                 minus[j] = H[j] - target;
//             }
//         }

//         int sum = 0;
//         for(int k = 0; k < N; k++) {
//             sum += minus[k];
//         }
//         if(sum == M) {
//             cout << target;
//             break;
//         }
//         target--;
//     }
// }

int main(void) {
    /*
     * 입력
     */
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        H.push_back(h);
    }
    
    sort(H.begin(), H.end());
    int low, mid = 0;
    int high = H.back();
    while(low < high) {
        mid = (low + high) / 2;
        int count = 0;
        for(int h : H) {
            if(h - mid > 0) {
                count += h - mid;
            }
        }

        if(count < M) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low - 1 << endl;   
}
