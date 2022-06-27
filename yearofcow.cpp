#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, k;
vector<int> years;
vector<pair<int, int>> blocks;
vector<pair<int, int>> merges;

bool cmp(pair<int, int> a, pair<int, int> b){
    return blocks[a.first].second - blocks[a.second].first < blocks[b.first].second - blocks[b.second].first;
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int year; 
        cin >> year;
        years.push_back(year);
    }

    sort(years.begin(), years.end());
    reverse(years.begin(), years.end());

    int curyear = (years[0]+11)/12;
    int blockbegin = curyear;
    int prevyear = curyear;
    bool addlast = true;

    for(int i = 1; i < n; i++){
        curyear = (years[i] + 11)/12;
        if(prevyear-curyear > 1){
            blocks.push_back(make_pair(blockbegin, prevyear-1));
            blockbegin = curyear;
        }
        prevyear = curyear;
    }
    blocks.push_back(make_pair(blockbegin, prevyear-1));
    blocks.push_back(make_pair(0, 0));

    for(int i = 0; i < blocks.size()-1; i++) merges.push_back(make_pair(i, i+1));
    sort(merges.begin(), merges.end(), cmp);

    vector<pair<int, int>> newblocks;

    if(blocks.size() > k){
        vector<pair<int, int>> merge;
        for(int i = 0; i < blocks.size()-k; i++) merge.push_back(merges[i]);
        for(int i = 0; i < blocks.size(); i++) merge.push_back(make_pair(i, i));
        sort(merge.begin(), merge.end());

        int curbegin = merge[0].first;
        int curend = merge[0].second;

        for(int i = 1; i < merge.size(); i++){
            if(merge[i].first != merge[i-1].second){
                newblocks.push_back(make_pair(blocks[curbegin].first, blocks[curend].second));
                curbegin = merge[i].first;
            }
            curend = merge[i].second;
        }
        newblocks.push_back(make_pair(blocks[curbegin].first, blocks[curend].second));
    } else{
        for(auto b: blocks) newblocks.push_back(b);
    }

    int ans = 0;
    for(int i = 0; i < newblocks.size(); i++)
        ans += (newblocks[i].first - newblocks[i].second);

    cout << ans * 12;
    
}