#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream fin("fenceplan.in");
ofstream fout("fenceplan.out");

int n, m;
pair<int, int> pos[100001];
vector<int> graph[100001];
set<int> components[100001];
bool vis[100001] = {false};

void getcomps(int cur, int curcomp){
    if(vis[cur]) return;
    components[curcomp].insert(cur);
    vis[cur] = true;

    for(int node: graph[cur]){
        getcomps(node, curcomp);
    }
}

int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> pos[i].first >> pos[i].second;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int curcomp = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            getcomps(i, curcomp);
            curcomp++;
        }
    }

    int ans = 2147483647;

    for(int i = 0; i < curcomp; i++){
        int min_x = 2147483647;
        int max_x = -1;
        int min_y = 2147483647;
        int max_y = -1;
        for(int j: components[i]){
            min_x = min(pos[j].first, min_x);
            max_x = max(pos[j].first, max_x);
            min_y = min(pos[j].second, min_y);
            max_y = max(pos[j].second, max_y);
        }
        ans = min(2*(max_x-min_x) + 2*(max_y-min_y), ans);
    }

    fout << ans;
}
