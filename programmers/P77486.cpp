#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void sendMoney(vector<int>& follow, vector<int>& result, int money, int me) {
    int lead = follow[me];
    int tax = money / 10;
    result[me] += money - tax;

    if (lead == -1 || tax == 0) {
        return;
    } else {
        sendMoney(follow, result, tax, lead);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> result(enroll.size(), 0);
    vector<int> follow(enroll.size(), -1);
    unordered_map<string, int> nameDict;

    int index = 0;
    for (const string& name : enroll) {
        nameDict[name] = index;
        index += 1;
    }

    for (int i = 0; i < referral.size(); ++i) {
        if (referral[i] != "-") {
            int target = nameDict[referral[i]];
            follow[i] = target;
        }
    }

    for (int i = 0; i < seller.size(); ++i) {
        int start = nameDict[seller[i]];
        int money = amount[i] * 100;
        sendMoney(follow, result, money, start);
    }

    return result;
}
