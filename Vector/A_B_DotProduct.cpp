#include <string>
#include <vector>

using namespace std;

// �Ҽ� �Ǻ� �Լ�
bool isChk(int num) {
    if (num == 0 || num == 1) return false;
    for (int i = 2; i < num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int n = nums[i] + nums[j] + nums[k];
                if (isChk(n) == true) {
                    answer++;
                }
            }
        }
    }

    return answer;
}

//bool sosu[3040];
//bool check[52];
//int answer = 0;
//void erotos() {
//    sosu[0] = sosu[1] = 1;// true�� �Ҽ��� �ƴϴ�.
//    for (int i = 2; i * i <= 3039; i++) {
//        if (!sosu[i]) {
//            for (int j = i * i; j <= 3039; j += i) sosu[j] = 1;
//        }
//    }
//}
//[��ó] [���α׷��ӽ�] �Ҽ� ����� C++ | �ۼ��� ����
// �� �Լ����� ������ �ִ��� 1000�̴�, 3000���� �ִ밪���� ������
//�����佺�׳׽��� ü �Լ��� ���� ���͵� �ϰ��� ������
//�����佺�׳׽��� ü��? ���п��� �Ҽ��� ã�� ���
