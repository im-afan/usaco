#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

ifstream fin("closing.in");
ofstream fout("closing.out");

int n, m;
unordered_set<int> graph[3001];
int comp[3001];
bool removed[3001] = {false};

void getcomps(int cur, int compnum){
    //cout << cur << endl;
    if(comp[cur]){
        return;
    }
    comp[cur] = compnum;

    for(int newnode: graph[cur]){
        if(!removed[newnode]){
            getcomps(newnode, compnum);
        }
    } 
}

bool check(){
    //cout << "CHECK" << endl;
    fill(comp+1, comp+n+1, 0);
    for(int i = 1; i <= n; i++){
        //cout << comp[i] << endl;
        if(!comp[i]){
            getcomps(i, i);
        }
    }

    //for(int i = 1; i <= n; i++) cout << comp[i] << " ";
    //cout << endl;
    //for(int i = 1; i <= n; i++) cout << removed[i] << " ";
    //cout << endl;

    int compnum = 0;

    for(int i = 1; i <= n; i++){
        if(!removed[i]){
            if(compnum == 0)
                compnum = comp[i];
            else if(comp[i] != compnum)
                return false;
        }
    }
    return true;
}

int main(){
    fin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    if(check()) fout << "YES" << endl;
    else fout << "NO" << endl;

    for(int i = 0; i < n-1; i++){
        int r;
        fin >> r;
        removed[r] = true;
        //cout << r << endl;
    //for(int i = 1; i < n; i++){
    //    cout << "[";
    //    for(int r: graph[i]) cout << r << " ";
    //    cout << "]" << endl;
    //}

        for(int remove: graph[r]){
            //cout << remove << endl;
            //graph[r].erase(graph[r].find(remove));
            graph[remove].erase(graph[remove].find(r));
        }
        graph[r].clear();
        if(check()) fout << "YES" << endl;
        else fout << "NO" << endl;
    }
}
