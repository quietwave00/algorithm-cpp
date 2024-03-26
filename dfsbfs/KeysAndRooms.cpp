/**
 * L841_Keys and Rooms
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void DFS(int v, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[v] = true;

        for(int i  = 0; i < rooms[v].size(); i++) {
            int next_v = rooms[v][i];
            if(!visited[next_v]) {
                DFS(next_v, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        DFS(0, rooms, visited);

        for(int i = 0; i < rooms.size(); i++) {
            if(!visited[i]) { // 방문하지 않은 vertex가 있다면
                return false;
            }
        }
        return true;
    }
};

int main() {
    // vector<vector<int>> rooms = {
    //     {{1,3},{3,0,1},{2},{0}}
    // };

    vector<vector<int>> rooms = { {1}, {2}, {3}, {} };

    bool answer = Solution().canVisitAllRooms(rooms);
    cout << answer << endl;

    return 0;
}