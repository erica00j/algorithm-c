#include <iostream>

using namespace std;

int main() {
	int N, M, a[100]; //N: ī���� ����, a: ī���� ���ڸ� �����ϴ� ������ �迭
	int sum = 0, near = 0;

	//�Է�
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i]; //ī���� ���� �Է�
	}

	//���� Ž��(N���� ī�� �� 3���� ī�� ������ ����� ��)
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = a[i] + a[j] + a[k]; //�� ����� ������ 3���� ���� ���� sum�� ����
				//sum�� M���� �۰ų� ���� ���� near������ ũ�ٸ� ���ο� near������ ����
				if (near < sum && sum <= M) {
					near = sum;
				}
			}
		}
	}

	//���
	cout << near;
}