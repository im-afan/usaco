#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long ans = 0;
vector<int> cols[20001];
vector<int> rows[20001];
vector<int> colsums[20001];
vector<int> rowsums[20001];

int calculate(int x, int y){
    //rows[y], cols[x]
    //if(x != 0 || y != 0) return 0;
    int numLeft = upper_bound(rows[y].begin(), rows[y].end(), x) - rows[y].begin()-1; //-1 because numBelow will also count the current point
    int numRight = rows[y].end() - lower_bound(rows[y].begin(), rows[y].end(), x)-1;

  //  printf("numRight: %d, numLeft: %d \n", numRight, numLeft);

    int sumHeightLeft = numLeft * x - rowsums[y][numLeft];
    int sumHeightRight = -numRight * x + (rowsums[y][rowsums[y].size()-1] - rowsums[y][numLeft+1]);

    int numBelow = upper_bound(cols[x].begin(), cols[x].end(), y) - cols[x].begin()-1; //-1 because numBelow will also count the current point
    int numAbove = cols[x].end() - lower_bound(cols[x].begin(), cols[x].end(), y)-1;
   // printf("sum of heights left: %d, sum of heights right: %d\n", sumHeightLeft, sumHeightRight);

    //cout << cols[0].size();

   // printf("numAbove: %d, numBelow: %d \n", numAbove, numBelow);

    int sumHeightBelow = numBelow * y - colsums[x][numBelow];
    int sumHeightAbove = -numAbove * y + (colsums[x][colsums[x].size()-1] - colsums[x][numBelow+1]);    

    //printf("sum of hegihts below; %d, sum of heights above: %d\n", sumHeightBelow, sumHeightAbove);
    ans += (long long)(sumHeightLeft + sumHeightRight) * (long long)(sumHeightBelow + sumHeightAbove);
}

int main(){
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    fin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y; fin >> x >> y;
        rows[y+10000].push_back(x+10000);
        cols[x+10000].push_back(y+10000);
    }
    
    for(int i = 0; i < 20001; i++){
        sort(cols[i].begin(), cols[i].end());
        sort(rows[i].begin(), rows[i].end());
    }

    for(int i = 0; i < 20001; i++){
        int cumul=0;
        for(int j = 0; j < cols[i].size(); j++){
            colsums[i].push_back(cumul);
            cumul += cols[i][j];
        }
        colsums[i].push_back(cumul);

        cumul=0;
        for(int j = 0; j < rows[i].size(); j++){
            rowsums[i].push_back(cumul);
            cumul += rows[i][j];
        }
        rowsums[i].push_back(cumul);
    }
    //cout << colsums[0][499] << endl;
    
    for(int x = 0; x < 20001; x++){
        for(auto y: cols[x]) {
            //cout << x << " " << y << endl;
            calculate(x, y);
        }
        //if(cols[x].size() > 0) cout << endl;
    }

    fout << ans%1000000007 << endl;
}