#include <iostream>

using namespace std;

int main() {
	int n, a;

	//�Է�
	cin >> n;

	//���� Ž�� 
	for (int i = 0; i <= n; i++) { //0�� n ������ ������ ã��
		int sum = i;
		int tmp = i;

		while (tmp > 0) {
			//�� �ڸ��� ���ϴ� ���� (��� �������� ���� �� �ڸ��� �����)
			sum += (tmp % 10); //���� sum�� ������ ���ڸ� �� ���ϱ�
			tmp /= 10; //���� ������ ���ڸ� �� ����
		}
		if (n == sum) { //�������� n�� ������ ��� ������ ���
			cout << i;
			a++;
			break;
		}
		else { //�������� n�� ���� ��찡 ���� �� ������ 0
			a = 0;
		}
	}

	if (a == 0) { //������ 0 ���
		cout << "0";
	}
}