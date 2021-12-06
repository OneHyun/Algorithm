#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    for (int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for (int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if (hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}


void main()
{
    vector<string> phone_book = { "12", "123", "1235", "567", "88" };
    solution(phone_book);
}

//bool solution(vector<string> phone_book) {
//    bool answer = true;
//    sort(phone_book.begin(), phone_book.end());
//    for (int i = 0; i < phone_book.size()-1; i++) 
//    {
//        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
//        {
//            answer = false;
//            break;
//        }
//    }
//    return answer;
//}