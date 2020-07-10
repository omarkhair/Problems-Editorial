# UVA 10036 - Divisibility Editorial

In case you did not read the problem, check it [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=977).  
In this problem, you are given a number **k** and a sequence of **n** numbers where you can add either **+** or **-** between every two adjacent numbers. You are required to tell if there is a result that is divisible by k.  
At first glance, it can be approached by a simple recursion where at each step you either add or subtract the current number. When you reach the last element, check if the sum is divisible by k.  
Since this approach is exponential, we will use dynamic programming with a simple math trick.  
### Solution:  
The trick is that what matters at a point of recursion is the remainder of the sum not the sum itself. We want at the end of the day to know if the final value has remainder of **zero**. 
The approach is that we will create a Boolean 2d array ``` reached[n][k]``` which will tell us if we were at index *i*, and we reached a sum of remainder of *j* before. *(0 <= i < n, 0 <= j < k)*.  
We will start at index 0 and follow the same recursive approach of making of recursive call for both **+** and **-**. However, we will do so if and only if that same index with the same remainder was not reached before. To know the answer to the problem after the recursion ends, we will just check the cell 
```reached[n-1][0]``` which tells us whether we managed to reach the last element in the array with remainder 0.  
**Time complexity:**  ***O (n \* k)***.  

  
#### My C++ solution:  
```#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
bool reached[10005][105];
int arr[10005];

void calc(int index, int prev) {
	if (index == n)	// we reached the last element
		return;
	// Now we will either add or subtract the element at arr[index] to our previous result
	// if it's already calculated before, we ignore it
	int added = (((prev + arr[index]) % k) + k) % k;
	int subtracted = (((prev - arr[index]) % k) + k) % k;
	if (!reached[index][added]) {
		reached[index][added] = true;
		calc(index + 1, added);
	}
	if (!reached[index][subtracted]) {
		reached[index][subtracted] = true;
		calc(index + 1, subtracted);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int m;
	cin >> m;
	while (m--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		// initializing all cells to false
		for (int i = 0; i < n; i++)
			for (int j = 0; j < k; j++)
				reached[i][j] = false;
		reached[0][((arr[0] % k) + k) % k] = true;// only arr[0]%k can be reached from the first element
		// the additional (( +k) %k) is to account for -ve numbers
		calc(1, ((arr[0] % k) + k) % k);
		// Now we will check if we can reach the last element with remainder 0
		if(reached[n-1][0])
			cout<<"Divisible\n";
		else
			cout<<"Not divisible\n";
	}
	return 0;
}
```
