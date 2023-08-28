#include <string>
#include <vector>

using namespace std;

bool prime(int n) {
    if (n == 1 || n == 2) {
        return true;
    }
    else if (n % 2 == 0) {
        return false;
    }
    for (int a = 2; a < n / 2; a++) {
        if (n % a == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for (int i = 4; i <= n; i++) {
        if (!prime(i)) {
            answer++;
        }
    }
    return answer;
}