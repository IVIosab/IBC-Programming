#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f first
#define s second
//defining some shortcuts to make the coding easier

int main() {

    int n = 8;
    int board[n][n]; // the chess board
    pair<int, int> pr[n]; //holding x,y for each queen
    memset(board, 0, sizeof board); // putting 0 in all of the array
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1; //putting each queen in it's place on the board
        pr[i] = {x - 1, y - 1};
    }

    for (int i = 0; i < n; i++) {
        int x = pr[i].f, y = pr[i].s;
        //checking column and row for other queens
        for (int j = 0; j < n; j++) {
            if (board[x][j] == 1 && y != j) { //checking column
                cout << "YES" << endl;
                return 0;
            }
            if (board[j][y] == 1 && x != j) { //checking row
                cout << "YES" << endl;
                return 0;
            }
        }
        //checking diagonals for other queens
        int minxy = min(x, y), maxxy = max(x,
                                           y); //some values that help with calculating the top right and top left start of diagonals
        int tx, ty; //temporary x and y
        //top left to right bottom diagonal
        tx = x - minxy;
        ty = y - minxy;
        while (tx < 8 && ty < 8) {
            if (tx == x && ty == y) {
                tx++;
                ty++;
                continue;
            }
            if (board[tx][ty] == 1) {
                cout << "YES" << endl;
                return 0;
            }
            tx++;
            ty++;
        }
        //top right to bottom left diagonal
        int t1 = min(x, (7 - maxxy));
        tx = x - t1;
        ty = y + t1;
        while (tx < 8 && ty >= 0) {
            if (tx == x && ty == y) {
                tx++;
                ty--;
                continue;
            }
            if (board[tx][ty] == 1) {
                cout << "YES" << endl;
                return 0;
            }
            tx++;
            ty--;
        }
    }
    cout << "NO" << endl;
    return 0;
}