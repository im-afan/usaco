#include <iostream>
#include <fstream>
#include <utility>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

int n, m;
string spottedGene[500];
string plainGene[500];

bool valid(int i1, int i2, int i3){
    set<string> spotted;

    for(int i = 0; i < m; i++){
        string combo;
        combo.push_back(spottedGene[i][i1]);
        combo.push_back(spottedGene[i][i2]);
        combo.push_back(spottedGene[i][i3]);
        spotted.insert(combo);
    }

    for(int i = 0; i < n; i++){
        string combo;
        combo.push_back(plainGene[i][i1]);
        combo.push_back(plainGene[i][i2]);
        combo.push_back(plainGene[i][i3]);      
        if(spotted.count(combo))
            return false;
    }

    return true;
}

int main(){
    fin >> n >> m;

    for(int i = 0; i < n; i++){
        fin >> spottedGene[i];
    }

    for(int i = 0; i < n; i++){
        fin >> plainGene[i];
    }

    int ans = 0;

    for(int i1 = 0; i1 < m; i1++){
        for(int i2 = i1+1; i2 < m; i2++){
            for(int i3 = i2+1; i3 < m; i3++){
                if(valid(i1, i2, i3))
                    ans++;
            }
        }
    }
    
    fout << ans;
}