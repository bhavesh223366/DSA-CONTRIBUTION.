#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {

    unordered_map<int, int> m;

    for(int i = 0; i < arr.size(); i++) {

        int first = arr[i];
        int sec = target - first;


        if(m.find(sec) != m.end()) {

            return {m[sec], i};
        }

        m[first] = i;
    }

    return {};
}

int main() {

    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(arr, target);

    cout << "Indices are: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
