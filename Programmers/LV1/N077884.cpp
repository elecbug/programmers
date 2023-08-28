#include <string>
#include <vector>

using namespace std;

bool is_square(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            return true;
        }
    }
    return false;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        if (is_square(i)) {
            answer -= i;
        }
        else {
            answer += i;
        }
    }
    return answer;
}