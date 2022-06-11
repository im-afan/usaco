#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

int n;
pair<int, int> bases[100000];

bool nest(pair<int, int> a, pair<int, int> b){ //is a nested within b?
    if(a.first >= b.first && a.second <= b.second)
        return true;
    return false;
}

int main(){
    ifstream infile;
    infile.open("mountains.in");

    infile >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        infile >> x >> y;

        bases[i] = make_pair(x-y, x+y);
    }

    sort(bases, bases+n);


    //for(int i = 0; i < n; i++){
    //    printf("(%d, %d) ", bases[i].first, bases[i].second);
    //}

    int cur = 0;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {   
        //printf("cur: %d \n", cur);

        if(nest(bases[cur], bases[i])){
            cur = i;
        }
        else if(!nest(bases[i], bases[cur])){
            cur = i;
            ans++;
        }
    }
    
    printf("\nanswer: %d", ans);

    ofstream outfile;
    outfile.open("mountains.out");

    outfile << ans;
}