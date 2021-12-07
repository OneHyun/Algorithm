#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> totalNumbers = { 0,1,2,3,4,5,6,7,8,9 };

//�������� ���õ� 0~9���� vector<int>�� �־�ΰ�
//�Ű����� numbers���� �����ϴ��� Ȯ���� ��, answer�� ���Ͽ� ��
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

//������ 0~9 ���� 45���� �ִ� ���ڵ��� ���� ���
//int solution(vector<int> numbers) {
//
//    int answer = 45;
//
//    for (int i = 0; i < numbers.size(); i++)
//        answer -= numbers[i];
//
//    return answer;
//}