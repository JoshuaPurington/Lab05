#include <chrono>
#include <string>
#include <iostream>
#include <vector>
#include "StringData.h"

using namespace std;

int linearSearch(const vector<string> &container, const string &element) {
    chrono::system_clock::time_point start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            // Show difference in time
            cout << "Linear Time: " << (chrono::high_resolution_clock::now() - start_time) << endl;
            return i;
        }
    }
    cout << "Linear Time: " << (chrono::high_resolution_clock::now() - start_time) << endl;
    return -1;
}

int binarySearch(const vector<string> &container, const string &element) {
    chrono::system_clock::time_point start_time = chrono::high_resolution_clock::now();
    int first_index = 0;
    int end_index = container.size() - 1;

    // While not all indices searched
    while (first_index <= end_index) {
        // Will automatically truncate due to integer division
        // Start in center
        int mid_index = (first_index + end_index) / 2;

        // Equality
        if (container[mid_index] == element) {
            cout << "Binary Time: " << (chrono::high_resolution_clock::now() - start_time) << endl;
            return mid_index;
        }
        if (container[mid_index] < element) {
            first_index = mid_index + 1;
        }
        else {
            end_index = mid_index - 1;
        }
    }

    cout << "Binary Time: " << (chrono::high_resolution_clock::now() - start_time) << endl;
    return -1;
}

int main() {
    const std::vector<std::string> container = getStringData();

    // Search for 'not_here'
    int linear_result = linearSearch(container, "not_here");
    cout << "Linear result for 'not_here' | Index: " << linear_result << endl;
    cout << '\n';
    int binary_result = binarySearch(container, "not_here");
    cout << "Binary result for 'not_here' | Index: " << binary_result << endl;

    cout << '\n';

    // Search for 'mzzzz'
    linear_result = linearSearch(container, "mzzzz");
    cout << "Linear result for 'mzzzz' | Index: " << linear_result << endl;
    cout << '\n';
    binary_result = binarySearch(container, "mzzzz");
    cout << "Binary result for 'mzzzz' | Index: " << binary_result << endl;

    cout << '\n';

    // Search for 'aaaaa'
    linear_result = linearSearch(container, "aaaaa");
    cout << "Linear result for 'aaaaa' | Index: " << linear_result << endl;
    cout << '\n';
    binary_result = binarySearch(container, "aaaaa");
    cout << "Binary result for 'aaaaa' | Index: " << binary_result << endl;

    return 0;
}
