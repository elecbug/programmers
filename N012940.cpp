#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
    if (n % m == 0) {
        return m;
    }
    return gcd(m, n % m);
}

vector<int> solution(int n, int m) {
    if (n < m) {
        n ^= m ^= n ^= m;
    }
    vector<int> answer = vector<int>(2);
    answer[0] = gcd(n, m);
    answer[1] = n * m / answer[0];
    return answer;
}