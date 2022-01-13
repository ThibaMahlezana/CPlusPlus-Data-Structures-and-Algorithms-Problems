#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int largestBand(vector<int> arr){
    int n = arr.size();
    unordered_set<int> s;

    for(int x : arr){
        s.insert(x);
    }

    int largestLen = 1;

    for(auto element : s){
        int parent = element - 1;

        if(s.find(parent) == s.end()){
            int next_no = element + 1;
            int count = 1;

            while(s.find(next_no) != s.end()){
                next_no++;
                count++;
            }

            if(count > largestLen){
                largestLen = count;
            }
        }
    }
    return largestLen;
}

int main(){
    vector<int> arr{1, 9, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << largestBand(arr) << endl;

    return 0;
}