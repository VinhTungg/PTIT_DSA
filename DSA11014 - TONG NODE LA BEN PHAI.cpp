#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, res;

struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

void order(Node *root, int mark = 0) {
    if (!root) return;
    if (!root->left and !root->right and mark) {
        res += root->data;
    }
    order(root->left, 0);
    order(root->right, 1);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Node *root = NULL;
        unordered_map<int, Node*> mp;
        for (int i = 0; i < n; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!root) {
                root = new Node(x);
                mp[x] = root;
                if (z == 'L') {
                    mp[x]->left = new Node(y);
                    mp[y] = mp[x]->left;
                } else {
                    mp[x]->right = new Node(y);
                    mp[y] = mp[x]->right;
                }
            } else {
                if (z == 'L') {
                    mp[x]->left = new Node(y);
                    mp[y] = mp[x]->left;
                } else {
                    mp[x]->right = new Node(y);
                    mp[y] = mp[x]->right;
                }
            }
        }
        res = 0;
        order(root);
        cout << res << endl;
        free(root);
    }
}