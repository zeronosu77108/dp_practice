/* レーベルシュタイン距離
 *   2つの文字列(s,t) が与えられ s と t に変換する操作回数の最小値を求める問題
 *   操作は以下の3つ
 *     1. 変更 s の任意の1文字を任意の1文字に変更する
 *     2. 削除 s の任意の1文字を削除する（空になっても良い）．
 *     3. 挿入 s の任意の箇所に1文字挿入する．
 *
 * dp[i+1][j+1] は，
 * s の i 文字目までを変換して，
 * t の j 文字目までへと変換するための最小操作回数
 *
 * s[i] と t[j] が等しいなら， dp[i+1][j+1] = dp[i][j]
 * そうでないなら，以下のうちの最小値
 *   - 変更 dp[i][j] + 1 
 *   - 削除 dp[i][j+1] + 1
 *   - 挿入 dp[i+1][j] + 1 (t に挿入）
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void printDpTable();

const int INF = INT_MAX - 10;

string s,t;
int dp[1010][1010];

int main(void) {
    cin >> s >> t;

    // 初期化
    for (int i=0; i<1010; ++i) for (int j=0; j<1010; ++j) dp[i][j] = INF;
    dp[0][0] = 0;

    // 0行目， 0列目 の更新
    for (int i=0; i<s.length(); i++)
        dp[i+1][0] = dp[i][0] + 1;
    for (int i=0; i<t.length(); i++)
        dp[0][i+1] = dp[0][i] + 1;

    // dp 
    for (int i=0; i<s.length(); i++) {
        for (int j=0; j<t.length(); j++) {
            if ( s[i] == t[j] ) {
                dp[i+1][j+1] = dp[i][j];
            } else {
                dp[i+1][j+1] = min( {dp[i][j]+1, dp[i+1][j]+1, dp[i][j+1]+1} );
            }
        }
    }
    
    printDpTable();
    cout << "ans : " << dp[s.length()][t.length()] << endl;
}

void printDpTable() {
    int digit = log10( dp[s.length()][t.length()] )+2;
    for (int i=0; i<=s.length(); i++) {
        for (int j=0; j<=t.length(); j++) {
            cout << setw(digit) << dp[i][j] << " ";
        }
        cout << endl;
    }
}
