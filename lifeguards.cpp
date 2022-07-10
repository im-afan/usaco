#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define INT_MAX 2147483647

using namespace std;

struct point{
    bool begin;
    int guardind;
    int pos;
};

bool cmp(point a, point b){
    return a.pos < b.pos;
}

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int n;
vector<point> points;
int a[100000];
int b[100000];

int main(){
    fin >> n;

    for(int i = 0; i < n; i++){
        point p;
        fin >> p.pos;
        p.begin = true;
        p.guardind = i;
        points.push_back(p);
        a[i] = p.pos;
        fin >> p.pos;
        p.begin = false;
        points.push_back(p);
        b[i] = p.pos;
    }
    sort(points.begin(), points.end(), cmp);

    vector<int> prefix(points.size());

    int cumul = 0;
    int active = 0;
    int prev = points[0].pos;

    for(int i = 0; i < points.size()-1; i++){
        if(points[i].begin){
            active += 1;
        } else{
            active -= 1;
        }
        prefix[i] = cumul;
        if(active == 1){
            cumul += points[i+1].pos - points[i].pos;
        }
       
    }
    prefix[prefix.size()-1] = cumul;

    int minsubtract = INT_MAX;

    unordered_map<int, int> search;

    for(int i = 0; i < points.size(); i++){
        if(points[i].begin){
            search.insert(make_pair(points[i].guardind, i));
        } else{
            int first = search[points[i].guardind];
            int second = i;

            minsubtract = min(prefix[i] - prefix[first], minsubtract);
        }
    }

    //get total minutes of lifeguard duty
    int l = points[0].pos;
    int r = points[0].pos;
    int s = 0;
    active = 0;
    for(int i = 0; i < points.size(); i++){
        if(points[i].begin){
            active++;
            if(active == 1){
                l = points[i].pos;
                r = l;
            }
        } else{
            r = points[i].pos;
            active--;
            if(active == 0) s += r-l;
        }
    }
    fout << s - minsubtract;
}
