#include <string>
#include <vector>

using namespace std;
int maxDiff = 0; //최대 점수차

//최대 점수차와 현재 점수차가 동일한 경우
bool compare(vector<int> ryan, vector<int> &answer) {  
    //작은점수부터 화살수를 비교 🠒 현재값이 작은점수에 화살수가 더 많다면 true
		for(int i = 10; i >= 0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
    }
}

//쏜 화살 배열을 토대로 점수를 계산
void calcScore(vector<int> ryan, vector<int> apeach, vector<int> &answer) {
    int ryanScore = 0;
    int apeachScore = 0;

    for(int i = 0; i < 11; i++) {
        if(ryan[i] > apeach[i]) ryanScore += 10 - i;
        else if(apeach[i] > 0) apeachScore += 10 - i;
    }

    int diff = ryanScore - apeachScore;
    if(diff > 0 && maxDiff <= diff) { 
				//현재 점수차가 최대점수차와 동일하지만, 낮은점수대에 화살수가 더 많지 않다면 최대 점수차를 갱신하지 않습니다.
        if(maxDiff == diff && !compare(ryan, answer)) return;
        maxDiff = diff;
        answer = ryan;
    }
}

//dfs를 이용한 완전탐색 - 라이언이 화살을 쏘는 함수
void shoot(int idx, int arrows, vector<int> ryan, vector<int> apeach, vector<int> &answer) {
    if(idx==11 || arrows == 0) {
        ryan[10] += arrows;
        calcScore(ryan, apeach, answer);
        ryan[10] -= arrows; //다음 탐색을 위해 화살수 돌려놓기
        return;
    }

    //어피치가 해당 점수에 쏜 화살보다 보유한 화살이 많으면 쏘기
    if(apeach[idx] < arrows) {
        ryan[idx] += apeach[idx] +1; //어피치의 화살수 + 1 만큼만 쏘면 점수를 가져갈 수 있습니다.
        shoot(idx+1, arrows-apeach[idx]-1, ryan,apeach, answer);
        ryan[idx] -= apeach[idx] +1; //다음 탐색을 위해 화살수 돌려놓기
    }
    shoot(idx+1, arrows, ryan, apeach, answer); //해당 점수대에 화살을 쏘지 않은 경우
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11,0);
    vector<int> answer(11, -1);

    shoot(0, n, ryan, info, answer);

    if(answer[0] == -1) {
        vector<int> looseAnswer(1, -1);
        return looseAnswer;
    } //절대 이길 수 없을때

    return answer;
}
