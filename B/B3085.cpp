#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int max_count = 0;
vector<vector<char>>  vec;
void candy_count();

int main() {
    // 입력
    cin >> N;
    vec.resize(N + 1, vector<char>(N + 1));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> vec[i][j];
        }
    }

    // 행 기준 체크
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            swap(vec[i][j], vec[i][j + 1]); // 좌우 스왑
            candy_count();
            swap(vec[i][j], vec[i][j + 1]); // 원복
        }
    }

    // 열 기준 체크
    for(int j = 0; j < N; j++) {
        for(int i = 0; i < N - 1; i++) {
            swap(vec[i][j], vec[i + 1][j]); // 상하 스왑
            candy_count();
            swap(vec[i][j], vec[i + 1][j]); //원복
        }
    }

    cout << max_count << '\n';

    return 0;
}

void candy_count() {
    // 행 체크
    for(int i = 0; i < N; i++) {
        int count = 1; // 캔디 하나부터
        for(int j = 0; j < N; j++) {
            if(vec[i][j] == vec[i][j + 1]) { // 좌우 같으면
                count++;
            } else {
                if(count > max_count) max_count = count;
                count = 1; // else문 들어온 건 같지 않다는 뜻이니까 이어지지 않은 거임, count = 1로 리셋
            }
        }
    }

    // 열 체크
    for(int j = 0; j < N; j++) {
        int count = 1;
        for(int i = 0; i < N; i++) {
            if(vec[i][j] == vec[i + 1][j]) { // 상하 같으면
                count++;
            } else {
                if(count > max_count) max_count = count;
                count = 1;
            }
        }
    }
}