#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> onePersonPattern = { 1, 2, 3, 4, 5 };
vector<int> twoPersonPattern = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> threePersonPattern = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == onePersonPattern[i % onePersonPattern.size()])
            score[0]++;
        if (answers[i] == twoPersonPattern[i % twoPersonPattern.size()])
            score[1]++;
        if (answers[i] == threePersonPattern[i % threePersonPattern.size()])
            score[2]++;
    }

    int maxNum = *max_element(score.begin(), score.end());
    for (int i = 0; i < score.size(); i++)
    {
        if (maxNum == score[i])
            answer.push_back(i+1);
    }
    return answer;
}

void main()
{
    vector<int> answers = { 1,3,2,4,2 };
    solution(answers);
}