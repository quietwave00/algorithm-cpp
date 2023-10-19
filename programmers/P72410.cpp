#include <string>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;

string step1(string id);
string step2(string id);
string step3(string id);
string step4(string id);
string step5(string id);
string step6(string id);
string step7(string id);


// 소문자로
string step1(string id) {
    for(char &c : id) {
        c = tolower(c);
    }
    // cout << "step1: " << id << endl;
    return step2(id);
}

// 소문자, 숫자, -, _, .만 허용
string step2(string id) {
    regex pattern("[^a-z0-9-_.]+");
    id = regex_replace(id, pattern, "");
    // cout << "step2: " << id << endl;
    return step3(id);
}

// 점 2개이상 연속 -> 하나로
string step3(string id) {
    regex pattern("\\.+");
    id = regex_replace(id, pattern, ".");
    // cout << "step3: " << id << endl;
    return step4(id);
}

// 점 처음, 끝에 있으면 제거
string step4(string id) {
    if(id[0] == '.') id = id.substr(1);
    if(id[id.size()-1] == '.') id = id.substr(0, id.size()-1);
    // cout << "step4: " << id << endl;
    return step5(id);
}

// 빈 문자열
string step5(string id) {
    if(id.length() == 0)  id = "a";
    // cout << "step5: " << id << endl;
    return step6(id);
}

// 길이가 16자 이상이면, 15자까지만
string step6(string id) {
    if(id.length() >= 16) id = id.substr(0, 15);
    if(id[id.length()-1] == '.') id = id.substr(0, id.length()-1);
    // cout << "step6: " << id << endl;
    return step7(id);
}

// 길이가 2 이하면 길이가 3이 될때까지 맨 끝 문자를 덧붙임
string step7(string id) {
    while(id.length() < 3) {
        id.push_back(id[id.length()-1]);
    }
    // cout << "step7: " << id << endl;
    return id;
}

string solution(string new_id) {
    string answer = step1(new_id);
    return answer;
}#include <string>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;

string step1(string id);
string step2(string id);
string step3(string id);
string step4(string id);
string step5(string id);
string step6(string id);
string step7(string id);


// 소문자로
string step1(string id) {
    for(char &c : id) {
        c = tolower(c);
    }
    // cout << "step1: " << id << endl;
    return step2(id);
}

// 소문자, 숫자, -, _, .만 허용
string step2(string id) {
    regex pattern("[^a-z0-9-_.]+");
    id = regex_replace(id, pattern, "");
    // cout << "step2: " << id << endl;
    return step3(id);
}

// 점 2개이상 연속 -> 하나로
string step3(string id) {
    regex pattern("\\.+");
    id = regex_replace(id, pattern, ".");
    // cout << "step3: " << id << endl;
    return step4(id);
}

// 점 처음, 끝에 있으면 제거
string step4(string id) {
    if(id[0] == '.') id = id.substr(1);
    if(id[id.size()-1] == '.') id = id.substr(0, id.size()-1);
    // cout << "step4: " << id << endl;
    return step5(id);
}

// 빈 문자열
string step5(string id) {
    if(id.length() == 0)  id = "a";
    // cout << "step5: " << id << endl;
    return step6(id);
}

// 길이가 16자 이상이면, 15자까지만
string step6(string id) {
    if(id.length() >= 16) id = id.substr(0, 15);
    if(id[id.length()-1] == '.') id = id.substr(0, id.length()-1);
    // cout << "step6: " << id << endl;
    return step7(id);
}

// 길이가 2 이하면 길이가 3이 될때까지 맨 끝 문자를 덧붙임
string step7(string id) {
    while(id.length() < 3) {
        id.push_back(id[id.length()-1]);
    }
    // cout << "step7: " << id << endl;
    return id;
}

string solution(string new_id) {
    string answer = step1(new_id);
    return answer;
}