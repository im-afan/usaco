#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("multimoo.in");
ofstream fout("multimoo.out");

struct component{
    int compid = 0;
    int compsize = 0;
    int cowid = 0;
};

struct cmp{
    bool operator() (component a, component b) const{
        if(a.compid == b.compid)
            return a.cowid < b.cowid;
        return a.compid < b.compid;
    }
};

int n;
int grid[250][250];
int compid[251][251] = {0};
int compsize[251*251] = {0};
int cowid[251*251] = {0};
set<int> graph_compid[251*251];
set<pair<int, int>> vispairs;

void floodfill(int i, int j, int target, int curcomp){
    if(i < 0 || i >= n || j < 0 || j >= n) return;
    if(grid[i][j] != target) return;
    if(compid[i][j]){
        return;
    }
    compsize[curcomp]++;
    compid[i][j] = curcomp;

    floodfill(i+1, j, target, curcomp);
    floodfill(i-1, j, target, curcomp);
    floodfill(i, j+1, target, curcomp);
    floodfill(i, j-1, target, curcomp);
}

int cursize = 0;
set<int> visited;

void dfs(int cur, int comp1, int comp2){
    if(cowid[cur] != cowid[comp1] && cowid[cur] != cowid[comp2])
        return;
    if(visited.count(cur))
        return;

    visited.insert(cur);
    vispairs.insert(make_pair(cur, comp1));
    vispairs.insert(make_pair(comp1, cur));
    vispairs.insert(make_pair(cur, comp2));
    vispairs.insert(make_pair(comp2, cur));
    cursize += compsize[cur];

    for(int node: graph_compid[cur]){
        dfs(node, comp1, comp2);
    } 
}

int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> grid[i][j];
        }
    }

    int comps = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!compid[i][j]){
                comps++;
                cowid[comps] = grid[i][j];
                floodfill(i, j, grid[i][j], comps);
            }
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    for(int i = 1 ;i <= comps; i++){
        ans1 = max(ans1, compsize[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > 0)
                graph_compid[compid[i][j]].insert(compid[i-1][j]);
            if(i < n-1)
                graph_compid[compid[i][j]].insert(compid[i+1][j]);
            if(j > 0)
                graph_compid[compid[i][j]].insert(compid[i][j-1]);
            if(j < n-1)
                graph_compid[compid[i][j]].insert(compid[i][j+1]);
        }
    }

    for(int i = 1; i <= comps; i++){
        for(int adj: graph_compid[i]){
            if(!vispairs.count(make_pair(i, adj))){
                //vispairs.insert(make_pair(adj, i));
                //vispairs.insert(make_pair(i, adj));
                visited.clear();
                cursize = 0;
                dfs(adj, i, adj);
                ans2 = max(ans2, cursize);
            }
        }
    }

    fout << ans1 << endl << ans2;
    cout << ans1 << endl << ans2;
}
