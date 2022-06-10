#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n;
char grid[1000][1000];
bool visited[1000][1000];

int perim;
int area;

int ans_perim = 0;
int ans_area = 0;

bool floodFill(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= n) return false;
    if(visited[i][j])  return true;
    if(grid[i][j] != '#') return false;

    visited[i][j] = true;
    area++;

    if(!floodFill(i+1, j)) perim++;
    if(!floodFill(i-1, j)) perim++;
    if(!floodFill(i, j+1)) perim++;
    if(!floodFill(i, j-1)) perim++;

    return true; 
}

int main(){
    ifstream infile;
    infile.open("perimeter.in");

    infile >> n;

    for (int i = 0; i < n; i++){
        string s; 
        infile >> s;
        for (int j = 0; j < n; j++){
            grid[i][j] = s[j];    
        }
        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && grid[i][j] == '#'){
                area = 0;
                perim = 0;
                
                floodFill(i, j);

                if(area > ans_area){
                    ans_area = area;
                    ans_perim = perim;
                }
                if(area == ans_area && perim < ans_perim){
                    ans_area = area;
                    ans_perim = perim;
                }
            }   
        }
    }

    ofstream outfile;
    outfile.open("perimeter.out");

    outfile << ans_area << " " << ans_perim << "\n";
}