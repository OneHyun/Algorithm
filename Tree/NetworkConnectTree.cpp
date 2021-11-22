#include <string>
#include <vector>
#include <iostream>
using namespace std;


bool dfs(int n, vector<vector<int>>& computers) 
{
    if (!computers[n][n]) //�̹� ��ȸ�� ����� ����(����Լ� Ż������)   
        return false;
    computers[n][n] = 0;
    for (int i = 0; i < computers.size(); i++) //������ŭ �ݺ�
    { 
        //����� ��尡 �ִٸ� ����Լ�
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
        //��ȸ���� ���� ����� dfsŽ���� answer����
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