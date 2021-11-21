#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> locationQue;
    vector<int> sortedPrio;

    for (int i = 0; i < priorities.size(); i++)
    {
        locationQue.push(i);
    }

    while (!locationQue.empty())
    {
        int nowIdx = locationQue.front();
        locationQue.pop();
        if (priorities[nowIdx] != *max_element(priorities.begin(), priorities.end()))
        {
            locationQue.push(nowIdx);
        }
        else
        {
            sortedPrio.push_back(nowIdx);
            priorities[nowIdx] = 0;
        }
    }
    for (int i = 0; i < sortedPrio.size(); i++)
    {
        if (sortedPrio[i] == location)
            answer = i + 1;
    }
    return answer;
}

void main()
{
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;
    int temp;
    temp = solution(priorities, location);
}