#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int currIdx, int wolf, int sheep, vector<int> nextNode, vector<int> info, vector<vector<int>> &adjList, int answer) {
		int isWolf = info[currIdx];
    if(!isWolf) sheep++;
    else wolf++;
    
	  //현재 양 마릿수와 최대 양 마릿수를 비교하여 최대값으로 정답을 갱신
    answer = max(answer, sheep);
    
	  //늑대수가 양의 수보다 같거나 많아졌다면 return
    if(wolf >= sheep) return answer;
    
		//현재 방문가능한 노드들을 순차적으로 방문
    for(int i = 0; i < nextNode.size(); i++) {
        vector<int> next = nextNode;
        next.erase(next.begin()+i); //다음으로 방문할 노드는 배열에서 삭제 후 재귀 파라미터에 전달
        
        for(int j = 0; j < adjList[nextNode[i]].size(); j++) {
            next.push_back(adjList[nextNode[i]][j]); 
        }
        answer = dfs(nextNode[i], wolf, sheep, next, info, adjList, answer);
    }
    return answer; //현재 방문가능한 노드들을 모두 방문했으면 return
}

int solution(vector<int> info, vector<vector<int>> edges) {
   vector<vector<int>> adjList(info.size());
    int answer = 1;

    for(int i = 0; i < edges.size(); i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int> nextNode; 
    for(int i = 0; i < adjList[0].size(); i++) {
        nextNode.push_back(adjList[0][i]);
    }
    
    answer = dfs(0, 0, 0, nextNode, info, adjList, answer); 
    
    return answer;
}
