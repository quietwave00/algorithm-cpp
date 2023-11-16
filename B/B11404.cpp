#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int INF = 987654321;
int graph[101][101];
int n, m, a, b, c;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) graph[i][j] = INF;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			

					
			
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
            cout << (graph[i][j] != INF ? graph[i][j] : 0)  << " ";
        }
		cout << endl;
	}
}