//had to look at solution for implementation, I had the right idea though!
//basically cow i can get gift j if cow i and cow j are in the same cycle for graph swaps

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <fstream>

using namespace std;

int N;
int A[501][501];
vector<int> swaps[501];
vector<int> mutualswaps[501];
int root;
bool visited[501][501] = {false};

void dfs(int cur){
    if(visited[root][cur]) return;
    visited[root][cur] = true;
    for(int n: swaps[cur])
        dfs(n);
}

int main(){

    cin >> N;

    for(int i = 1; i <= N; i++){
        bool better = true;
        for(int j = 1; j <= N; j++){
            int g;
            cin >> g;

            A[i][j] = g;

            if(better){
                if(g == i){
                    better = false;
                    swaps[i].push_back(g);
                }
                else
                    swaps[i].push_back(g);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        root = i;
        dfs(i);
    }

    for(int i = 1; i <= N; i++){
        for(int g: swaps[i]){
            if(visited[g][i] && visited[i][g]){ //2nd statemenet is trivial
                cout << g << endl;
                break;
            }
        }
    }
}