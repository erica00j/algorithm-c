#include <iostream>
#include <stack>

using namespace std;

int solution(const string& str) {
	stack<char> st;
	int answer = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') { //여는 괄호이면 stack에 push
			st.push('(');
		}
		else { //닫는 괄호이면
			st.pop();

			if (str[i - 1] == '(') { //이전 문자가 (이면 레이저
				answer += st.size(); //레이저이면 스택 사이즈만큼 더하기
			}
			else { //이전 문자가 (가 아니면 쇠막대기의 끝
				answer += 1; //쇠막대기의 끝이면 +1
			}
		}
	}
	return answer;
}
int main() {
	string str;
	cin >> str;

	int answer = solution(str);
	cout << answer;
	return 0;
}