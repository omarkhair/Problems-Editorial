#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, row, col;
	ll p, count;
	pair<int, int> dir[] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } }; // up, left, down, right
	while (true) {
		cin >> n >> p;
		if (n == 0)
			return 0;
		row = col = (n + 1) / 2;
		count = 1;
		int i = 0, step = 0;
		while (count < p) {
			if (i % 2 == 0)
				step++;
			if (count + step > p)	// in order not to pass the target
				step = p - count;	// make the step = the remaining distance
			count += step;
			row += step * dir[i % 4].first, col += step * dir[i % 4].second;
			i++;
		}
		cout << "Line = " << row << ", column = " << col << ".\n";
	}
	return 0;
}

