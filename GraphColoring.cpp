#include <iostream>
using namespace std;

const int MAXN = 100;
int n, m;
int G[MAXN][MAXN];
int X[MAXN];

bool isSafe(int k, int c) {
    for (int i = 0; i < n; i++) {
        if (G[k][i] == 1 && c == X[i]) {
            return false;
        }
    }
    return true;
}

void graphColour(int k) {
    for (int c = 1; c <= m; c++) {
        if (isSafe(k, c)) {
            X[k] = c;
            if ((k + 1) < n) {
                graphColour(k + 1);
            } else {
                for (int i = 0; i < n; i++) {
                    cout << X[i] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    cout << "Enter the number of colors: ";
    cin >> m;

    cout << "Possible colorings: " << endl;
    graphColour(0);
    return 0;
}