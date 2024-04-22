#include <iostream>
using namespace std;

int main() {
    int a[5][5] = {{1, 0, 0, 0, 0}, {4, 7, 0, 0, 0}, {6, 9, 5, 0, 0}, {1, 8, 4, 1, 0}, {2, 3, 0, 9, 6}};
    int b[16], index = 0;
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j <= i; j++)
            if (a[i][j])
                b[index++] = a[i][j];
    
    for (int i = 0; i < index; i++)
        cout << b[i] << ' ';
    cout << endl;
    
    return 0;
}
