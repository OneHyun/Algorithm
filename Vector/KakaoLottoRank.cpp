#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int>::iterator ptr;
    int cnt = 0, zeroCnt = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zeroCnt++;
            continue;
        }
       ptr = find(win_nums.begin(), win_nums.end(), lottos[i]);
       if (ptr != win_nums.end())
       {
           cnt++;
       }
    }
    
    int maxRank, minRank;
    if (cnt < 2)
        minRank = 6;
    else
        minRank = 6-cnt+1;

    if (cnt+zeroCnt < 2)
        maxRank = 6;
    else
        maxRank = 6 - (cnt + zeroCnt)+1;
    answer.push_back(maxRank);
    answer.push_back(minRank);

    return answer;
}

void main()
{
    vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
    vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
    solution(lottos, win_nums);
}