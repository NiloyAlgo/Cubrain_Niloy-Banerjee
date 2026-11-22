#include <iostream>
#include <vector>
using namespace std;

// Delete first occurrence of target by shifting left, then shrink by one.
// No erase()/remove(). O(N) time, O(1) space.
void deleteFirst(vector<int>& arr, int target) {
    int n = arr.size();
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) { idx = i; break; }
    }
    if (idx == -1) return;                 // not found: unchanged

    for (int i = idx; i < n - 1; i++)      // shift later elements left
        arr[i] = arr[i + 1];
    arr.pop_back();                        // shrink length by exactly one
}

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Test { vector<int> arr; int target; vector<int> expected; };
    vector<Test> tests = {
        {{10, 20, 30, 20, 40}, 20, {10, 30, 20, 40}},
        {{5, 15}, 99, {5, 15}},
        {{7}, 7, {}},
        {{}, 3, {}},
        {{4, 4, 4}, 4, {4, 4}},
    };
    for (auto& t : tests) {
        auto original = t.arr;
        deleteFirst(t.arr, t.target);
        cout << (t.arr == t.expected ? "PASS " : "FAIL ");
        print(original); cout << " target=" << t.target << " -> "; print(t.arr); cout << "\n";
    }
    return 0;
}
