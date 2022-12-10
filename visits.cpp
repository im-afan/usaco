#include <iostream>
#include <vector>
#define int long long
#define INT_MAX 1e9+1
using namespace std;

int n;
int p[100000];
int v[100000];
bool vis[100000];
int sum_barn[100000];
int ans = 0;

int32_t main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int pi, vi; cin >> pi >> vi;
		--pi;
		p[i] = pi;
		v[i] = vi;
		ans += vi;
	}

	for(int i = 0; i < n; i++){
		if(vis[i])
			continue;
		int j = i;
		int minval = INT_MAX;
		int sum = 0;
		vector<int> path;
		while(!vis[j]){
			vis[j] = true;
			path.push_back(j);
			j = p[j];
		}
	
		int foundstart = false;
		for(int k = 0; k < path.size(); k++){
			if(path[k] == j) foundstart = true;
			if(foundstart)
				minval = min(minval, v[path[k]]);
		}

		if(minval != INT_MAX)
			ans -= minval;
	}
	cout << ans;
}
