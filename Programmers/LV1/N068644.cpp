#include <string>
#include <vector>

using namespace std;

int binary_search(vector<int> arr, int element) {
    if (arr.size() == 0) {
        return 0;
    }
    if (arr[0] > element) {
        return 0;
    }
    else if (arr[arr.size() - 1] < element) {
        return arr.size();
    }
    int min = 0, max = arr.size();
    while (true) {
        if (arr[(max + min) / 2] < element) {
            min = (max + min) / 2;
        }    
        else if (arr[(max + min) / 2] > element) {
            max = (max + min) / 2;
        }
        else {
            return (max + min) / 2;
        }
        if (min + 1 == max) {
            return arr[min] == element ? min : max;
        }
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer = vector<int>();
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int idx = binary_search(answer, 
                    numbers[i] + numbers[j]);
            if (idx == answer.size()) {
                answer.push_back(numbers[i] + numbers[j]);
            }
            else if (answer[idx] != numbers[i] + numbers[j]) {
                answer.insert(answer.begin() + idx, 
                        numbers[i] + numbers[j]);
            }
        }
    }
    return answer;
}