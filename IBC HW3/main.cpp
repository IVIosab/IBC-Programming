#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;
    cin >> n;
    int bins[n + 2], cu[n + 2];
    //cu is used to store the start and end for each ball so we don't need to iterate over each segment and knocking the ball one by one for each ball
    for (int i = 1; i <= n; i++) {
        bins[i] = 1;
        cu[i] = 0;
    }
    bins[0] = cu[0] = 0;
    bins[n + 1] = cu[n + 1] = 0;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        cu[l]++;
        cu[r + 1]--;
        //we add one to cu[l] and substitute one to cu[r+1]
    }
    int knocked = 0; //knocked is used to see if a ball had hit the current bin or not
    // we use it by adding each element from cu we pass on and if knocked is bigger than zero than the current bin has been knocked
    for (int i = 1; i <= n; i++) {
        knocked += cu[i];
        if (knocked >= 1) {
            bins[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (bins[i] == 1) {
            cout << "I";
        } else {
            cout << ".";
        }
    }
    cout << endl;
    return 0;
}