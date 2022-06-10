#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};

int n, k;
int grid[100][10];
bool vis[100][10];


//unordered_set<pair<int, int>, hashFunction> visited; 
vector<pair<int, int>> pop;

void floodFill(pair<int, int> coords, int target){ //i, j
    //printf("(%d, %d): %d, target: %d\n", coords.first, coords.second, vis[coords.first][coords.second], target);
    if(coords.first > n-1 || coords.first < 0 || coords.second > 9 || coords.second < 0) return;
    if(vis[coords.first][coords.second] != false) return;
    if(grid[coords.first][coords.second] != target) return;

    pop.push_back(coords);
    vis[coords.first][coords.second] = true;

    floodFill(make_pair(coords.first+1, coords.second), target);
    floodFill(make_pair(coords.first-1, coords.second), target);
    floodFill(make_pair(coords.first, coords.second+1), target);
    floodFill(make_pair(coords.first, coords.second-1), target);    
}

void gravity(){
    int lowest = n-1;
    //printf("gravity\n");
    
    for(int i = 9; i >= 0; i--){
        /*
        vector<int> nonzero;
        for(int j = n-1; j >= 0; j--){
            if(grid[j][i] != 0){
                nonzero.push_back(grid[j][i]);
            }
        }
        for(int j = 0; j < n; j++){
            grid[j][i] = 0;
        }
        for(int j = 0; j < nonzero.size(); j++){
            grid[n-j-1][i] = nonzero[j];
        }*/
        int p = n-1;
        for (int j = n-1; j >= 0; j--) {
            if (grid[j][i] != 0) {
                grid[p][i] = grid[j][i];
                p--;
            }
        }
        for (int j = p; j >= 0; j--) {
            grid[j][i] = 0;
        }
    }
}

void solve(){
    bool progress = false;

    while(true){
        progress = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                vis[i][j] = false;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    pop.clear();
                    floodFill(make_pair(i, j), grid[i][j]);
                    if(pop.size() >= k){
                        progress=true;
                        for(auto p: pop) grid[p.first][p.second] = 0;
                    }
                }
            }
        }
        gravity();
        if(!progress) break;
    }
}

int main(){
    ifstream infile;
    infile.open("mooyomooyo.in");
    infile >> n >> k;

    for (int i = 0; i < n; i++)
    {
        string s;
        infile >> s;
        for(int j = 0; j < 10; j++){
            grid[i][j] = s[j] - '0';
        }
    }

    solve();

    ofstream outfile;
    outfile.open("mooyomooyo.out");
    
    for (int i = 0; i < n; i++)
    {
            for (int j = 0; j < 10; j++)
            {
                outfile << grid[i][j];
            }
            outfile << "\n";
            
    }
}