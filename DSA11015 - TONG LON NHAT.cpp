#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, maxSum;

struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

void insertNode(Node *root, int u, int v, char c) {
    if (root) {
        if (root->data == u) {
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        } else {
            insertNode(root->left, u, v, c);
            insertNode(root->right, u, v, c);
        }
    }
}

int DFS(Node *root) {
    if (!root) return 0;

    if (!root->left and !root->right) return root->data;

    int left = DFS(root->left);
    int right = DFS(root->right);

    if (root->left and root->right) {
        maxSum = max(maxSum, left + right + root->data);
        return max(left, right) + root->data;
    }
    return (root->left ? left : right) + root->data;
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        Node *root = NULL;
        for (int i = 0; i < n; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!root) {
                root = new Node(x);
                insertNode(root, x, y, z);
            } else insertNode(root, x, y, z);
        }
        maxSum = INT_MIN;
        DFS(root);
        cout << maxSum << endl;
    }
}