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

map<int, struct TreapNode*> nodeMap;

struct TreapNode {
    int value;
    int priority;
    int subtreeSize;

    TreapNode *left;
    TreapNode *right;
    TreapNode *parent;

    TreapNode(int v):
        value(v),
        priority(rand()),
        subtreeSize(1),
        left(nullptr),
        right(nullptr),
        parent(nullptr) {
        nodeMap[v] = this;
    }
};

int getSubtreeSize(TreapNode* node){
    if(node) return node->subtreeSize;
    else return 0;
}

void updateSubtreeSize(TreapNode* node){
    if(node) {
        node->subtreeSize = 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }
}

void setParent(TreapNode* child, TreapNode* parent) {
    if (child) child->parent = parent;
}

void splitByPosition(TreapNode* current, int leftSize, TreapNode*& leftTreap, TreapNode*& rightTreap){
    if(!current){
        leftTreap = nullptr;
        rightTreap = nullptr;
        return;
    }

    if(getSubtreeSize(current->left) >= leftSize){
        splitByPosition(
            current->left,
            leftSize,
            leftTreap,
            current->left
        );
        setParent(current->left, current);
        rightTreap = current;
    } else {
        splitByPosition(
            current->right,
            leftSize - getSubtreeSize(current->left) - 1,
            current->right,
            rightTreap
        );
        setParent(current->right, current);
        leftTreap = current;
    }

    updateSubtreeSize(current);
}

TreapNode* mergeTreaps(TreapNode* leftTreap, TreapNode* rightTreap) {
    if (!leftTreap || !rightTreap)
        return leftTreap ? leftTreap : rightTreap;

    if (leftTreap->priority > rightTreap->priority) {
        leftTreap->right = mergeTreaps(leftTreap->right, rightTreap);
        setParent(leftTreap->right, leftTreap);
        updateSubtreeSize(leftTreap);
        return leftTreap;
    } else {
        rightTreap->left = mergeTreaps(leftTreap, rightTreap->left);
        setParent(rightTreap->left, rightTreap);
        updateSubtreeSize(rightTreap);
        return rightTreap;
    }
}

int findPosition(int targetValue) {
    TreapNode* node = nodeMap[targetValue];
    int pos = getSubtreeSize(node->left);
    while (node->parent) {
        if (node == node->parent->right) {
            pos += getSubtreeSize(node->parent->left) + 1;
        }
        node = node->parent;
    }
    return pos;
}

inline void solve(){
    int n;
    cin >> n;

    vi v(n);
    FO(i,n) cin >> v[i];

    // Clear nodeMap for each test case
    nodeMap.clear();

    // Init treap
    TreapNode* root = nullptr;

    FO(i,n){
        root = mergeTreaps(root, new TreapNode(v[i]));
    }
    if (root) root->parent = nullptr;

    vi res(n);
    int cut, pos;
    TreapNode *leftPart, *rightPart;
    TreapNode *removedCard, *remaining;

    for(int val = n; val > 0; val--){
        // Find position of card val
        pos = findPosition(val);
        if(pos == 0){
            cut = val;
        } else {
            cut = val - pos;
        }

        // Store cut value in result
        res[val-1] = cut;

        // Rotate 
        leftPart = nullptr;
        rightPart = nullptr;
        splitByPosition(
            root,
            val - cut,
            leftPart,
            rightPart
        );
        root = mergeTreaps(rightPart, leftPart);
        if (root) root->parent = nullptr;

        // Remove first card
        removedCard = nullptr;
        remaining = nullptr;
        splitByPosition(root, 1, removedCard, remaining);
        root = remaining;
        if (root) root->parent = nullptr;
    }

    TR(x, res){
        cout << x << " ";
    }
    cout << endl;

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
