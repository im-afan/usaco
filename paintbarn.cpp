#include <iostream>
#include <fstream>

using namespace std;

int n, k;
int dp[1000][1000] = {0};

int main(){
    ifstream infile;
    infile.open("paintbarn.in");

    infile >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        infile >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j < x2; j++){
            dp[y1][j] += 1;
            dp[y2][j] -= 1;
        }
    }
    /*

    for(int i = 0; i < 9; i++){
        printf("\n");
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", dp[i][j]);
            if(dp[i][j] >= 0) printf(" ");
        }
    }*/

    int ans = 0;
    int line[1000] = {0};

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            line[j] += dp[i][j];
        }
        
        
        for (int j = 0; j < 1000; j++){
            n=line[j];
           // printf("%d ", n);
            if(n == k) ans++;
        }
        //printf("\n");*/
    }

    ofstream outfile;
    outfile.open("paintbarn.out");

    outfile << ans;
}