#include <iostream>

using namespace std;

int main() {
	int n, a;

	//입력
	cin >> n;

	//완전 탐색 
	for (int i = 0; i <= n; i++) { //0과 n 사이의 생성자 찾기
		int sum = i;
		int tmp = i;

		while (tmp > 0) {
			//각 자릿수 더하는 로직 (몫과 나머지를 통해 각 자릿수 떼어내기)
			sum += (tmp % 10); //기존 sum에 오른쪽 끝자리 수 합하기
			tmp /= 10; //합한 오른쪽 끝자리 수 제거
		}
		if (n == sum) { //분해합이 n과 같아질 경우 생성자 출력
			cout << i;
			a++;
			break;
		}
		else { //분해합이 n과 같은 경우가 없을 때 생성자 0
			a = 0;
		}
	}

	if (a == 0) { //생성자 0 출력
		cout << "0";
	}
}