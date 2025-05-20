#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, maxLen;

struct Node {
    int val;
    Node *left, *right;
    Node (int x) {
        val = x;
        left = right = NULL;
    }
};

void build(Node *&root, int val) {
    if (!root) root = new Node(val);
    else {
        if (root->val > val) build(root->left, val);
        else build(root->right, val);
    }
}

bool isLeaf(Node *root) {
    return !root->left and !root->right;
}

void order(Node *root, int cnt = 0) {
    if (!root) return;
    if (isLeaf(root)) {
        maxLen = max(maxLen, cnt);
    }
    if (root->left) order(root->left, cnt + 1);
    if (root->right) order(root->right, cnt + 1);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n, x; cin >> n;
        Node *root = NULL;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            build(root, x);
        }
        maxLen = 0;
        order(root);
        cout << maxLen << endl;
    }
}