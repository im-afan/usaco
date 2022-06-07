//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

//#define int long long

using namespace std;

vector<long long> t;
int n, m, c;

bool check(int maxTime){
  //printf("maxtime: %d\n", maxTime);
  int busesUsed = 1;
  long long start = t[0];
  long long first = 0;

  for (int i = 1; i < t.size(); i++)
  {
    if(i - first+1 > c || t[i]-start > maxTime){
      first = i;
      start = t[i];
      busesUsed++;
    }
  }

  //printf("buses used: %d \n", busesUsed);

  return busesUsed <= m;
}

int binSearch(int lower, int upper){
  printf("upper: %d, lower: %d\n", upper, lower);
  if(upper == lower){
    return lower;
  }
  if(upper == lower+1){
    if(check(lower)) return lower;
    return upper;
  }

  int cur = (upper+lower)/2;

  if(check(cur)){
    return binSearch(lower, cur);
  } else{
    return binSearch(cur, upper);
  }
}

int main(){
  ifstream infile;
  infile.open("convention.in");

  infile >> n >> m >> c;
  //printf("%d %d %d \n", n, m, c);

  for (int i = 0; i < n; i++)
  {
    long long a; infile >> a;
    t.push_back(a);
  }
  
  sort(t.begin(), t.end());
 // printf("%d\n", t[t.size()-1]);
  //printf("%d", binSearch(t[0], t[t.size()-1]));

  ofstream outfile;
  outfile.open("convention.out");
  outfile << binSearch(0, 1000000000) << endl;
}
