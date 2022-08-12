#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
//#define LOCAL

using namespace std;

int n, g;

struct cowlog {
  int time, cowid, change;
};

cowlog logs[100000];

bool cmplog(cowlog a, cowlog b) { return a.time < b.time; }

int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#else
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
#endif

    cin >> n >> g;
    set<int> willchange;

    for (int i = 0; i < n; i++) {
        cowlog l;
        cin >> l.time >> l.cowid >> l.change;
        willchange.insert(l.cowid);
        logs[i] = l;
    }

    sort(logs, logs + n, cmplog);
    
    unordered_map<int, int> mp;
    set<pair<int, int>> prodset;

    for (int c : willchange) {
        mp.insert(make_pair(c, g)); 
        prodset.insert(make_pair(g, c));
    }
    mp.insert(make_pair(*(willchange.rbegin()) + 1, g));
    prodset.insert(make_pair(g, *(willchange.rbegin()) + 1));

    int ans = 0;
	
    for (int i = 0; i < n; i++) {
		int prev = distance(prodset.lower_bound(make_pair((*prodset.rbegin()).first, -1)), prodset.end());
        int prevbest = (*prodset.rbegin()).second;
		prodset.erase(prodset.find(make_pair(mp[logs[i].cowid], logs[i].cowid)));
        
        mp[logs[i].cowid] += logs[i].change;
		prodset.insert(make_pair(mp[logs[i].cowid], logs[i].cowid));
		int cur = distance(prodset.lower_bound(make_pair((*prodset.rbegin()).first, -1)), prodset.end());
		int curbest = (*prodset.rbegin()).second;

        if(cur != prev || prevbest != curbest) ans++;
    }

	cout << ans;
}
