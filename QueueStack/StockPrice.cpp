#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//stack, queue�� ������� ���� ���� for�� ���
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();

    for (int i = 0; i < size; i++) {
        int time = 0;
        for (int j = i + 1; j < size; j++) {
            time++;
            if (prices[j] < prices[i] || j == size - 1) { //���������� �ι�° ���� ���� ������ ���� �� ũ�ٸ� push�� ���� ���⶧���� ���ǿ� �߰�
                answer.push_back(time);
                break;
            }
        }
    }

    answer.push_back(0); //�������� �ð��� ����

    return answer;
}


//ó�� Stack�� ����ϸ鼭, ���ʿ��ϰ� ����for���� �����Ͽ�
//���� �Ǽ����� �� �������
//vector<int> solution(vector<int> prices) {
//    int sizeChk = prices.size();
//    vector<int> answer(sizeChk);
//    vector<int> pricesCopyLight = prices;
//    stack<int> st;
//    int cnt = 0;
//
//    for (int i = 0; i < sizeChk; i++)
//    {
//        cnt = 0;
//        for (int j = i + 1; j < sizeChk; j++)
//        {
//            if (prices[i] <= prices[j])
//                cnt++;
//            else
//            {
//                cnt++;
//                break;
//            }
//        }
//        st.push(cnt);
//    }
//
//    for(int i = sizeChk-1; i >= 0; i--)
//    {
//        answer[i] = st.top();
//        st.pop();
//    }
//    return answer;
//}

//Stack�� ����Ͽ� �ذ� �ϴ¹��
//vector<int> solution(vector<int> prices) {
//    int sizeChk = prices.size();
//    vector<int> answer(sizeChk);
//    stack<int> st;
//
//    for (int i = 0; i < sizeChk; i++) {
// 
//        while (!st.empty() && prices[st.top()] > prices[i]) {
//            answer[st.top()] = i - st.top();
//            st.pop();
//        }
//        st.push(i);
//    }
//
//    while (!st.empty()) {
//        answer[st.top()] = sizeChk - st.top() - 1;
//        st.pop();
//    }
//    return answer;
//}

void main()
{
    vector<int> prices = { 1, 2, 3, 2, 3 };
    solution(prices);
}