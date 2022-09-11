#include <iostream>
#include <stack>

using namespace std;

int solution(const string& str) {
	stack<char> st;
	int answer = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') { //���� ��ȣ�̸� stack�� push
			st.push('(');
		}
		else { //�ݴ� ��ȣ�̸�
			st.pop();

			if (str[i - 1] == '(') { //���� ���ڰ� (�̸� ������
				answer += st.size(); //�������̸� ���� �����ŭ ���ϱ�
			}
			else { //���� ���ڰ� (�� �ƴϸ� �踷����� ��
				answer += 1; //�踷����� ���̸� +1
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