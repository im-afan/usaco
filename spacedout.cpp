#include <iostream>

using namespace std;

int n;
//int grid[1000][1000];
int a[1000][1000];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    //check horizontal alternation
    int horizontalmax = 0;
    for(int i = 0; i < n; i++){
        int rowsum = 0;
        int sum1 = 0;
        for(int j = 0; j < n; j++){
            if(j % 2 == 0) sum1 += a[i][j];
            rowsum += a[i][j];
        }
        horizontalmax += max(rowsum-sum1, sum1);
    }

    //check vertical alternation

    int verticalmax = 0;
    for(int i = 0; i < n; i++){
        int colsum = 0;
        int sum1 = 0;
        for(int j = 0; j < n; j++){
            if(j % 2 == 0) sum1 += a[j][i];
            colsum += a[j][i];
        }
        verticalmax += max(colsum-sum1, sum1);
    }

    cout << max(verticalmax, horizontalmax);
}
