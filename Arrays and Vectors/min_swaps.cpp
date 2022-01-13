#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countMinSwaps(vector<int> arr){
    pair<int, int> ap[n];
    int n = arr.size();
    for(int i=0; i < n; i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    sort(ap, ap + n);

    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        int old_pos = ap[i].second;
        if(visited[i] == true or old_pos == i){
            continue;
        }

        int node = i;
        int cycle = 0;

        while(!visited[node]){
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main(){
    vector<int> arr{5, 4, 3, 2, 1};
    cout << countMinSwaps(arr) << endl;
    
    return 0;
}