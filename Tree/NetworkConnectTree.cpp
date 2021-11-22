#include <string>
#include <vector>
#include <iostream>
using namespace std;


bool dfs(int n, vector<vector<int>>& computers) 
{
    if (!computers[n][n]) //이미 순회한 노드라면 리턴(재귀함수 탈출조건)   
        return false;
    computers[n][n] = 0;
    for (int i = 0; i < computers.size(); i++) //노드수만큼 반복
    { 
        //연결된 노드가 있다면 재귀함수
        if (computers[n][i])    
            dfs(i, computers);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    for (int i = 0; i < n; i++) 
    {
        //순회하지 않은 노드라면 dfs탐색후 answer증가
        if (computers[i][i] && dfs(i, computers))
            answer++;
    }
    return answer;
}

void main()
{
    int n = 3;
    vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };
    solution(n, computers);
}