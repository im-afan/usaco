#include <iostream>
#include <cmath>

using namespace std;

int n;
int deg[100001] = {0};
int ans;

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }

    for(int i = 1; i <= n; i++){
        int children = deg[i] - (i!=1);
        int log = ceil(log2(children+1));

        ans += log;
        ans += children;
    }

    cout << ans;
}
