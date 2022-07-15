#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

ifstream fin("sort.in");
ofstream fout("sort.out");

int n;
int A[100000];
int A_sort[100000];
unordered_map<int, int> farthest;

int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        int a;
        fin >> a;
        A[i] = a;
        A_sort[i] = a;
    }

    sort(A_sort, A_sort+n);

    for(int i = 0; i < n; i++){;
        if(!farthest.count(A_sort[i])){
            farthest.insert(make_pair(A_sort[i], i));
        } else{
            farthest.erase(farthest.find(A_sort[i]));
            farthest.insert(make_pair(A_sort[i], i));
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        int posdiff = i-farthest[A[i]] + 1;
        ans = max(ans, posdiff);
    }

    fout << ans;
}
