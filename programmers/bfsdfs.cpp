// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string.h>
// #include <algorithm>
// using namespace std;

// int N, M, V; // 정점, 간선, 시작 정점
// vector<int> graph[1001];
// bool visited[1001];

// // 큐 구현
// void bfs(int start)
// {
//     queue<int> q;
//     q.push(start);         // 첫 노드 삽입
//     visited[start] = true; // 해당 노드 방문 처리

//     while (!q.empty())
//     {
//         int x = q.front(); // 하나 뽑아 출력
//         q.pop();
//         cout << x << " ";
//         for (int i = 0; i < graph[x].size(); i++)
//         {
//             int y = graph[x][i];
//             if (!visited[y])
//             {
//                 q.push(y);
//                 visited[y] = true;
//             }
//         }
//     }
// }

// // 재귀 구현
// void dfs(int current)
// {
//     visited[current] = true;
//     cout << current << " ";

//     for (int i = 0; i < graph[current].size(); i++) // 사이즈만큼 탐색
//     {
//         int y = graph[current][i]; // x의 인접 노드 값
//         if (!visited[y])           // 인접 노드값이 방문하지 않았다면
//         {
//             dfs(y); // 재귀를 통해 탐색
//         }
//     }
// }

// //        1  ㅡ  2
// //      /  \    /
// //    3 ㅡ 4

// //      5 ㅡ 4 ㅡ 3
// //     /             /
// //   2    ㅡ    1
// // dfs: 3 1 2 5 4
// // bfs: 3 1 4 2 5
// int main(void)
// {
//     cin >> N >> M >> V;

//     int x, y;
//     for (int i = 0; i < M; i++)
//     {
//         cin >> x >> y;
//         graph[x].push_back(y);
//         graph[y].push_back(x);
//     }

//     sort(graph[V].begin(), graph[V].end());
//     dfs(V);
//     cout << endl;

//     memset(visited, 0, sizeof(visited));

//     bfs(V);

//     // 그래프 확인
//     for (int i = 1; i <= N; i++)
//     {
//         cout << endl;
//         cout << "Node " << i << " connected to: ";
//         for (const int &neighbor : graph[i])
//         {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }
// }