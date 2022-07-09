#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

int n, b;
int f[250];
int s[250];
int d[250];
int ans = 251;
bool dp[250][250] = {false};

void dfs(int shoei, int pos, int discard){
    //cout << "shoe index: " << shoei << " position: " << pos << endl;
    if(pos == n-1){
     //   cout << "RETURN" << endl;
        ans = min(ans, discard);
        return;
    }

    if(pos > n-1){
        return;
    }

    if(dp[shoei][pos]) return;
    dp[shoei][pos] = true;

    for(int i = pos+1; i <= pos+d[shoei]; i++){
        //cout << "check new pos: " << f[i] << endl;
        if(f[i] <= s[shoei]) dfs(shoei, i, discard);
    }

    int temp = discard;
    for(int i = shoei+1; i < b; i++){
        temp++;
        //cout << "trying shoe max " << s[i] << " current depth: " << f[pos] << endl;
        if(s[i] >= f[pos]){
            //cout << "shoe " << i << " works" << endl;
            dfs(i, pos, temp);
        }
    }
}

int main(){
    fin >> n >> b;
    for(int i = 0; i < n; i++){
        fin >> f[i];
    }
    for(int i = 0; i < b; i++){
        fin >> s[i] >> d[i];
    }

    dfs(0, 0, 0);
    fout << ans;
}
