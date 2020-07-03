#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;
vector<vector<int>> grid, dist;

bool isValid(int x, int y) {
	return x < n && y < m && x >= 0 && y >= 0;
}
void bfs() { // This is a multi-source BFS where every white (1) cell is considered a source
	queue<ii> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 1) {
				q.push( { i, j });
				dist[i][j] = 0;	// Any white cell has a distance of 0
			}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {	// Check all the adjacent cells
			if (isValid(x + dx[i], y + dy[i])
					&& dist[x + dx[i]][y + dy[i]] == -1) {// If this cell is not visited yet,set it's minimum distance and add it to the queue
				dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
				q.push( { x + dx[i], y + dy[i] });
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		grid.assign(n, vector<int>(m));
		dist.assign(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < m; j++)
				grid[i][j] = line[j] - '0';
		}
		bfs();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << dist[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}

