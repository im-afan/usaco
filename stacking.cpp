#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, k;
int dp[1000001] = {0};
int sum[1000001] = {0};

int main(){
    ifstream fin("stacking.in");
    fin >> n >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        fin >> a >> b;
        dp[a] += 1;
        dp[b+1] -= 1;
    }
    int cumul = 0; 
    for(int i = 0; i < n; i++){
        cumul += dp[i];
        sum[i] = cumul;
    }

    sort(sum, sum+n);

    //for(int i = 0; i < n; i++) cout << sum[i] << " ";
    //cout << endl << n/2 << endl;
    ofstream fout("stacking.out");
    fout << sum[n/2];
}