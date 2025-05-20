#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;

struct Node {
    int val;
    Node *left, *right;
    Node (int x) {
        val = x;
        left = right = NULL;
    }
};

void buildTree(Node *&root, int val) {
    if (!root) root = new Node(val);
    else {
        if (root->val > val) buildTree(root->left, val);
        else buildTree(root->right, val);
    }
}

void preOrder(Node *root) {
    if (!root) return;
    cout << root->val << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Node *root = NULL;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            buildTree(root, x);
        }
        preOrder(root);
        cout << endl;
    }
}