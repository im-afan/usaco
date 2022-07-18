#include <iostream>
#include <fstream>
#include <set>

using namespace std;

ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

int n;
set<int> bessiecards;
int elsiecards[50000];
set<int> bessie_upper;
set<int, greater<int>> bessie_lower;

int main(){
    fin >> n;
    for(int i = 1; i <= 2*n; i++){
        bessiecards.insert(i);
    }
    for(int i = 0; i < n; i++){
        fin >> elsiecards[i];
        bessiecards.erase(bessiecards.find(elsiecards[i]));
    }

    auto itr = bessiecards.begin();

    for(; itr != bessiecards.end(); ++itr){
        if(bessie_lower.size() < n/2)
            bessie_lower.insert(*itr);
        else
            bessie_upper.insert(*itr);
    }

    int ans = 0;

    for(int i = 0; i < n/2; i++){
        auto play = bessie_upper.lower_bound(elsiecards[i]);
        if(play != bessie_upper.end()){
            ans++;
            bessie_upper.erase(play);
        } else{
            bessie_upper.erase(bessie_upper.begin());
        }
    }

    for(int i = n/2; i < n; i++){
        auto play = bessie_lower.lower_bound(elsiecards[i]);
        if(play != bessie_lower.end()){
            ans++;
            bessie_lower.erase(play);
        } else{
            bessie_lower.erase(bessie_lower.begin());
        }
    }

    fout << ans;
}
