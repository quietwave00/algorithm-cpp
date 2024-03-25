#include <iostream>
using namespace std;

int weight[101];
int value[101];
int d[101][100001];
int main(){
    int N,K;
    cin >> N >> K;

    for(int i = 1; i<=N; i++){
        cin >> weight[i];
        cin >> value[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= K; j++){
            if(j >= weight[i]) {
                d[i][j] = max(d[i-1][j], d[i-1][j-weight[i]]+value[i]);
            } 
            else d[i][j] = d[i-1][j];
        }
    }
    cout << d[N][K];
}