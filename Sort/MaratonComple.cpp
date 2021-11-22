#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

string  sortCompletion(vector<string>& participant, vector<string>& completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++) {
        if (participant[i] != completion[i])
            return participant[i];
    }
}

//Map, multiset 등에 대해 공부할것
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//    unordered_multiset<string> names;
//
//    for (int i = 0; i < participant.size(); i++)
//    {
//        names.insert(participant[i]);
//    }
//
//    for (int i = 0; i < completion.size(); i++)
//    {
//        unordered_multiset<string>::iterator itr = names.find(completion[i]);
//        names.erase(itr);
//    }
//
//    return *names.begin();
//}
string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    answer = sortCompletion(participant, completion);
    return answer;
}

void main()
{
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion{ "eden", "kiki" };
    solution(participant, completion);
}