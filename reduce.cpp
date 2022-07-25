#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

ifstream fin("reduce.in");
ofstream fout("reduce.out");

int n;
pair<int, int> sortx[50000];
pair<int, int> sorty[50000];

//set<pair<int, int>> removed;

int ans = 40000*40000;

bool cmpy(pair<int, int > a, pair<int, int> b){
    return a.second < b.second;
}

void backtrack(int left, int right, int bottom, int top, int i, set<pair<int, int>> removed){
    if(left > right || bottom > top) return;

    int templeft = left, tempright = right, tempbottom = bottom, temptop = top;

    if(left != 0) removed.insert(sortx[left-1]);
    if(right != n-1) removed.insert(sortx[right+1]);
    if(bottom != 0) removed.insert(sorty[bottom-1]);
    if(top != n-1) removed.insert(sorty[top+1]);

    while(removed.count(sortx[templeft])){
        templeft++;
    }
    while(removed.count(sortx[tempright])){
        tempright--;
    }
    while(removed.count(sorty[temptop])){
        temptop--;
    }
    while(removed.count(sorty[tempbottom])){
        tempbottom++;
    }

    ans = min(ans, (sortx[tempright].first - sortx[templeft].first) * (sorty[temptop].second - sorty[tempbottom].second));

    if(i == 3){
        return;
    }

    backtrack(templeft+1, tempright, tempbottom, temptop, i+1, removed);
    backtrack(templeft, tempright-1, tempbottom, temptop, i+1, removed);
    backtrack(templeft, tempright, tempbottom+1, temptop, i+1, removed);
    backtrack(templeft, tempright, tempbottom, temptop-1, i+1, removed);
}

int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> sortx[i].first >> sortx[i].second;
        sorty[i].first = sortx[i].first;
        sorty[i].second = sortx[i].second;
    }

    sort(sortx, sortx+n);
    sort(sorty, sorty+n, cmpy);

    backtrack(0, n-1, 0, n-1, 0, set<pair<int, int>>());
    fout << ans;
}