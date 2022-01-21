#include <iostream>
#include <unordered_set>
#include <climits>

using namespace std;

string s = "thequickbrownfoxjumpsoverthehighbridge";

string_words[] = {"the", "fox", "over", "bridge", "high", "tall", "quick", "brown"};

int min_bars_helper(string s, string words[], int idx, unordered_set<string> &m){
    if(s[idx] == '\0'){
        return 0;
    }
    
    int ans = INT_MAX;
    string current_string = "";

    for(int j = idx; s[j] != '\0'; j++){
        current_string += s[j];

        if(m.find(current_string) != m.end()){
            int remaining_ans = min_bars_helper(s, words, j + 1, m);
            if(remaining_ans != -1){
                ans = min(ans, 1 + remaining_ans);
            }
        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int min_bars(){
    unordered_set<string> m;

    for(string w : words){
        m.insert(w);
    }

    int output = min_bars_helper(s, words, 0, min);
    return output - 1;
}

int main(){
    cout << min_bars() << endl;
    return 0;
}
