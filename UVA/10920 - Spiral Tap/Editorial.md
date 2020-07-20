# 10920 - Spiral Tap Editorial

You can read the problem [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1861).  
All we need in this problem is to simulate the spiral move until we reach our target cell in an efficient way. Observe the illustration given below and try to find the pattern.  
![Spiral Tap](https://cdn.discordapp.com/attachments/731865130077519935/734915978718216192/unknown.png)  
### Solution:
  Assuming the board is *N\*N* and the target cell is in position *P*.  
  Make two pointers *row* and *col* and move them around the spiral. The starting point is *(N+1)/2* for both *row* and *col*. The moving directions are up, left, down, right. The step being made for each direction is 1, 1, 2, 2, 3, 3, 4, ... .  
  So, start at the middle, move 1 up, 1 left, 2 down, 2 right, 3 up, 3 left, 4 down, and so on until you reach the desired cell.  
  In your last step, make sure that you don't go beyond the cell at position *P*. This can be done by making the *last step = P - yourCounter*.  
    
   **Time complexity: worst case O(N)**.  
 #### My C++ solution:  
 ``` #include<iostream>
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
``` 
