#include <iostream>
using namespace std;

int main() {

    int arr[9] = {6,7,0,1,2,3,4,5,6};
    int n = 9;

    int target = 0;

    int start = 0;
    int end = n - 1;

    while(start <= end) {

        int mid = start + (end - start) / 2;
        
        if(arr[mid] == target) {
            cout << "Element found at index: " << mid;
            return 0;
        }

        if(arr[start] <= arr[mid]) {

            if(target >= arr[start] && target <= arr[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

     
        else {

            if(target >= arr[mid] && target <= arr[end]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    cout << "Element not found";

    return 0;
}
