#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    //인덱스 에러가 나지 않도록 예외처리 (크기를 2만큼 여유두고)
    vector<int> clothes(n + 2, 1);
    for (auto i : lost) { //체육복을 잃어버린 학생
        clothes[i]--;
    }
    for (auto i : reserve) { //여분 옷을 가져온 학생
        clothes[i]++;
    }

    for (int i = 1; i <= n; i++) {
        if (clothes[i]) { //체육복 있으면
            continue;
        }
        if (clothes[i - 1] == 2) { //왼쪽 학생에게 체육복 빌릴 수 있으면
            clothes[i - 1]--;
            clothes[i]++;
        }
        else if (clothes[i + 1] == 2) { //오른쪽 학생에게 체육복 빌릴 수 있으면
            clothes[i + 1]--;
            clothes[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (clothes[i]) { //체육복 있는 학생 카운트
            answer++;
        } 
    }
    return answer;
}

int main() {
    vector<int> lost = { 2,4 };
    vector<int> reserve = { 1,3,5 };
    int n = 5;

    cout << solution(n, lost, reserve);
    return 0;
}
