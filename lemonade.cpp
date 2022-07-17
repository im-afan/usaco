#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

int n;
int w[100000];

int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> w[i];
    }
    sort(w, w+n);
    reverse(w, w+n);
    
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(w[i] >= i){
            ans++; 
        }
    }

    fout << ans;
}
