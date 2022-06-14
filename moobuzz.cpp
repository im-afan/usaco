#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");

    int n; 
    fin >> n;
    
    int cumul = floor(n/3) + floor(n/5) - floor(n/15); 
    int add = floor(n/3) + floor(n/5) - floor(n/15);

    while(add > 0){     
        //cout << "add: " << add << " n: " << n << endl;
        n += add;

        add = floor(n/3) + floor(n/5) - floor(n/15)-cumul;
        cumul = floor(n/3) + floor(n/5) - floor(n/15);
   }

   fout << n;
}    