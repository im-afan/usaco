#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> graph[100001];
bool planted[100001];
int ans = 1;
int n;

void solve(int node){
    int add;
    if(ans == 1) add = graph[node].size();
    else add = (graph[node].size()-1) - (ans-2);

    planted[node] = true; 
    if(add > 0) ans += add;

    for(auto child: graph[node])
        if(!planted[child]) solve(child);
}

int main(){
    ifstream infile;
    infile.open("planting.in");

    infile >> n;

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        infile >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    solve(1);

    ofstream outfile;
    outfile.open("planting.out");

    outfile << ans << "\n";
}