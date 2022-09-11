#include <iostream>

using namespace std;

int main() {
	int N, M, a[100]; //N: 카드의 개수, a: 카드의 숫자를 저장하는 일차원 배열
	int sum = 0, near = 0;

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i]; //카드의 숫자 입력
	}

	//완전 탐색(N장의 카드 중 3장의 카드 조합의 경우의 수)
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = a[i] + a[j] + a[k]; //각 경우의 수마다 3장의 숫자 합을 sum에 저장
				//sum이 M보다 작거나 같고 기존 near값보다 크다면 새로운 near값으로 갱신
				if (near < sum && sum <= M) {
					near = sum;
				}
			}
		}
	}

	//출력
	cout << near;
}