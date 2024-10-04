#include <iostream>
#include <vector>
#include "StringData.h"

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
    vector<string> data = getStringData();
    vector<string> search = {"not_here", "mzzzz", "aaaaa"};
    for (int i = 0; i < search.size(); i++) {
        chrono::time_point start_lin = chrono::system_clock::now();
        int lin_pos = linearSearch(data, search[i]);
        chrono::time_point end_lin = chrono::system_clock::now();
        std::chrono::duration<double> elapsed_lin = end_lin - start_lin;
        cout << "Linear Search - " << search[i] << " - " << lin_pos << " - " << elapsed_lin << endl;

        chrono::time_point start_bin = chrono::system_clock::now();
        int bin_pos = binarySearch(data, search[i]);
        chrono::time_point end_bin = chrono::system_clock::now();
        std::chrono::duration<double> elapsed_bin = end_bin - start_bin;
        cout << "Binary Search - " << search[i] << " - " << bin_pos << " - " << elapsed_bin << endl;
    }
    return 0;
}