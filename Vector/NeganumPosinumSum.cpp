#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < signs.size(); i++) {
        if (!signs[i]) 
            absolutes[i] *= -1;
        answer += absolutes[i];
    }
    return answer;
}

//int sumChk(int numbers, bool plusminus)
//{
//    if (plusminus)
//        return numbers;
//    else
//        return -numbers;
//}
//
//int solution(vector<int> absolutes, vector<bool> signs) {
//    int answer = 0;
//    for (int i = 0; i < absolutes.size(); i++)
//    {
//        answer += sumChk(absolutes[i], signs[i]);
//    }
//    return answer;
//}