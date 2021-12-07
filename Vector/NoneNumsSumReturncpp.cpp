#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> totalNumbers = { 0,1,2,3,4,5,6,7,8,9 };

//문제에서 제시된 0~9까지 vector<int>로 넣어두고
//매개변수 numbers에서 존재하는지 확인한 후, answer에 더하여 줌
int solution(vector<int> numbers) {
    int answer = 0;
    for (int i = 0; i < totalNumbers.size(); i++)
    {
        auto v = find(numbers.begin(), numbers.end(), totalNumbers[i]);
        if (v == numbers.end())
            answer += totalNumbers[i];
    }
    return answer;
}

//역으로 0~9 총합 45에서 있는 숫자들을 빼는 방법
//int solution(vector<int> numbers) {
//
//    int answer = 45;
//
//    for (int i = 0; i < numbers.size(); i++)
//        answer -= numbers[i];
//
//    return answer;
//}