#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> checkProcess(vector<int> progresses, vector<int> speeds)
{
    static vector<int> temp;
    queue<int> proQueue;

    int count = 0;
    int sub = 0;

    for (int i = 0; i < progresses.size(); i++) {

        proQueue.push(((99-progresses[i]) / speeds[i]+1));

    }
    sub = proQueue.front();

    while (!proQueue.empty()) {
        if (sub < proQueue.front()) {
            sub = proQueue.front();
            proQueue.pop();
            temp.push_back(count);
            count = 1;
        }
        else {
            count++;
            proQueue.pop();
        }
    }
    temp.push_back(count);
    return temp;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    answer = checkProcess(progresses, speeds);
    return answer;
}

void main()
{
    vector<int> progress = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1,1,1,1,1,1 };
    vector<int> test = solution(progress, speeds);
}



//vector<int> checkProcess(vector<int> progresses, vector<int> speeds, int idx = 0)
//{
//    static vector<int> temp;
//    int positionIdx = idx;
//    while (progresses[positionIdx] <= 100)
//    {
//        for (int i = positionIdx; i < progresses.size(); i++)
//        {
//            progresses[i] += speeds[i];
//        }
//    }
//    int completeCnt = 0, tempPositionidx = 0;
//    for (int j = positionIdx; j < progresses.size(); j++)
//    {
//        if (progresses[j] >= 100)
//        {
//            completeCnt++;
//        }
//        else
//            break;
//    }
//    temp.push_back(completeCnt);
//    if (completeCnt != progresses.size())
//    {
//        vector<int> nextProgresses;
//        vector<int> nextSpeed;
//        for (int k = completeCnt; k < progresses.size(); k++)
//        {
//            nextProgresses.push_back(progresses[k]);
//            nextSpeed.push_back(speeds[k]);
//        }
//        checkProcess(nextProgresses, nextSpeed);
//    }
//
//    return temp;
//}