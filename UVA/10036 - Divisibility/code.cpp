#include<iostream>
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

