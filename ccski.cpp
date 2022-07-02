#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ccski.in");
ofstream fout("ccski.out");

int n, m;
int grid[500][500];
bool vis[500][500] = {0};
vector<int> waypoint_i;
vector<int> waypoint_j;

void floodfill(int i, int j, int prev_i, int prev_j, int d){
    if(i < 0 || i > n || j < 0 || j > m) return;
    if(abs(grid[i][j] - grid[prev_i][prev_j]) > d) return;
    if(vis[i][j]) return;

    vis[i][j] = true;
    
    floodfill(i+1, j, i, j, d);
    floodfill(i-1, j, i, j, d);
    floodfill(i, j-1, i, j, d);
    floodfill(i, j+1, i, j, d);
}

bool dWorks(int d){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            vis[i][j] = false;

    floodfill(waypoint_i[0], waypoint_j[0], waypoint_i[0], waypoint_j[0], d);

    for(int i = 0; i < waypoint_i.size(); i++){
        int curi = waypoint_i[i];
        int curj = waypoint_j[i];
        if(vis[curi][curj] == false)
            return false;
    }
    return true;
}

int main(){
    fin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            fin >> grid[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int iswaypoint; fin >> iswaypoint;
            if(iswaypoint){
                waypoint_i.push_back(i);
                waypoint_j.push_back(j);
            }
        }
    }

    int low = 0, high = 1000000000;

    while(high-low > 1){
        int mid = (low+high)/2;
        if(dWorks(mid))
            high = mid;
        else
            low = mid;
    }

    if(high-low == 1){
        if(dWorks(high))
            fout << high;
        else
            fout << low;
    } else{
        fout << high;
    }
}
