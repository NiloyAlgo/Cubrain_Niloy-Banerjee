#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Reverse nums[left..right] (inclusive) in place.
void reverseSegment(vector<int>& nums, int left, int right) {
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

// Rotate right by k steps in place. O(N) time, O(1) space.
void rotate(vector<int>& nums, long long k) {
    int n = nums.size();
    if (n == 0) return;
    k %= n;
    if (k == 0) return;
    reverseSegment(nums, 0, n - 1);   // 1. reverse whole array
    reverseSegment(nums, 0, k - 1);   // 2. reverse first k elements
    reverseSegment(nums, k, n - 1);   // 3. reverse remaining n-k elements
}

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Test { vector<int> nums; long long k; vector<int> expected; };
    vector<Test> tests = {
        {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
        {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
        {{1, 2}, 5, {2, 1}},
        {{1}, 10, {1}},
        {{1, 2, 3}, 0, {1, 2, 3}},
    };
    for (auto& t : tests) {
        vector<int> original = t.nums;
        rotate(t.nums, t.k);
        cout << (t.nums == t.expected ? "PASS " : "FAIL ");
        print(original); cout << " k=" << t.k << " -> "; print(t.nums); cout << "\n";
    }
    return 0;
}
