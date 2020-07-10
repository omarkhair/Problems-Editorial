# UVA 196 - Spreadsheet Editorial

In case you didn't read the problem, check it [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=132).  
In this problem, you are required to implement a simple spreadsheet application. You will be provided with a 2d Array containing either a number or a **sum** equation. Note that the equation may contain a reference to another equation, so you have to calculate it first. It's guaranteed that there's no circular dependencies meaning that you will not find a cell **X** that depends on cell **Y**, and on the same time **Y** depends on **X**.  
Firstly, let's see how we can convert the given cell notation to row and column. If you are given **"AFC221"**, then for sure, row = 221. To get the column, we can treat **"AFC"** as a number system with base 26. To convert it to decimal "base 10", we take the right-most bit and multiply by 26<sup>0</sup>, the one to its left by 26<sup>1</sup>, and so on. Since we know, that A is equivalent to 1, B is equivalent to 2, and , in general, *char* is equivalent to 
``` char - 'A' + 1 ```.  
Then, for "AFC", col = ('C'-'A'+1)\*26<sup>0</sup> + ('F'-'A'+1)\*26<sup>1</sup> + ('A'-'A'+1)*26<sup>2</sup> .  

### Solution:
  Take the input as a string 2d array. Then, iterate over it and whenever we find an *expression*, we calculate its value recursively. Note that it has to be recursive because the cells involved in an expression may be an expression themselves. So, you extract the cells' indices from the expression, convert them as mentioned above, calculate their effective value using a recursive call, and add them all up. After you calculate its effective value, store it in your array, in case it was needed in another calculation. This will save you some time.  
Pay attention to the format of the output as there is no space after the last element of each row.  
  **Time complexity:**  ***O(Rows \* Columns)***.  
Another editorial for iterative solution can be found [here](https://algorithmist.com/wiki/UVa_196_-_Spreadsheet).  
You can find my ***C++*** solution below. Moreover, Here's a [link](https://github.com/kalex1994/UVA/blob/master/196.cpp) to a similar soltuion.  
  
  ``` 
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
```
