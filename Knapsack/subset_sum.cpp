/*
 * dp[i+1][j] i番目までの整数の中からいくつか選んで
 * 総和を j とすることが可能かどうか
 *
 * dp[0][0] は，0個の整数で 0 が作れるか
*/

#include <iostream>

using namespace std;

void printDpTable();


int N, A;
int a[110];
bool dp[110][1110];


int main(void) {
    cin >> N >> A;
    for (int i=0; i<N; i++) cin >> a[i];

    dp[0][0] = true;

    // d[i+1][j] は， a[i][j] が True なら True
    // もしくは， j >= a[i] のとき
    //   dp[i][j-[a[i]] が True なら True
    for (int i=0; i<N; i++) {
        for (int j=0; j<=A; j++) {
            dp[i+1][j] |= dp[i][j];
            if (j >= a[i]) dp[i+1][j] |= dp[i][j-a[i]];
        }
    }

    printDpTable();
    if (dp[N][A]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void printDpTable() {
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=A; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
