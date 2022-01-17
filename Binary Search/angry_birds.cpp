#include <iostream>

using namespace std;

bool canPlaceBirds(int B, int N, vector<int> nests, int sep){
    int birds = 1;
    int location = nests[0];

    for(int i = 1; i <= n - 1; i++){
        int current_location = nests[i];
        if(current_location - location >= sep){
            birds++;
            location = current_location;

            if(birds == B){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int B = 3;
    vector<int> nests{1, 2, 4, 8, 9};
    sort(nests.begin(), nests.end());
    int N = nests.size();

    int s = 0;
    int e = nests[N - 1] - nests[0];
    int ans = -1;

    while(s <= e){
        int mid = (s + e) / 2;

        bool canPlaceBirds(B, N, nests, mid);
        if(canPlaceBirds){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}