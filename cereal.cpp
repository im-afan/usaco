#include <iostream>
#include <fstream>
//#define LOCAL

using namespace std;

int n, m;
int f[100000];
int s[100000];
int occ[100001];
int ans[100000];
int curans = 0;

void occupy2(int i){
    int j = occ[s[i]];
    if(j == -1) occ[s[i]] = i;
    else if(i < j){
        if(s[i] == f[j]){
            occ[s[i]] = i;
            occupy2(j);
        } else{
            --curans;
            occ[s[i]] = i;
        }
    } else{
        --curans;
    }
}

void occupy1(int i){
    int j = occ[f[i]];
    if(j == -1) occ[f[i]] = i;
    else{
        occ[f[i]] = i;
        occupy2(j);
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in", "r", stdin);
#else
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
#endif

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> f[i] >> s[i];
    }
    fill(occ+1, occ+1+m, -1);

    for(int i = n-1; i >= 0; i--){
        ++curans;
        occupy1(i);
        ans[i] = curans;
    }   

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}