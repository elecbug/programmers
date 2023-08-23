#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void merge(string& arr, int left, int right) {
	int mid = (right + left) / 2;
	if (right > left) {
		merge(arr, left, mid);
		merge(arr, mid + 1, right);
		char* temp = (char*)malloc(sizeof(int) * (right - left + 1));
		int i = left, j = mid + 1, k = 0;
		while (i <= mid && j <= right) {
			if (arr[i] > arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (k < right - left + 1) {
			if (i <= mid)
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		for (int in = 0; in < right - left + 1; in++) {
			arr[in + left] = temp[in];
		}
		free(temp);
	}
}

string solution(string s) {
    merge(s, 0, s.length() - 1);
    return s;
}