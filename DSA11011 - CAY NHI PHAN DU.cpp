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
    int data;
    Node *right, *left;
    Node (int x) {
        data = x;
        right = left = NULL;
    }
};

void insertNode (Node *root, int u, int v, char c) {
    if (root) {
        if (root->data == u) {
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        }else {
            insertNode(root->left, u, v, c);
            insertNode(root->right, u, v, c);
        }
    }
}

int check(Node *root) {
    if (!root) return 1;
    if ((!root->left and root->right) or (!root->right and root->left)) return 0;
    return check(root->left) and check(root->right);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Node *root = NULL;
        for (int i = 1; i <= n; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!root) {
                root = new Node(x);
                insertNode(root, x, y, z);
            } else insertNode(root, x, y, z);
        }
        cout << check(root) << endl;
    }
}