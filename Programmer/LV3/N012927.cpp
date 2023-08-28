#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heaping(vector<int>& works, int n) {
    if (works.size() > n * 2 + 1) {
        if (works.size() > n * 2 + 2) {
            int big = works[n * 2 + 1] >= works[n * 2 + 2] 
                ? n * 2 + 1 : n * 2 + 2;
            if (works[n] < works[big]){
                swap(works[n], works[big]);
                heaping(works, big);
            }
        }
        else if (works[n] < works[n * 2 + 1]) {
            swap(works[n], works[n * 2 + 1]);
            heaping(works, n * 2 + 1);
        }
    }
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    sort(works.begin(), works.end(), [](int x, int y)->bool{return x > y;});
    for (int i = 0; i < n; i++) {
        if (works[0] != 0) {
            works[0]--;
        }
        heaping(works, 0);
    }
    for (int i = 0; i < works.size(); i++) {
        answer += (long long)works[i] * (long long)works[i];
    }
    return answer;
}