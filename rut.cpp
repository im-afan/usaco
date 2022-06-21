#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct cow{
    pair<int, int> pos;
    int id;
};

int N;
vector<cow> cowsE;
vector<cow> cowsN;
pair<int, int> stop[1000]; //pair: (distance, blame)

bool cmp(cow a, cow b){
    return a.pos.second < b.pos.second;
}

bool cmpy(cow a, cow b){
    return a.pos.first < b.pos.first;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++) stop[i].second = -1;

    for(int i = 0; i < N; i++){
        char d;
        int x, y;
        cin >> d >> x >> y;

        cow cur;
        cur.pos = make_pair(x, y);
        cur.id = i;

        if(d == 'E') cowsE.push_back(cur);
        if(d == 'N') cowsN.push_back(cur);
    }

    sort(cowsN.begin(), cowsN.end(), cmpy);
    sort(cowsE.begin(), cowsE.end(), cmp);

    for(cow n: cowsN){
        for(cow e: cowsE){
            if(e.pos.first < n.pos.first && e.pos.second > n.pos.second){
                if(stop[e.id].second == -1){
                    if(n.pos.first - e.pos.first > e.pos.second - n.pos.second){ //n stops e
                        stop[e.id] = make_pair(n.pos.first - e.pos.first, n.id);
                    } else if(n.pos.first - e.pos.first < e.pos.second - n.pos.second){ //e stops n
                        stop[n.id] = make_pair(e.pos.second - n.pos.second, e.id);
                        break;
                    }
                } else if(stop[e.id].first > n.pos.first){ //e already stopped
                    stop[n.id] = make_pair(e.pos.second - n.pos.second, e.id);
                }
            }
        }
    }
    
    int ans[1000] = {0};

    for(int i = 0; i < N; i++){
        int j = i;
        while(stop[j].second != -1){
            ans[stop[j].second]++;
            j = stop[j].second;
        }
    }

    for(int i = 0; i < N; i++) cout << ans[i] << endl;
}
