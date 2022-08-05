#include <iostream>
#include <algorithm>
//#define LOCAL

using namespace std;

int n, k, b;
int a[100001] = {0};

int main(){
    #ifdef LOCAL
        freopen("input.in", "r", stdin);
    #else
        freopen("maxcross.in", "r", stdin);
        freopen("maxcross.out", "w", stdout);
    #endif

    cin >> n >> k >> b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }

    int l = 1, r = 1;
    int lsum = 0, rsum = 0;
    for(; r <= k; ++r){
        rsum += a[r];
    }

    int ans = rsum;

    for(; r <= n; ++r){
        rsum += a[r];
        lsum += a[l];
        ans = min(ans, rsum - lsum);
        ++l;
    }
    cout << ans;
}