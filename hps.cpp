#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("hps.in");
ofstream fout("hps.out");

int n;
char f[100001];

int prefix_h[100001];
int prefix_p[100001];
int prefix_s[100001];

int suffix_h[100001];
int suffix_p[100001];
int suffix_s[100001];

int main(){
    fin >> n;

    int cumul_h = 0;
    int cumul_p = 0;
    int cumul_s = 0;

    for(int i = 0; i < n; i++){
        fin >> f[i];
    }
    
    for(int i = 0; i < n; i++){
        char a = f[i];
        if(a == 'H') cumul_h++;
        if(a == 'P') cumul_p++;
        if(a == 'S') cumul_s++;

        prefix_h[i] = cumul_h;
        prefix_p[i] = cumul_p;
        prefix_s[i] = cumul_s;
    }

    cumul_h = 0;
    cumul_p = 0;
    cumul_s = 0;

    for(int i = n-1; i >= 0; i--){
        char a = f[i];
        if(a == 'H') cumul_h++;
        if(a == 'P') cumul_p++;
        if(a == 'S') cumul_s++;

        suffix_h[i] = cumul_h;
        suffix_p[i] = cumul_p;
        suffix_s[i] = cumul_s;
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        int possible[7] = {ans,
        prefix_h[i] + suffix_p[i+1],
        prefix_h[i] + suffix_s[i+1],
        prefix_p[i] + suffix_h[i+1],
        prefix_p[i] + suffix_s[i+1],
        prefix_s[i] + suffix_h[i+1],
        prefix_s[i] + suffix_p[i]};
        ans = *max_element(begin(possible), end(possible));
    }

    fout << ans;
}
