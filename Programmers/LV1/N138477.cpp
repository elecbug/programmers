#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer = vector<int>();
    vector<int> now = vector<int>();
    for (int i = 0; i < score.size(); i++) {
        now.push_back(score[i]);
        sort(now.begin(), now.end());
        if (i < k) {
            answer.push_back(now[0]);
        }
        else {
            answer.push_back(now[now.size() - k]);
        }
    }
    return answer;
}