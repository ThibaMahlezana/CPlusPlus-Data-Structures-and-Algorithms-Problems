#include <vector>

using namespace std;

int merge(vector<int> &arr, int s, int e){
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;
    int cnt = 0;

    while(i <= m and j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            cnt += (m - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= m){
        temp.push_back(arr[i++]);
    }
    while(j <= e) {
        temp.push_bak(arr[j++]);
    }

    int k = 0;
    for(int idx = s; idx <= e; idx++){
        arr[idx] = temp[k++];
    }
    return cnt;
}

int inversion_count(vector<int> &arr, int s, int e){
    if (s >= e){
        return 0;
    }
    int mid = (s + e) / 2;
    int C1 = inversion_count(arr, s, mid);
    int C2 = inversion_count(arr, mid + 1, e);
    int CI = merge(arr, s, e);
    return C1 + C2 + CI;
}

int main(){
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;
    cout << inversion_count(arr, s, e);
    cout << endl;
    return 0;
}