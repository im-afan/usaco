#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[100000];
set<int> comps; //y value of comp

int main(){
#ifdef LOCAL
	freopen("input1.in", "r", stdin);
#else
	freopen("moop.in", "r", stdin);
	freopen("moop.out", "w", stdout);
#endif
	
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a, a+n);
    reverse(a, a+n);

    for(int i = 0; i < n; i++){
        auto lb = comps.lower_bound(a[i].second);
        if(lb == comps.end()){
            comps.insert(a[i].second);
        } else{
            int maxy = *comps.rbegin();
            comps.erase(lb, comps.end());
            comps.insert(maxy);
        }
    }

    cout << comps.size() << endl;
}
