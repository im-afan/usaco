#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("diamond.in");
ofstream fout("diamond.out");

int n, k;
int A[100000];
int far[100000];

int main(){
    fin >> n >> k;
    for(int i = 0; i < n; i++)
        fin >> A[i];

    sort(A, A+n);

    int r = 0;

    for(int l = 0; l < n; l++){
        while(r < n-1 && A[r+1] - A[l] <= k){
            r++;
        }
        far[l] = r;
    }

    int curmax = 0;
    int j = n-1;
    int ans = 0;

    for(int i = n-1; i >= 0; --i){
        curmax = max(curmax, far[j] - j+1);
        while(j-1 > far[i] && j > 0){
            j--;
            curmax = max(curmax, far[j] - j+1);
        }
        ans = max(ans, far[i]-i+1 + curmax);
    }

    fout << ans;
}
