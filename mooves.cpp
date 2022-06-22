#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, k;
int order[100001];
unordered_set<int> reach[100001];
int cnt[100001] = {0};
int comp[100001] = {0};
pair<int, int> swaps[200000];
int tempans = 0;
int cntcomp[100001] = {0};

void add(int node){
    for(auto i: reach[node]){
        if(cnt[i] == 0){
            cnt[i]++;
            tempans++;
        }
    }
}

void dfs(int node, int compnum){
    if(comp[node]) return;
    comp[node] = compnum;
    add(node);

    dfs(order[node], compnum);
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < k; i++)
        cin >> swaps[i].first >> swaps[i].second;

    for(int i = 1; i <= n; i++){
        order[i] = i;
        reach[i].insert(i);
    }

    for(int i = 0; i < k; i++){
        int temp = order[swaps[i].first];
        reach[order[swaps[i].first]].insert(swaps[i].second);
        reach[order[swaps[i].second]].insert(swaps[i].first);
        order[swaps[i].first] = order[swaps[i].second]; 
        order[swaps[i].second] = temp;
    }

    for(int i = 1; i <= n; i++){
        tempans = 0;
        if(!comp[i]){
            fill(cnt+1, cnt+n+1, 0);
            dfs(i, i);
            cntcomp[i] = tempans;
        }
    }

    for(int i = 1; i <= n; i++)
        cout << cntcomp[comp[i]] << endl;
}
