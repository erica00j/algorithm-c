#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m; //1부터 n까지의 자연수 중 중복없이 m개를 고른 수열 구하기 
vector<int> num(SIZE);
vector<bool> check(SIZE + 1); //해당 수가 현재 수열에서 사용이 되었는지 체크하는 배열

void backtracking(int cnt) { //cnt: 수열의 인덱스
    if (cnt == m) { //m개의 수열 만든 경우 (기저 조건)
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) { //i: 고르려는 수
        if (!check[i]) { //현재 수열에 해당 수가 없다면 사용 가능
            num[cnt] = i; //사용
            check[i] = true;
            backtracking(cnt + 1); //다음 인덱스 수 호출
            //다시 돌아왔을 때
            check[i] = false; //원래 상태로 돌려놓음
        }
    }
}
int main()
{
    //입력
    cin >> n >> m;
    //연산
    backtracking(0);
    return 0;
}
