#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Cow{
    int a; //arrival
    int t; //time eating grass
    int s; //seniority
    //int w; //waiting time
};

bool compare(Cow a, Cow b){
    return a.s > b.s;
}

bool compare_vec(Cow a, Cow b){
    if(a.a != b.a){
        return a.a < b.a;
    }
    return a.s < b.s;
}


int main(){
    ifstream infile;
    infile.open("convention2.in");

    int n; 
    infile >> n;

    vector<Cow> cows;

    for (int i = n; i > 0; i--)
    {
        Cow cow; 
        infile >> cow.a >> cow.t;
        cow.s = i;
        cows.push_back(cow);
    }

    sort(cows.begin(), cows.end(), compare_vec);

    auto cmp = [](Cow a, Cow b) { return a.s > b.s;};

    set<Cow, decltype(cmp)> line(cmp);

    int ans = 0;
    int i = 0;
    int curtime = cows[0].a;
    
    line.insert(cows[i]);
    Cow eating = *line.begin();
    line.erase(line.begin());
    i++;

    while(i < n || line.size() > 0){
        while(i < n && cows[i].a < curtime+eating.t){
            line.insert(cows[i]);
            i++;
        }

        curtime = curtime + eating.t;

        if(!line.empty()){
            eating = *line.begin();
            line.erase(line.begin());
            if(ans < curtime - eating.a) ans = curtime - eating.a;
        } else{
            eating = cows[i];
            curtime = eating.a;
            i++;
        }
    }
    
    ofstream outfile;
    
    outfile.open("convention2.out");
    outfile << ans << std::endl;
}