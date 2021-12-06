#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), desc);
    if (!citations[0])
        return 0;
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] > i)
            answer++;
        else
            break;
    }
    return answer;
}

void main()
{
    vector<int> citations = { 3, 0, 6, 1, 5 };
    solution(citations);
}