#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int temp = s / n;
    int plus_one = s % n;
    if (temp == 0) {
        answer.push_back(-1);
        return answer;
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (j < plus_one) {
            answer.push_back(temp + 1);
            j++;
        }
        else {
            answer.insert(answer.begin(), temp);
        }
    }
    return answer;
}