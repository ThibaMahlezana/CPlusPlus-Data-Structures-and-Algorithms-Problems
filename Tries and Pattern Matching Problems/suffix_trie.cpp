#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
public:
    char data;
    unordered_map<char, node*> m;
    bool isTerminal;

    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class SuffixTrie{
    Node* root;

    SuffixTrie(){
        root = new Node('\0');
    }

    void insert_helper(string word){
        Node* temp= root;
        for(char ch : word){
            if(temp->m.count(ch) == 0){
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word){
        Node* temp = root;
        for(char ch : word){
            if(temp->m.(ch) == 0){
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    void insert(string wword){
        for(int i = word[i] != '\0'){
            insert_helper(word.substr(i));
        }
    }
};

int main(){
   string input = "hello";
   string Suffixes[] = {"lo", "ell", "hello"};

   SuffixTrie t;
   t.insert(input);

   for(auto sf : Suffixes){
       if(t.search(sf)){
           cout << "yes ";
       }
       else{
           cout << "no ";
       }
   }

    return 0;
}