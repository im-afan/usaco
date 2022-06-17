#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m, k;

int curK = 0;

int swapDist = 0;
map<int, vector<int>> change;

pair<int, int> swapcoords[100];


vector<int> transform(vector<int> old, vector<int> trans){
    vector<int> ret = {0};

    for(int i = 1; i < old.size(); i++){
        ret.push_back(old[trans[i]]);
    }

    return ret;
}

int main(){
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    fin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        fin >> swapcoords[i].first >> swapcoords[i].second;
    }

    vector<int> cur = {0};

    for(int i = 1; i <= n; i++)
        cur.push_back(i);
    
    while(curK < k){
        if(curK == 0){
            for(int i = 0; i < m; i++){
                for(int j = swapcoords[i].first; j <= (swapcoords[i].second+swapcoords[i].first)/2; j++){
                    int temp = cur[j];
                    cur[j] = cur[swapcoords[i].second-(j-swapcoords[i].first)];
                    cur[swapcoords[i].second-(j-swapcoords[i].first)] = temp;
                }
            }
            change.insert(make_pair(1, cur));
            curK = 1;
        } else{
            int timeleft = k - curK;

            if((*change.rbegin()).first > timeleft){
                curK += (*--change.upper_bound(timeleft)).first;
                cur = transform(cur, (*--change.upper_bound(timeleft)).second);
            } else{
                curK += (*change.rbegin()).first;
                cur = transform(cur, (*change.rbegin()).second);
                change.insert(make_pair(curK, cur));
            }
        }
    }
    cout << curK << endl;

    for(int i = 1; i <= n; i++){
        fout << cur[i] << endl;
    }
}
