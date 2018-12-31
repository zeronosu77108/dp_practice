/* 最長共通部分列問題（LCS）
 *   2つの文字列(s,t)が与えられたとき，
 *   共通の部分文字列の長さの最大値を求める問題
 *
 * dp[i][j] は，
 * s の i 文字目， t の j 文字目まだでの共通部分文字列
 * 
 * s[i] と t[i] が等しいなら， dp[i+1][j+1] = dp[i][j] + 1
 * そうでないなら，
 *   dp[i+1][j+1] = max( dp[i][j+1] , dp[i+1][j] )
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void printDpTable();

string s,t;
int dp[1010][1010];


int main(void) {
    cin >> s >> t;
    cout << s << endl;
    cout << t << endl;

    for (int i=0; i<s.length(); i++) {
        for (int j=0; j<t.length(); j++) {
            if ( s[i] == t[j] ) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max( dp[i+1][j], dp[i][j+1] );
            }
        }
    }
    printDpTable();
}

void printDpTable() {
    for (int i=0; i<=s.length(); i++) {
        for (int j=0; j<=t.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

