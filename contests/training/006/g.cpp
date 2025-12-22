#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

class TrieNode {
public:
    bool endofWord;
    TrieNode* children[26];

    TrieNode()
    {
        endofWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// class for the Trie implementation
class Trie {
private:
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    TrieNode* getRoot()
    {
        return root;
    }

    void insert(string word)
    {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->endofWord = true;
    }

    // Return pointer to the next node when searching for a character
    // If not valid children, it returns nullptr
    TrieNode* next_node(char c, TrieNode* node){
        return node->children[c - 'a'];
    }
};


inline void solve(){
    string s; cin >> s;
    int n; cin >> n;

    Trie trie;
    string temp;
    
    FO(i,n){
        cin >> temp;
        trie.insert(temp);
    }

    vector<int> dp(s.size() + 1, false);
    dp[0] = true;
    TrieNode* node;

    // Try to create
    FO(i,sz(s)){
        if(!dp[i]) continue;

        node = trie.getRoot();
        for(int j=i; j<sz(s); j++){
            node = trie.next_node(s[j], node);
            
            // If no following node, stop
            if(node == nullptr){
                break;
            }

            // If the end of the word, you can start searching on the next one
            if(node->endofWord){
                dp[j+1] = true;
            }
        }

    }

    // Check if the last accumulated string is empty (all words were completed)
    if(dp[s.size()]){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
