#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
int cows[100000];

int main(){
    ifstream infile;
    infile.open("herding.in");

    infile >> n;

    for (int i = 0; i < n; i++)
    {
        infile >> cows[i];
    }
    
    sort(cows, cows+n);

    //get min
    int min = 2147483647;
    int back, front = 0;

    for (int i = 0; i < n; i++)
    {
        back = i;
        while(front < n-1 && cows[front+1] - cows[back]+1 <= n)
            front++;
       //cout << front << " " << back << endl;
        if(n-(front-back+1) < min) min = n-(front-back+1);
    }
    //printf("%d", min);
    if(cows[n-2]-cows[0]+1 == n-1 && (cows[n-1]-cows[0]+1)-n > 1) min = 2;
    if(cows[n-1]-cows[1]+1 == n-1 && (cows[n-1]-cows[0]+1)-n > 1) min = 2;

    //get max
    int max;
    if(cows[1]-cows[0] < cows[n-1] - cows[n-2])
        max = (cows[n-1]-cows[1])-(n-2);
    else
        max = (cows[n-2]-cows[0])-(n-2);

    ofstream outfile;
    outfile.open("herding.out");
    outfile << min << "\n" << max;
}