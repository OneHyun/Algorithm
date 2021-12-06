#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//stack, queue를 사용하지 않은 이중 for문 방식
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();

    for (int i = 0; i < size; i++) {
        int time = 0;
        for (int j = i + 1; j < size; j++) {
            time++;
            if (prices[j] < prices[i] || j == size - 1) { //마지막에서 두번째 값은 만약 마지막 값이 더 크다면 push할 수가 없기때문에 조건에 추가
                answer.push_back(time);
                break;
            }
        }
    }

    answer.push_back(0); //마지막은 시간이 없음

    return answer;
}


//처음 Stack을 사용하면서, 불필요하게 이중for문을 동반하여
//가장 악수였던 것 같은방법
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

//Stack을 사용하여 해결 하는방법
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