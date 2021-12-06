#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
bool compare_map_value(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> musicPlayed;
    vector<pair<string, int>> vMusicPlayed;
    map<string,vector<pair<int, int>>> musicList;

    for (int i = 0; i < genres.size(); i++)
    {
        musicPlayed[genres[i]] += plays[i];
        musicList[genres[i]].push_back(make_pair(plays[i],i));
    }

    for (auto& k : musicList) {
        sort(k.second.begin(), k.second.end(), compare);
    }
    vMusicPlayed.assign(musicPlayed.begin(), musicPlayed.end());
    sort(vMusicPlayed.begin(), vMusicPlayed.end(), compare_map_value);

    for (int i = 0; i < vMusicPlayed.size(); i++) {
        string genre_name = vMusicPlayed[i].first;
        /*음악이 1개면 1개만, 2개이상이면 2개까지만 answer에 저장*/
        for (int j = 0; (j < musicList[genre_name].size()) && (j < 2); j++) {
            answer.push_back(musicList[genre_name][j].second);      //노래 고유번호 answer에 삽입
        }
    }
    return answer;
}

void main()
{
    vector<string> music_category = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> music_played = { 500, 600, 150, 800, 2500 };
    solution(music_category, music_played);
}