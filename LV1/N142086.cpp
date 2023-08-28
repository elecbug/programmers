#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> dist = vector<int>(26, -1);
    for (int i = 0; i < s.length(); i++) {
        if (dist[s[i] - 'a'] == -1) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(dist[s[i] - 'a']);
        }
        dist[s[i] - 'a'] = 0;
        for (int a = 0; a < 26; a++) {
            if (dist[a] != -1) {
                dist[a]++;
            }
        }
    }
    return answer;
}