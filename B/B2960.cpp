// #include <iostream>
// using namespace std;

// int main(void) {
//     int N, K;
//     cin >> N >> K;
//     int arr[N + 1];

//     // 초기화
//     for (int i = 2; i <= N; i++) {
//         arr[i] = i;
//     }

//     int count = 0;
//     for (int i = 2; i <= N; i++) {
//         if (arr[i] == 0) continue;
//         for (int j = i; j <= N; j += i) {
//             if (arr[j] != 0) {
//                 arr[j] = 0;
//                 count++;
//                 if (count == K) {
//                     cout << j << endl;
//                     return 0;
//                 }
//             }
//         }
//     }
// }
