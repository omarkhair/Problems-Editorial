#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAXROWS = 999 + 5, MAXCOLS = 18278 + 5;		// 5 is for safety
string sheet[MAXROWS][MAXCOLS];

vector<string> split(string str) {	// this method splits the string using '+' as a delimiter
	vector<string> res;
	stringstream ss(str);
	string token;
	while (getline(ss, token, '+')) {
		res.push_back(token);
	}
	return res;
}
int calc(string &val) {
	if (val[0] != '=')
		return stoi(val);
	vector<string> tokens = split(val.substr(1));
	int result = 0;
	for (string s : tokens) {
		int i = 0, c = 0, r;
		// Convert spreadsheet notation to numbers
		while (s[i] >= 'A' && s[i] <= 'Z') {
			c *= 26;
			c += s[i] - 'A' + 1;
			i++;
		}
		r = stoi(s.substr(i));
		result += calc(sheet[r][c]);
	}
	val = to_string(result);	// it's important to save the result you calculated in the sheet
	return result;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
//	freopen("sort.in", "r", stdin);
//	freopen("sort.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int row, col;
		cin >> col >> row;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {
				cin >> sheet[i][j];
			}

		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {
				calc(sheet[i][j]);
			}

		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
					cout << sheet[i][j];
					if (j < col)
						cout<<' ';
			}
			cout << '\n';
		}
	}
	return 0;
}

