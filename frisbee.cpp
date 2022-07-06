#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
int ind[300000];
int height[300000];
map<int, int> intervals; //begin, end

bool cmp(int a, int b){
    return height[a] > height[b]; 
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> height[i];
        ind[i] = i;
    }

    sort(ind, ind+N, cmp);

    long long ans = max(ind[0], ind[1]) - min(ind[0], ind[1])+1;
    intervals.insert(make_pair(min(ind[0], ind[1]), max(ind[0], ind[1])));

    for(int i = 2; i < N; i++){
        if(ind[i] < (*intervals.begin()).first){
            ans += (*intervals.begin()).first - ind[i] + 1;
            intervals.insert(make_pair(ind[i], (*intervals.begin()).first));
        } else if(ind[i] > (*intervals.rbegin()).second){
            ans += ind[i] - (*intervals.rbegin()).second + 1;
            intervals.insert(make_pair((*intervals.rbegin()).second, ind[i]));
        } else{
            auto itr = --intervals.lower_bound(ind[i]);
            int begin = (*itr).first;
            int end = (*itr).second;

            intervals.erase(itr);

            intervals.insert(make_pair(begin, ind[i]));
            intervals.insert(make_pair(ind[i], end));

            ans += ind[i] - begin + 1;
            ans += end - ind[i] + 1;
        }
    }


    cout << ans << endl;
}