#include <string>
#include <vector>

using namespace std;

int abs(int handPos, int pushNumPos)
{
    int num = pushNumPos - handPos;
    if (num < 0)
        return -num;
    else
        return num;
}
int distance(int handPos, int pushNumPos)
{
    int distance = abs(handPos, pushNumPos);
    return ((distance / 3) + (distance % 3));
}

//키패드 구성이 가로 3개씩인 점을 생각해서 
//*을 10, 0을 11, #을 12로 설정
string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    int lHand = 10, rHand = 12;
    int lHandDist, rHandDist;

    for (int i = 0; i < numbers.size(); i++)
    {
        int num = (numbers[i] != 0 ? numbers[i] : 11);

        if (num % 3 == 1)
        {
            lHand = num;
            answer += 'L';
        }
        else if (num % 3 == 0)
        {
            rHand = num;
            answer += 'R';
        }
        else
        {
            lHandDist = distance(lHand, num);
            rHandDist = distance(rHand, num);

            if (lHandDist < rHandDist)
            {
                lHand = num;
                answer += 'L';
            }
            else if (lHandDist > rHandDist)
            {
                rHand = num;
                answer += 'R';
            }
            else
            {
                answer += (hand[0] - 32);
                if(hand == "right")
                    rHand = num;
                else
                    lHand = num;
            }
        }
    }
    return answer;
}

void main()
{
    vector<int> testNums = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string usingHand = "right";
    solution(testNums, usingHand);
}