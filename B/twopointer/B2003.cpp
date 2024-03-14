#include <iostream>
#include <vector>

using namespace std;


int main() {

    int N, M; // 크기, 합
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
        

    int L = 0;
    int R = 0;
    int sum = A[0];

    int answer = 0;
    while(R < N) {
        if(sum < M) { // 합이 작으면 오른쪽 포인터 이동
            R++;
            if(R < N) {
                sum += A[R];
            }
        }
        else if(sum > M) { // 합이 크면 왼쪽 포인터 이동
            sum -= A[L];
            L++;
        }
        else if(sum == M) { // 합이 같으면 두 포인터 모두 이동
            sum -= A[L];
            L++;
            R++;
            if(R < N) {
                sum += A[R];
            }
            answer++;
        }
    }

    cout << answer << endl;
}
