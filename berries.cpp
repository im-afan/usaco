#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k;
int mod;
int trees[1000];

bool cmp(int a, int b){
    return a % mod > b % mod;
}

int main(){
    ifstream fin("berries.in");
    ofstream fout("berries.out");

    fin >> n >> k;

    for(int i = 0; i < n; i++){
        fin >> trees[i];
    }

    int ans;

    for(int i = 1; i <= *max_element(trees, trees+n); i++){
        int bcomplete = 0;

        for(auto t: trees)
            bcomplete += floor(t/i);
        
        if(bcomplete >= k){
            ans = max(k/2 * i, ans);
        } else{
            mod = i;
            int a = (bcomplete - floor(k/2)) * mod;
            sort(trees, trees+n, cmp);

            for(int j = 0; j < (k-bcomplete); j++){
                if(bcomplete + j >= k/2){
                    a += trees[j] % mod;
                }
            }

            ans = max(a, ans);
        }
    }

    fout << ans;
}