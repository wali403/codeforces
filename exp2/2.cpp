#include <bits/stdc++.h> 
using namespace std;

int mat[5][5] = {
	{1, 0, 0, 0, 0},
	{4, 7, 0, 0, 0},
	{6, 9, 5, 0, 0},
	{1, 8, 4, 1, 0},
	{2, 3, 0, 9, 6}
};

int con[18];

int get_index(int r, int c) {
    return (r * (r + 1)) / 2 + c;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    for (int i = 0; i < 5; i++) {
    	for (int j = 0; j < 5; j++) {
    		con[get_index(i, j)] = mat[i][j];
     	}
    }

    for (int i = 0; i < 18; i++) {
    	cout << con[i] << ' ';
    }
	return 0;
}