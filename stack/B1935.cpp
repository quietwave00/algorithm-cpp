/**
 * B1935_후위표기식2
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N; // 피연산자 개수
    cin >> N;

    string str; // 후위표기식
    cin >> str;

    int arr[N]; // 피연산자
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<double> st; // 연산 과정
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') { // 피연산자의 경우
            st.push(arr[str[i] - 'A']);
        } else { // 연산자의 경우 계산 진행
            double num1, num2;
            num2 = st.top();
            st.pop();
            num1 = st.top();
            st.pop();

            if(str[i] == '+') {
                // cout << "num1 + num2: " << num1 + num2 << endl;
                st.push(num1 + num2);
            } else if(str[i] == '-') {
                // cout << "num1 - num2: " << num1 - num2 << endl;
                st.push(num1 - num2);
            } else if(str[i] == '*') {
                // cout << "num1 * num2: " << num1 * num2 << endl;
                st.push(num1 * num2);
            } else if(str[i] == '/') {
                // cout << "num1 / num2: " << num1 / num2 << endl;
                st.push(num1 / num2);
            }
        }
    }
    cout << fixed;
	cout.precision(2);
    cout << st.top() << '\n';

    return 0;
}