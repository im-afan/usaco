#include <iostream>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

ifstream fin("cowdance.in");
ofstream fout("cowdance.out");

int n, tmax;
int d[10000];

class cmp{
public:
    bool operator() (int a, int b){
        return a > b;
    }
};

bool check(int k){
    int t = 0;
    //set<int> dancing;
    priority_queue<int, vector<int>, cmp> dancing;
    for(int i = 0; i < n; i++){
        //cout << "time: " << t  << endl;
        if(dancing.size() < k){
            dancing.push(d[i]);
        } else{
            t = dancing.top();
            if(d[i]+t > tmax) return false;
            dancing.pop();
            dancing.push(d[i]+t);
        }
       // cout << "dancing set size: " << dancing.size() << endl;
    }
    return true;
}

int main(){
    fin >> n >> tmax;
    for(int i = 0; i < n; i++){
        fin >> d[i];
    }

    int l = 1;
    int r = n;

    while(l != r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        } else{
            l = mid+1;
        }
    }

    fout << r;
}
