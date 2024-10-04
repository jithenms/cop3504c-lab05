#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<string> container, string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<string> container, string element) {
    int start = 0;
    int end = container.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (container[mid] == element) {
            return mid;
        }

        if (container[mid] < element) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<string> data = {"hello", "world", "test", "woah!"};
    vector<string> search = {"test", "nope!", "woah!"};
    for (int i = 0; i < search.size(); i++) {
        chrono::time_point start_lin = chrono::system_clock::now();
        int lin_pos = linearSearch(data, search[i]);
        chrono::time_point end_lin = chrono::system_clock::now();
        cout << "Linear Search - " << search[i] << " - " << lin_pos << endl;

        chrono::time_point start_bin = chrono::system_clock::now();
        int bin_pos = binarySearch(data, search[i]);
        chrono::time_point end_bin = chrono::system_clock::now();
        cout << "Binary Search - " << search[i] << " - " << bin_pos << endl;
    }
    return 0;
}