#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int count_triangles(vector<pair<int, int>> &points){
    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;

    for(auto p : points){
        int x = p.first;
        int y = p.second;
        freq_x++;
        freq_y++;
    }

    int count = 0;
    for(auto p : points){
        int x = p.first;
        int y = p.second;

        int fx = freq_x[x];
        int fy = freq_y[y];

        count += (fx - 1) * (fy - 1);
    }
    return count;
}

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> points;

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    cout << count_triangles(points);

    return 0;
}