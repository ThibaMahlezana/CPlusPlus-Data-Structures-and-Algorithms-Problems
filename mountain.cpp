#include <iostream>

using namespace std;

int highest_mountain(vector<int> arr){
    int n = arr.size();
    int largest = 0;

    for (int i = 1; i < n-2;){
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
            int count = 1;
            int j = i;

            while(j >= 1 && arr[j] > arr[j - 1]){
                j--;
                count++;
            }
            while(i <= n - 2 && arr[i] > arr[i + 1]){
                i++;
                count++;
            }
            largest = max(largerst, count);
        }
        else {  i++; }
    }
    return largest;
}

int main(){
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 3, -2, 4};

    cout << highest_mountain(arr) << endl;
    return 0;
}