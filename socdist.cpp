#include <iostream>
#include <utility>
#include <algorithm>
#include <fstream>
#define ll long long

using namespace std;

ifstream fin("socdist.in");
ofstream fout("socdist.out");

int n, m;
pair<int, int> intervals[100000];

int check(ll d){
    ll prev = -d;
    int placed = 0;

    for(int i = 0; i < m; i++){
        if(intervals[i].first >= prev + d){
            prev = intervals[i].first;
            placed++;
        } else{
            prev += d;
            
            while(prev > intervals[i].second && i < m){
                i++;
            }
            if(prev < intervals[i].first){
                prev = intervals[i].first;
            }
            if(i == m) return placed >= n;
            placed++;
        }
        
        placed += max((ll)0, (ll)(intervals[i].second - prev)/d);
        prev += (max((ll)0, (ll)(intervals[i].second - prev)/d))*d;
    }

    return placed >= n;
}

int main(){
    fin >> n >> m;
    for(int i = 0; i < m; i++){
        fin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals, intervals+m);
    
    ll low = 0;
    ll high = 1000000000000000000;

    while(high-low > 1){
        ll mid = (low+high)/2;
        if(check(mid)){
            low = mid;
        } else{
            high = mid-1;
        }
    }

    if(high-low == 1){
        if(check(high)) fout << high;
        else fout << low;
    } else{
        fout << low;
    }
}
