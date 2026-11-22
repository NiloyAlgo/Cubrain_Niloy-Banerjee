#include <iostream>
#include <vector>
using namespace std;

// Each element becomes the sum of elements strictly to its right.
// Single right-to-left pass. O(N) time, O(1) space.
void suffixSumInPlace(vector<long long>& arr) {
    long long running = 0;
    for (int i = (int)arr.size() - 1; i >= 0; i--) {
        long long current = arr[i];   // save before overwriting
        arr[i] = running;
        running += current;
    }
}

void print(const vector<long long>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Test { vector<long long> arr, expected; };
    vector<Test> tests = {
        {{10, 4, 8, 3}, {15, 11, 3, 0}},
        {{5}, {0}},
        {{}, {}},
        {{-2, 5, -1}, {4, -1, 0}},
        {{1, 2, 3, 4}, {9, 7, 4, 0}},
    };
    for (auto& t : tests) {
        auto original = t.arr;
        suffixSumInPlace(t.arr);
        cout << (t.arr == t.expected ? "PASS " : "FAIL ");
        print(original); cout << " -> "; print(t.arr); cout << "\n";
    }
    return 0;
}
