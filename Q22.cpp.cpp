#include <iostream>
#include <vector>
using namespace std;

// Merge nums2 into nums1 in place, filling from the back so no unread value
// in nums1 is overwritten. O(M+N) time, O(1) space.
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;          // last real element of nums1
    int j = n - 1;          // last element of nums2
    int write = m + n - 1;  // last slot of nums1

    while (j >= 0) {        // when nums2 is exhausted, nums1's rest is in place
        if (i >= 0 && nums1[i] > nums2[j]) nums1[write--] = nums1[i--];
        else                               nums1[write--] = nums2[j--];
    }
}

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Test { vector<int> nums1; int m; vector<int> nums2; int n; vector<int> expected; };
    vector<Test> tests = {
        {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
        {{0}, 0, {1}, 1, {1}},
        {{1}, 1, {}, 0, {1}},
        {{4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3, {1, 2, 3, 4, 5, 6}},
        {{1, 3, 5, 0, 0}, 3, {2, 4}, 2, {1, 2, 3, 4, 5}},
    };
    for (auto& t : tests) {
        auto original = t.nums1;
        merge(t.nums1, t.m, t.nums2, t.n);
        cout << (t.nums1 == t.expected ? "PASS " : "FAIL ");
        print(original); cout << " -> "; print(t.nums1); cout << "\n";
    }
    return 0;
}
