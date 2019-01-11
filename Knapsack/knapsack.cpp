#include <iostream>

using namespace std;

int main(void) {
    int N,W;    // 物の個数，最大の重さ
    int weight[110], value[110];

    int dp[110][10010];     // dp table

    // 入力
    cin >> N >> W;
    for (int i=0; i<N; i++) cin >> value[i] >> weight[i];

    // DP
    for (int i=0; i<N; i++) {
        for (int w=0; w<=W; w++) {
            // i 番目の物が， w （一時的な容量）を超えないなら，入れる
            // そうでないなら，前と同じ．
            if( w>= weight[i]) {
                dp[i+1][w] = max( dp[i][w - weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i+1][w] = dp[i][w];
            }
        }
    }

    cout << dp[N][W] << endl;
}
