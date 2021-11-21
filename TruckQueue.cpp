#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> onBrigeTrucks;
    queue<int> completeTrucks;
    int currentWeight = 0;

    while (!truck_weights.empty() || !completeTrucks.empty())
    {
        int queueSize = onBrigeTrucks.size();
        for (int i = 0; i < queueSize; i++)
        {
            int length = onBrigeTrucks.front();
            onBrigeTrucks.pop();

            if (length <= 1) {
                currentWeight -= completeTrucks.front();
                completeTrucks.pop();
                continue;
            }
            onBrigeTrucks.push(length - 1);
        }

        if (truck_weights.size() > 0 && currentWeight + truck_weights.front() <= weight) {
            completeTrucks.push(truck_weights.front());
            currentWeight += truck_weights.front();
            onBrigeTrucks.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if (truck_weights.size() == 0 && completeTrucks.size() == 0)
            break;
    }
    return answer;
}
void print(int bridge_length, int weight, vector<int> truck_weights, int answer) {
    int t = solution(bridge_length, weight, truck_weights);
    cout << t << " , ";
    if (t == answer)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}

int main() {
    print(100, 100, { 10,10,10,10,10,10,10,10,10,10 }, 110);
    print(2, 10, { 7,4,5,6 }, 8);
    print(100, 100, { 10 }, 101);

    return 0;
}


