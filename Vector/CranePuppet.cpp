#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> container;
    int answer = 0;

    for (int i = 0; i < moves.size(); i++) {
        int num_row = board.size();
        int col = moves[i] - 1;
        for (int row = 0; row < num_row; row++) {
            if (board[row][col] != 0) {
                if (!container.empty()) {
                    if (container[container.size() - 1] == board[row][col]) {
                        container.pop_back();
                        answer += 2;
                    }
                    else {
                        container.push_back(board[row][col]);
                    }
                }
                else {
                    container.push_back(board[row][col]);
                }
                board[row][col] = 0;
                break;
            }
            else {
                continue;
            }
        }
    }

    return answer;
}

void main()
{
    vector<vector<int>> board = { 
        {0, 0, 0, 0, 0}, 
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1}, 
        {4, 2, 4, 4, 2}, 
        {3, 5, 1, 3, 1} };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 5, 1, 4, 3 };

    solution(board, moves);
}
//int solution(vector<vector<int>> board, vector<int> moves) {
//    int answer = 0;
//    vector<vector<int>>::iterator it;
//    vector<int>::iterator it2;
//    vector<int> clearArray;
//    int Cnt = 0;
//    for (it = board.begin(); it != board.end(); it++)
//    {
//        it->erase(remove(it->begin(), it->end(), 0), it->end());
//    } //0 으로 된 칸은 삭제 처리함 
//
//    int movesNum;
//    for (int i = 0; i< moves.size(); i++)
//    {
//        movesNum = moves[i] - 1;
//        if (board[movesNum].size() == 0)
//            continue;
//        if (!clearArray.empty() && (clearArray.back() == board[movesNum].back()))
//        {
//            clearArray.pop_back();
//            Cnt += 2; //연속된 2개가 붙을 때 마다 터지기에
//        }
//        else
//            clearArray.push_back(board[movesNum].back());
//        
//        board[movesNum].pop_back();
//    }
//    answer = Cnt;
//    return answer;
//}
// 
//vector<int> 특정값 remove 사용법
// v.erase(std::remove(v.begin(), v.end(), 2), v.end());
//v.erase(std::remove(v.begin(), v.end(), 4), v.end());