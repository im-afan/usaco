#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int comp[100001] = {0};
vector<int> graph[100001];
//int newComp = 1;

int n, m;
string cows = ""; //cow types

void dfs(int cow, char type, int curcomp){
    if(comp[cow] != 0) return;
    if(cows[cow-1] != type) return;
    //printf("%d %c\n", cow, type);

    comp[cow] = curcomp;

    for(auto i: graph[cow]){
        dfs(i, type, curcomp);
    }
}

int main(){
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    fin >> n >> m;
    fin >> cows;

    for(int i = 0; i < n-1; i++){
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        //printf("n: %d \n ", n);
    }

    for(int i = 1; i <= n; i++){
        dfs(i, cows[i-1], i);
        //newComp++;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        char type;
        fin >> a >> b >> type;

        //printf("%d %d %c \n", a, b, type);

        if(comp[a] != comp[b])
            fout << "1";
        else if(cows[a-1] == type)
            fout << "1";
        else
            fout << "0";
    }
}