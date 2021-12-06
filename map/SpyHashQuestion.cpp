#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 1; 
	unordered_map <string, int> clothesMap; 
	
	for (vector<string> pair : clothes)
	{
		clothesMap[pair[1]]++;
	}
	//위쪽 for문과 같은 구성, 반복문 응용 학습
	//for(int i = 0; i < clothes.size(); i++)
	//{ clothesMap[clothes[i][1]]++; }


	unordered_map <string, int>::iterator iter; 
	for (iter = clothesMap.begin(); iter != clothesMap.end(); iter++)
	{
		answer *= iter->second + 1;
	}
	return answer - 1;
}

void main()
{
	vector<vector<string>> test = { {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear" } };
	solution(test);
}
