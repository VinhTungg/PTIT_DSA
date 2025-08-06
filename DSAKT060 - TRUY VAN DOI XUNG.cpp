#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const long long BASE = 31;
const long long MOD = 1e9 + 7;

class SegmentTree {
private:
    int n;
    vector<long long> tree_hash;  // Hash thuận
    vector<long long> tree_rev;   // Hash nghịch
    vector<long long> tree_pow;   // Lũy thừa của BASE
    vector<long long> pow_base;   // Precomputed powers
    
    void build(string& s, int node, int start, int end) {
        if (start == end) {
            // Node lá
            tree_hash[node] = s[start] - '0';
            tree_rev[node] = s[start] - '0';
            tree_pow[node] = 1;
        } else {
            int mid = (start + end) / 2;
            build(s, 2*node, start, mid);
            build(s, 2*node+1, mid+1, end);
            
            // Merge hash thuận: left + right * pow(BASE, len_left)
            int len_left = mid - start + 1;
            tree_hash[node] = (tree_hash[2*node] + 
                              (tree_hash[2*node+1] * pow_base[len_left]) % MOD) % MOD;
            
            // Merge hash nghịch: right + left * pow(BASE, len_right)
            int len_right = end - mid;
            tree_rev[node] = (tree_rev[2*node+1] + 
                             (tree_rev[2*node] * pow_base[len_right]) % MOD) % MOD;
            
            tree_pow[node] = pow_base[end - start + 1];
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree_hash[node] = val;
            tree_rev[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            
            // Merge lại sau khi update
            int len_left = mid - start + 1;
            tree_hash[node] = (tree_hash[2*node] + 
                              (tree_hash[2*node+1] * pow_base[len_left]) % MOD) % MOD;
            
            int len_right = end - mid;
            tree_rev[node] = (tree_rev[2*node+1] + 
                             (tree_rev[2*node] * pow_base[len_right]) % MOD) % MOD;
        }
    }
    
    pair<long long, long long> query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {0, 0};
        }
        if (l <= start && end <= r) {
            return {tree_hash[node], tree_rev[node]};
        }
        
        int mid = (start + end) / 2;
        auto left = query(2*node, start, mid, l, r);
        auto right = query(2*node+1, mid+1, end, l, r);
        
        if (left.first == 0) return right;
        if (right.first == 0) return left;
        
        // Merge hash thuận
        int len_left = min(mid, r) - max(start, l) + 1;
        if (max(start, l) > mid) len_left = 0;
        
        long long hash_forward = (left.first + 
                                 (right.first * pow_base[len_left]) % MOD) % MOD;
        
        // Merge hash nghịch
        int len_right = min(end, r) - max(mid+1, l) + 1;
        if (max(mid+1, l) > end) len_right = 0;
        
        long long hash_backward = (right.second + 
                                  (left.second * pow_base[len_right]) % MOD) % MOD;
        
        return {hash_forward, hash_backward};
    }
    
public:
    SegmentTree(string& s) {
        n = s.length();
        tree_hash.resize(4 * n);
        tree_rev.resize(4 * n);
        tree_pow.resize(4 * n);
        
        // Precompute powers of BASE
        pow_base.resize(n + 1);
        pow_base[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow_base[i] = (pow_base[i-1] * BASE) % MOD;
        }
        
        build(s, 1, 0, n-1);
    }
    
    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
    
    bool isPalindrome(int l, int r) {
        auto result = query(1, 0, n-1, l, r);
        return result.first == result.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    SegmentTree st(s);
    
    int q;
    cin >> q;
    
    while (q--) {
        char type;
        cin >> type;
        
        if (type == 'q') {
            int l, r;
            cin >> l >> r;
            l--; r--; // Convert to 0-based
            
            if (st.isPalindrome(l, r)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        else if (type == 'c') {
            int pos;
            char newChar;
            cin >> pos >> newChar;
            pos--; // Convert to 0-based
            
            st.update(pos, newChar - '0');
        }
    }
    
    return 0;
}

/*
Ý tưởng Segment Tree cho Palindrome:

1. Mỗi node lưu:
   - Hash thuận của đoạn
   - Hash nghịch của đoạn
   - Độ dài đoạn (để tính pow)

2. Kiểm tra palindrome:
   - Tính hash thuận và nghịch của đoạn [l,r]
   - So sánh: nếu bằng nhau thì là palindrome

3. Hash function:
   - Hash thuận: h = a[0] + a[1]*BASE + a[2]*BASE^2 + ...
   - Hash nghịch: h = a[n-1] + a[n-2]*BASE + a[n-3]*BASE^2 + ...

4. Độ phức tạp:
   - Build: O(N)
   - Update: O(log N)
   - Query: O(log N)
   - Tổng: O(N + Q*log N)

Test với input mẫu:
s = "12345"
q 1 5: Hash("12345") thuận ≠ nghịch → NO
q 5 5: Hash("5") thuận = nghịch → YES  
c 4 3: s = "12335"
q 3 5: Hash("335") thuận ≠ nghịch → NO
q 3 4: Hash("33") thuận = nghịch → YES
*/