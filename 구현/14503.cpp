#include <iostream>
#include <vector>
using namespace std;
int solution(int n, int m, int r, int c, int d, vector<vector<int>> &map){
  int answer = 0 ;
	int nx, ny, nd, check;
  int dx[4] = {-1,0,1,0}; // 북 동 남 서
  int dy[4] = {0,1,0,-1}; 

  while (1) {
		if (map[r][c] == 0) { // 청소를 안 한 구역에
			answer++; // 청소한 구역의 수에 + 1을 해주고,
			map[r][c] = 2; // 청소했음을 표시해줍니다.
		}
		for (check = 0; check < 4; check++) {
			d = (d + 3) % 4; // 현재 방향의 왼쪽 방향 d를 구해줍니다.
			nx = r + dx[d]; // 왼쪽 방향의 좌표를 구해줍니다.
			ny = c + dy[d];
			if (map[nx][ny] == 0) { r = nx; c = ny; break; } // 왼쪽 방향이 청소하지 않은 곳이라면 그 위치로 이동하고 처음으로 돌아갑니다.
		}
		if (check == 4) { // 네 방향 모두 벽이거나 청소가 되어 있는 경우 뒤로 이동합니다.
			nd = (d + 2) % 4; // 뒤의 방향 nd를 구해줍니다.
			nx = r + dx[nd];  // 뒤의 방향의 좌표를 구해줍니다.
			ny = c + dy[nd];
			if (map[nx][ny] == 1)  break; // 뒤에가 벽일 경우 청소기 작동을 멈춥니다.
      //뒤가 벽이 아니면 그 쪽으로 이동합니다.
			r = nx;
			c = ny;
		}
	}
	return answer;
}

int main(void) {
   int n,m,r,c,d;
	scanf("%d %d", &n, &m);
  vector<vector<int>> map(n,vector<int>(m,0));
	scanf("%d %d %d", &r, &c, &d);
  vector<vector<int>> v;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin>>map[i][j];
  printf("%d",solution(n,m,r,c,d,map));
  return 0;
}
