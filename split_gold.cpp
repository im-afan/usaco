#include <iostream>
#include <utility>
#include <algorithm>

#define ll long long
//#define LOCAL

using namespace std;

ll n;
pair<ll, ll> a[50000];
ll min_area = (ll)1000000000*(ll)1000000000;

bool cmpy(pair<ll, ll> x, pair<ll, ll> y){
    return x.second < y.second;
}

void solveAxis(){
    ll prefix[100000];
    ll max_x = 0;
    ll min_x = 1000000001; 
    ll max_y = 0;
    ll min_y = 1000000001;

    for(ll i = 0; i < n; i++){
        max_x = max(a[i].first, max_x);
        min_x = min(a[i].first, min_x);
        max_y = max(a[i].second, max_y);
        min_y = min(a[i].second, min_y);
    
        prefix[i] = (max_x-min_x) * (max_y-min_y);
    }

    max_x = 0;
    min_x = 1000000001; 
    max_y = 0;
    min_y = 1000000001;

    for(ll i = n-1; i >= 0; i--){
        max_x = max(a[i].first, max_x);
        min_x = min(a[i].first, min_x);
        max_y = max(a[i].second, max_y);
        min_y = min(a[i].second, min_y);
    
        ll cur_area = (max_x-min_x) * (max_y-min_y);
        //cout << prefix[i]+cur_area << endl;
        min_area = min(min_area, prefix[i-1]+cur_area);
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in", "r", stdin);
#else
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
#endif

    cin >> n;

    for(ll i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n);
    ll lengthX = a[n-1].first - a[0].first;
    solveAxis();
    sort(a, a+n, cmpy);
    ll lengthY = a[n-1].second - a[0].second;
    solveAxis();

    cout << lengthX*lengthY - min_area;
}