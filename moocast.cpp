#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector<int> edges[200];
int X[200];
int Y[200];
int P[200];
bool vis[200] = {false};

ifstream fin("moocast.in");
ofstream fout("moocast.out");

int dfs(int cur){
    if(vis[cur]) return 0;
    vis[cur] = true;

    int sum = 0;

    for(auto n: edges[cur]){
        sum += dfs(n);
    }

    return sum + 1;
}

int main(){
    fin >> N;

    for(int i = 0; i < N; i++){
        fin >> X[i] >> Y[i] >> P[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j && (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]) <= P[i]*P[i])
                edges[i].push_back(j);
        }
    }
    
    int ans = 0;

    for(int i = 0; i < N; i++){
        for(int i = 0; i < N; i++) vis[i] = false;
        ans = max(ans, dfs(i));
    }

    fout << ans;
}