#include <iostream>
#include <fstream>
#include <algorithm>
//#define LOCAL
#define ll long long

using namespace std;

ll n, k, l;
ll c[100000];

bool check(ll h){
    ll missing = 0;
    for(int i = h-1; i >= 0; i--){
        missing += max((ll)0, h-c[i]);
        if(c[i] + k < h)
            return false;
    }
    return l*k >= missing;
}

int main(){
#ifdef LOCAL
    freopen("input.in", "r", stdin);
#endif
    cin >> n >> k >> l;
    for(ll i = 0; i < n; i++){
        cin >> c[i];
    }

    sort(c, c+n);
    reverse(c, c+n);

    ll l = 0, r = n;
    ll ans = 0;

    while(l+1 < r){
        ll mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        } else{
            r = mid-1;
        }
    }

    if(check(r)) cout << r;
    else cout << l;
}