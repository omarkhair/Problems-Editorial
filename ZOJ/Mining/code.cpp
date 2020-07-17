#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int s, w, c, k, m;
	while (cin >> s >> w >> c >> k >> m) {	// there are multiple test cases
		priority_queue<ll, vector<ll>, greater<ll>> pq;	// creating a min priority q
		ll digAvailable = 0, curTime = 0;
		int curUnits = 0;
		// add to the pq, for each of the k robots, the time required to reach the digging area
		for (int i = 1; i <= k; i++)
			pq.push(1ll * i * m + s);
		while (curUnits < 1e4) {
			// take the robot that will reach the digging area first
			ll closest = pq.top();
			pq.pop();
			curUnits += c;
			// this robot will start digging whenever it reaches the dig area and it is available
			curTime = max(digAvailable, closest) + w + s;
			digAvailable = max(digAvailable, closest) + w;
			// the robot would return to the dig area after 2s mins from finishing its digging
			pq.push(digAvailable + 2 * s);
		}
		cout << curTime << '\n';
	}
	return 0;
}

