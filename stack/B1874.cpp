/**
 * B1874_스택 수열
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;
    
    stack<int> st;
    vector<char> result;
    int push_num = 1; // 스택에 넣을 수
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        while(push_num <= temp) {
            // cout << "push" << endl;
            st.push(push_num);
            push_num++;
            result.push_back('+');
        }
        
        if(st.top() == temp) {
            // cout << "pop" << endl;
            st.pop();
            result.push_back('-');
        } else { // 스택에 해당 값이 없으면 수열을 만들어낼 수가 없음
            cout << "NO" << '\n';
            return 0; // 종료
        }
    }
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}
