#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    int mx = -1, x, y, tmp;
    for (int i = 1; i <= N; i++) { //row 
        for (int j = 1; j <= M; j++) { //col
            cin >> tmp;
            if (tmp > mx) {
            	mx = tmp, y = i, x = j;
            }
        }
    }

    cout << mx << " " << x << " " << N-y+1;
    return 0;
}

/*

4 4
1 3 5 7
2 7 4 9
6 8 9 10
12 13 11 10

*/