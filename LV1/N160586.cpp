#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer = vector<int>(targets.size());
    vector<int> len = vector<int>(26, 100);
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].length(); j++) {
            if (len[keymap[i][j] - 'A'] > j) {
                len[keymap[i][j] - 'A'] = j + 1;
            }
        }
    }
    for (int i = 0; i < targets.size(); i++) {
        for (int j = 0; j < targets[i].length(); j++) {
            if (len[targets[i][j] - 'A'] == 100) {
                answer[i] = -1;
                break;
            }
            answer[i] += len[targets[i][j] - 'A'];
        }
    }
    return answer;
}