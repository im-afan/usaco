#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
int comp[100001] = {0};
vector<pair<int, int>> graph[100001]; //pair: other end of wormhole, width
int cows[100001];

void getComps(int pos, int maxwidth, int curcomp){ //working
    if(comp[pos] != 0)
        return;

    comp[pos] = curcomp;

    for(auto newpos: graph[pos]){
        if(newpos.second >= maxwidth) getComps(newpos.first, maxwidth, curcomp);
    }
}

bool possible(){
    for(int i = 1; i <= n; i++){
        if(comp[cows[i]] != comp[i]) return false;
    }

    return true;
}

int solve(int low, int high){
    if(high-low == 0) return low;

    int mid;

    if(high-low == 1) mid = high; 
    else mid = (low + high)/2;
    
    fill(comp+1, comp+n+1, 0);
    
    for(int i = 1; i <= n; i++){
        if(!comp[i]) getComps(i, mid, i);
    }

    if(possible()) return solve(mid, high);
    else return solve(low, mid-1);
}

int main(){
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    fin >> n >> m;

    for(int i = 1; i <= n; i++){
        fin >> cows[i];
    }

    int maxw = 0;

    for(int i = 0; i < m; i++){
        int a, b, w;
        fin >> a >> b >> w;

        maxw = max(maxw, w); 

        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }

    int sorted = true;

    for(int i = 1; i <= n; i++){
        if(cows[i] != i) sorted = false;
    }

    if(sorted){
        fout << -1;
        return 0;
    }

    fout << solve(0, maxw);
}