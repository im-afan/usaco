#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, q;
string paint;
pair<int, int> queries[100001];
int prefix[100001], suffix[100001] = {0};
int stacksizes[100001] = {0};
vector<char> stack;

void buildDp(int *dp){
    int cumul = 0;
    for(int i = 0; i < n; i++){
        if(stack.size() > 0) 
            while(stack[stack.size()-1] > paint[i])
                stack.pop_back();
        if(stack.size() == 0 || paint[i] > stack[stack.size()-1]){
            stack.push_back(paint[i]);
            cumul++;
        }
        dp[i+1] = cumul;
    }
}

int main(){
    cin >> n >> q;
    cin >> paint;

    for(int i = 0; i < q; i++)
        cin >> queries[i].first >> queries[i].second;

    int cur = 1;

    buildDp(prefix);
    reverse(paint.begin(), paint.end());
    stack.clear();
    buildDp(suffix);
    reverse(suffix+1, suffix+n+1);
  
    for(int i = 0; i < q; i++){
        int below = prefix[queries[i].first-1];
        if(queries[i].first == 1) below = 0;

        int above = suffix[queries[i].second+1];
        if(queries[i].second == n) above = 0;

        cout << above+below << endl;
    }
}
