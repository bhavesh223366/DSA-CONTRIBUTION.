#include <iostream>
#include <vector>
using namespace std;

int main() {

    int arr[4] = {1, 4, 5, 6};
    int n = 4;

    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> ans(n);

    // Prefix
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    // Suffix
    for(int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * arr[i + 1];
    }

    // Final answer
    for(int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }

    // Print answer
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

// int arr[4] = {1, 4, 5, 6};
//     int n = 4;

//     vector<int> ans(n, 1);

//     // prefix product
//     int prefix = 1;
//     for(int i = 0; i < n; i++) {
//         ans[i] = prefix;
//         prefix *= arr[i];
//     }

//     // suffix product
//     int suffix = 1;
//     for(int i = n - 1; i >= 0; i--) {
//         ans[i] *= suffix;
//         suffix *= arr[i];
//     }

//     // print answer
//     for(int i = 0; i < n; i++) {
//         cout << ans[i] << " ";
//     }
