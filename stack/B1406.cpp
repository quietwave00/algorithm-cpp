/**
 * B1406_에디터
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> st;
stack<char> temp;

int main() {
    cin >> str;
    int n;
    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }

    cin >> n;
    while(n--) {
        char command;
        cin >> command;
        if(command == 'P') {
            char c;
            cin >> c;
            st.push(c);
        }
        else if(command == 'L') {
            if(st.empty()) // 무시
                continue;
            else {
                temp.push(st.top());
                st.pop();
            }
        }
        else if(command == 'B') {
            if(st.empty()) // 무시
                continue;
            else {
                st.pop();
            }
        }
        else if(command == 'D') {
            if(temp.empty()) // 무시
                continue;
            else {
                st.push(temp.top());
                temp.pop();
            }
        }
    }
    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    
    while(!temp.empty()) { // 역순 출력
        cout << temp.top();
        temp.pop();
    }
    
    return 0;
}