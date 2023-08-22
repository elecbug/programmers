#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> num = vector<int>(10000000);
    for (int i = 0; i < tangerine.size(); i++) {
        num[tangerine[i] - 1]++;
    }
    sort(num.begin(), num.end());
    for (int i = num.size() - 1; i >= 0; i--) {
        k -= num[i];
        answer++;
        if (k <= 0) {
            break;
        }
    }
    return answer;
}