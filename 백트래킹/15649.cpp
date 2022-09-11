#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m; //1���� n������ �ڿ��� �� �ߺ����� m���� �� ���� ���ϱ� 
vector<int> num(SIZE);
vector<bool> check(SIZE + 1); //�ش� ���� ���� �������� ����� �Ǿ����� üũ�ϴ� �迭

void backtracking(int cnt) { //cnt: ������ �ε���
    if (cnt == m) { //m���� ���� ���� ��� (���� ����)
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) { //i: ������ ��
        if (!check[i]) { //���� ������ �ش� ���� ���ٸ� ��� ����
            num[cnt] = i; //���
            check[i] = true;
            backtracking(cnt + 1); //���� �ε��� �� ȣ��
            //�ٽ� ���ƿ��� ��
            check[i] = false; //���� ���·� ��������
        }
    }
}
int main()
{
    //�Է�
    cin >> n >> m;
    //����
    backtracking(0);
    return 0;
}