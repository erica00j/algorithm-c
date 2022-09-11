#include <iostream>
#include <vector>

using namespace std;
const int MOD = 10007;

//길이 N에서 일의 자리 수가 0 ~ 9인 오르막 수 모두 더하는 함수
int sumLastCnt(vector<int> &arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans += arr[i];
        ans %= MOD;
    }
    return ans;
}

int solution(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(10, 1));

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 10; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }
    return sumLastCnt(dp[n]);
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산 & 출력
    cout << solution(n);
    return 0;
}
