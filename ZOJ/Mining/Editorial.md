# ZOJ - 1200 Mining Editorial

You can read the problem statement  [here](https://zoj.pintia.cn/problem-sets/91827364500/problems/91827364699).  
This is obviously a simulation problem. We should simulate the process of robots being created, going to the digging area, collecting units, and coming back to the base until we reach **10000 Units** in base. We shall not simulate it minute by minute because this is not efficient as the time can grow to very large numbers.   
We are given 5 numbers as inputs:  
**S** - minutes to reach digging area  
**W** - minutes to extract units  
**C** - number of units extracted  
**K** - the number of robots available  
**M** - minutes to build a robot  

### Solution:
  We will use a **min priority queue** that will tell us the time required for each robot to reach the digging area. At the beginning, each robot needs *M* minutes to be built and *S* minutes to reach the digging area. So, the *1st* robot needs **M + S** minutes in total, *2nd* robot **2M + S** minutes, and the *last* robot needs **k * M + S** minutes. After adding those to our priority queue, we will let the first robot start digging, assume it starts at time **T**. The area will be occupied for *W* minutes. Note that for the next robot to dig, it will have to wait until this one finishes at **T+W**. After **T+W+S** minutes, this robot would reach the base with additional *C* units. It will be available again at the digging area after *S* minutes, so we will add **T+W+2S** to the PQ. Now we can choose the next robot in the PQ to work, and its start time would be the maximum between the time it reaches and the time the digging area becomes available.  
  This loop shall continue till we reach at least **10000 Units** in base. The final answer would be the *time to start the last dig + W + S*.
#### C++ code:
``` #include<iostream>
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
```
