#include <string>
#include <vector>

using namespace std;

// 소수 판별 함수
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
//    sosu[0] = sosu[1] = 1;// true면 소수가 아니다.
//    for (int i = 2; i * i <= 3039; i++) {
//        if (!sosu[i]) {
//            for (int j = i * i; j <= 3039; j += i) sosu[j] = 1;
//        }
//    }
//}
//[출처] [프로그래머스] 소수 만들기 C++ | 작성자 류리
// 위 함수에선 문제의 최댓값이 1000이니, 3000까지 최대값으로 설정함
//에라토스테네스의 체 함수에 대한 스터디 하고자 가져옴
//에라토스테네스의 체란? 수학에서 소수를 찾는 방법
