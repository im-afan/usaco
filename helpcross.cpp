#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
//#define LOCAL

using namespace std;

int c, n;
pair<int, int> cows[20000];
int chickens[20000];

bool cmpb(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(void){
#ifdef LOCAL
    freopen("input.in", "r", stdin);
#else
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
#endif

    cin >> c >> n;

    for(int i = 0; i < c; i++){
        cin >> chickens[i];
    }

    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }

    sort(chickens, chickens+c);
    sort(cows, cows+n);

    multiset<int, greater<int>> active; //b_i of cows before current chicken
    
    int ans = 0;
    int cowptr = 0;   

    for(int i = 0; i < c; i++){   
        while(cowptr < n && cows[cowptr].first <= chickens[i]){
            active.insert(cows[cowptr].second);
            cowptr++;
        }
        if(active.size()){
            auto outofrange = active.upper_bound(chickens[i]);
            active.erase(outofrange, active.end());
        }
        if(active.size()){
            active.erase(--active.end());
            ans++;
        } 
    }

    cout << ans;
}