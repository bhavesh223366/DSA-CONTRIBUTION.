#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    //  Brute Force (Sort)
    void merge_brute(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;

        for(int i = 0; i < m; i++) temp.push_back(nums1[i]);
        for(int i = 0; i < n; i++) temp.push_back(nums2[i]);

        sort(temp.begin(), temp.end());

        for(int i = 0; i < m + n; i++) nums1[i] = temp[i];
    }

    // . Better (Two Pointer + Extra Array)
    void merge_better(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i = 0, j = 0;

        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i++]);
            } else {
                temp.push_back(nums2[j++]);
            }
        }

        while(i < m) temp.push_back(nums1[i++]);
        while(j < n) temp.push_back(nums2[j++]);

        for(int k = 0; k < m + n; k++) {
            nums1[k] = temp[k];
        }
    }

    // Optimal (3 Pointers from End) ⭐
    void merge_optimal(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j >= 0) {
            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }

    // Gap Method (Shell Sort Concept)
    void merge_gap(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Copy nums2 into nums1
        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        int len = m + n;
        int gap = (len + 1) / 2;

        while(gap > 0) {
            int i = 0;
            int j = gap;

            while(j < len) {
                if(nums1[i] > nums1[j]) {
                    swap(nums1[i], nums1[j]);
                }
                i++;
                j++;
            }

            if(gap == 1) break;
            gap = (gap + 1) / 2;
        }
    }
};

void printArray(vector<int>& arr) {
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    Solution sol;

    vector<int> base1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3, n = 3;

    // Brute
    vector<int> nums1 = base1;
    sol.merge_brute(nums1, m, nums2, n);
    cout << "Brute: ";
    printArray(nums1);

    //  Better
    nums1 = base1;
    sol.merge_better(nums1, m, nums2, n);
    cout << "Better: ";
    printArray(nums1);

    // Optimal
    nums1 = base1;
    sol.merge_optimal(nums1, m, nums2, n);
    cout << "Optimal: ";
    printArray(nums1);

    // Gap Method
    nums1 = base1;
    sol.merge_gap(nums1, m, nums2, n);
    cout << "Gap Method: ";
    printArray(nums1);

    return 0;
}
