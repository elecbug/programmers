#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    for (int i = 0; i < dic.size(); i++) {
        bool* check = new bool[spell.size()];
        for (int j = 0; j < dic[i].length(); j++) {
            for (int k = 0; k < spell.size(); k++) {
                if (dic[i][j] == spell[k][0]) {
                    check[k] = false;
                }
            }
        }
        bool check_all = false;
        for (int j = 0; j < spell.size(); j++) {
            check_all |= check[j];
        }
        if (!check_all && spell.size() == dic[i].length()) {
            return 1;
        }
    }
    return 2;
}