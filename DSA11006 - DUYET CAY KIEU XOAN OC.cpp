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

void insertNode(Node *root, int u, int v, char c) {
    if (root != NULL) {
        if (root->data == u) {
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        } else {
            insertNode(root->left, u, v, c);
            insertNode(root->right, u, v, c);
        }
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Node *root = NULL;
        int u, v;
        char c;
        for (int i = 1; i <= n; ++i) {
            cin >> u >> v >> c;
            if (root == NULL) {
                root = new Node(u);
                insertNode(root, u, v, c);
            } else insertNode(root, u, v, c);
        }
        stack<Node*> pre, after;
        pre.push(root);
        while (pre.size() or after.size()) {
            while (pre.size()) {
                Node *top = pre.top();
                pre.pop();
                cout << top->data << ' ';
                if (top->right != NULL) after.push(top->right);
                if (top->left != NULL) after.push(top->left);
            }
            while (after.size()) {
                Node *top = after.top();
                after.pop();
                cout << top->data << ' ';
                if (top->left != NULL) pre.push(top->left);
                if (top->right != NULL) pre.push(top->right); 
            }
        }
        cout << endl;
    }
}