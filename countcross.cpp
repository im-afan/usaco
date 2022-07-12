#include <iostream>
#include <fstream>
#include <set>
#include <utility>

using namespace std;

int n, k, r;
int comp[101][101] = {0};
pair<int, int> cows[100];
set<pair<pair<int, int>, pair<int, int>>> roads;
ifstream fin("countcross.in");
ofstream fout("countcross.out");

void floodFill(int previ, int prevj, int curi, int curj, int curcomp){
    if(curi > n || curi < 1 || curj > n || curj < 1)
        return;
    if(comp[curi][curj])
        return;
    if(roads.find(make_pair(make_pair(previ, prevj), make_pair(curi, curj))) != roads.end() || roads.find(make_pair(make_pair(curi, curj), make_pair(previ, prevj))) != roads.end()){
       // cout << "alksdnf" << endl;
        return;
    }

   // cout << curi << " " << curj << endl;
    comp[curi][curj] = curcomp;

    floodFill(curi, curj, curi+1, curj, curcomp);
    floodFill(curi, curj, curi-1, curj, curcomp);
    floodFill(curi, curj, curi, curj+1, curcomp);
    floodFill(curi, curj, curi, curj-1, curcomp);
}

int main(){
    fin >> n >> k >> r;

    for(int i = 0; i < r; i++){
        int r, c, r1, c1;
        fin >> r >> c >> r1 >> c1;
        roads.insert(make_pair(make_pair(r, c), make_pair(r1, c1)));
    }
    for(int i = 0; i < k; i++){
        fin >> cows[i].first >> cows[i].second;
    }

    int compnum = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(comp[i][j] == 0){
                //cout << i << j << endl;
                //cout << "NEW FLOOD FILL" << endl;
                floodFill(i, j, i, j, compnum);
                compnum++;
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << comp[i][j] << " ";
        }
        cout << endl;   
    }
    */
    int ans = 0;

    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            if(comp[cows[i].first][cows[i].second] != comp[cows[j].first][cows[j].second]){
                ans ++;
            }
        }
    }
    fout << ans;
}