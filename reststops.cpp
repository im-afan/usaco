#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

ifstream fin("reststops.in");
ofstream fout("reststops.out");

int n;
int l;
int rf, rb;
pair<int, int> patch[100000];
bool stop[100000] = {false};

int main(){
    fin >> l >> n >> rf >> rb;
    
    for(int i = 0; i < n; i++) fin >> patch[i].first >> patch[i].second;

    //vector<int> stops;

    int max_before = -1;

    for(int i = n-1; i >= 0; i--){
        //cout << "alksdnflaknsdf" << endl;
        if(patch[i].second > max_before){
            stop[i] = true;
            max_before = patch[i].second;
        }
    }

    long long ans = 0;
    long long prevpos = 0;

    long long timebetween = 0;

    for(int i = 0; i < n; i++){
        timebetween += rf*(patch[i].first-prevpos) - rb*(patch[i].first-prevpos);
        prevpos = patch[i].first;
        if(stop[i]){
            ans += timebetween * patch[i].second;
            timebetween = 0;
        }
    }

    fout << ans;
}
