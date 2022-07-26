#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("moocast.in");
ofstream fout("moocast.out");

int n;
int cowx[1000];
int cowy[1000];
bool vis[1000];

void dfs(int cur, int x){
    if(vis[cur])
        return;
    vis[cur] = true;
    
    for(int i = 0; i < n; i++){
        if(i != cur){
            if((cowx[i]-cowx[cur])*(cowx[i]-cowx[cur]) + (cowy[i]-cowy[cur])*(cowy[i]-cowy[cur]) <= x)
                dfs(i, x);
        }
    }
}

bool check(int x){
    fill(vis, vis+n, 0);
    dfs(0, x);

    for(int i = 0; i < n; i++){
        if(!vis[i]) return false;
    }
    return true;
}

int main(){
    fin >> n;   
    for(int i = 0; i < n; i++){
        fin >> cowx[i];
        fin >> cowy[i];
    }

    int l = 0,  r = 25000*25000 + 25000*25000;
    int ans = r;

    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }

    fout << ans;
}
