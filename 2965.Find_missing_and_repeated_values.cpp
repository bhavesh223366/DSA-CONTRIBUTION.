#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
LeetCode 2965: Find Missing and Repeated Values
===========================================================
*/


// ===========================================================
// 🔹 Approach 1: Frequency Array (EASIEST)
// Time: O(n^2), Space: O(n^2)
// ===========================================================
vector<int> approach1(vector<vector<int>>& grid) {
    int n = grid.size();
    int N = n * n;

    vector<int> freq(N + 1, 0);

    // Count frequency
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            freq[num]++;
        }
    }

    int repeat = -1;
    int missing = -1;

    // Find answer
    for (int i = 1; i <= N; i++) {
        if (freq[i] == 2) repeat = i;
        if (freq[i] == 0) missing = i;
    }

    return {repeat, missing};
}


// ===========================================================
// 🔹 Approach 2: HashSet + Sum
// Time: O(n^2), Space: O(n^2)
// ===========================================================
vector<int> approach2(vector<vector<int>>& grid) {
    int n = grid.size();
    int N = n * n;

    unordered_set<int> st;
    long long sum = 0;
    int repeat = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];

            if (st.count(num)) {
                repeat = num;
            }

            st.insert(num);
            sum += num;
        }
    }

    long long expected = 1LL * N * (N + 1) / 2;
    int missing = expected - (sum - repeat);

    return {repeat, missing};
}


// ===========================================================
// 🔹 Approach 3: Mathematical (Optimal)
// Time: O(n^2), Space: O(1)
// ===========================================================
vector<int> approach3(vector<vector<int>>& grid) {
    int n = grid.size();
    int N = n * n;

    long long sum = 0;
    long long sqSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            sum += num;
            sqSum += 1LL * num * num;
        }
    }

    long long expectedSum = 1LL * N * (N + 1) / 2;
    long long expectedSqSum = 1LL * N * (N + 1) * (2 * N + 1) / 6;

    long long sumDiff = sum - expectedSum;       // x - y
    long long sqDiff = sqSum - expectedSqSum;    // x^2 - y^2

    long long sumXY = sqDiff / sumDiff;          // x + y

    int repeat = (sumDiff + sumXY) / 2;
    int missing = repeat - sumDiff;

    return {repeat, missing};
}


// ===========================================================
// 🔹 Approach 4: Sorting
// Time: O(n^2 log n), Space: O(n^2)
// ===========================================================
vector<int> approach4(vector<vector<int>>& grid) {
    vector<int> arr;

    int n = grid.size();

    // Flatten grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr.push_back(grid[i][j]);
        }
    }

    sort(arr.begin(), arr.end());

    int repeat = -1;
    int missing = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            repeat = arr[i];
        }

        if (arr[i] > arr[i - 1] + 1) {
            missing = arr[i - 1] + 1;
        }
    }

    if (arr[arr.size() - 1] != arr.size()) {
        missing = arr.size();
    }

    return {repeat, missing};
}


// ===========================================================
// 🔹 Approach 5: XOR (Advanced)
// Time: O(n^2), Space: O(1)
// ===========================================================
vector<int> approach5(vector<vector<int>>& grid) {
    int n = grid.size();
    int N = n * n;

    int xr = 0;

    // XOR grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            xr ^= grid[i][j];
        }
    }

    // XOR 1 to N
    for (int i = 1; i <= N; i++) {
        xr ^= i;
    }

    // Rightmost set bit
    int bit = xr & (-xr);

    int x = 0;
    int y = 0;

    // Divide into 2 groups
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] & bit) x ^= grid[i][j];
            else y ^= grid[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        if (i & bit) x ^= i;
        else y ^= i;
    }

    // Check which is repeated
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == x) count++;
        }
    }

    if (count == 2) return {x, y};
    else return {y, x};
}


// ===========================================================
// 🔹 MAIN FUNCTION
// ===========================================================
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 👉 Change here to test any approach
    vector<int> ans = approach1(grid);

    cout << "Repeated: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;

    return 0;
}
