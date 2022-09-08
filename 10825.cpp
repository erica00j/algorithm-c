#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct { //구조체 정의
	string name;
	int kor, eng, math;
} Student;

bool compare(const Student& a, const Student& b) { //비교 함수 정의
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}
vector<string> solution(int n, vector<string> name, vector<int>kor, vector<int> eng, vector<int> math) {
	vector<string> answer(n); //정답을 담을 vector 선언
	Student arr[n + 1]; //Student 구조체 배열
	for (int i = 0; i < n; i++) arr[i] = { name[i],kor[i],eng[i],math[i] };
	sort(arr, arr + n, compare); //정렬
	for (int i = 0; i < n; i++) answer[i] = arr[i].name;
	return answer;
}

int main() {
	int n;
	cin >> n; //학생 수 입력
	vector<string> name(n);
	vector<int> kor(n);
	vector<int> eng(n);
	vector<int> math(n);

	for (int i = 0; i < n; i++) { //학생 이름 입력
		cin >> name[i];
	}
	for (int i = 0; i < n; i++) { //학생 점수 입력
		cin >> kor[i] >> eng[i] >> math[i];
	}

	auto answer = solution(n, name, kor, eng, math);

	for (auto i : answer)
		cout << i << '\n';
	return 0;
}