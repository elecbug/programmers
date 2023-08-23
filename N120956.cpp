#include <string>
#include <vector>

using namespace std;

bool start_with(string str, string target) {
    if (target.length() > str.length()) {
        return false;
    }
    else {
        for (int i = 0; i < target.size(); i++) {
            if (str[i] != target[i]) {
                return false;
            }
        }
        return true;
    }
}

int solution(vector<string> babbling) {
    vector<string> strs = {"aya", "ye", "woo", "ma"};
    int answer = 0;
    for (int i = 0; i < babbling.size(); i++) {
        int len = 0;
        int sum = 0;
        while (true) {
            len = babbling[i].length();
            for (int s = 0 ; s < strs.size(); s++) {
                if (start_with(babbling[i], strs[s])) {
                    babbling[i] = babbling[i]
                        .substr(strs[s].length(), babbling[i].length() - strs[s].length());
                    sum++;
                }
            }
            if (len == babbling[i].length()) {
                break;
            }
            if (babbling[i].length() == 0) {
                answer++;
                break;
            }
        }
    }
    return answer;
}