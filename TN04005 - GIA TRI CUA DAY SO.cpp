#include <bits/stdc++.h>
using namespace std;

/*
  Tính:
    Ans = (sum over all subarrays of max) - (sum over all subarrays of min).
  Áp dụng công thức monotonic-stack như đã mô tả ở trên.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // Mảng lưu các chỉ số biên trái/phải
    vector<int> Lg(N+1), Rg(N+1), Ls(N+1), Rs(N+1);

    // --- Tính Lg[i] = chỉ số gần nhất < i sao cho A[j] > A[i]. Nếu không có, Lg[i]=0 ---
    {
        stack<int> st;
        for(int i = 1; i <= N; i++) {
            while(!st.empty() && A[st.top()] <= A[i]) {
                st.pop();
            }
            Lg[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
    }

    // --- Tính Rg[i] = chỉ số gần nhất > i sao cho A[j] >= A[i]. Nếu không có, Rg[i]=N+1 ---
    {
        stack<int> st;
        for(int i = N; i >= 1; i--) {
            // Dùng điều kiện A[st.top()] < A[i] (pop những phần tử < A[i]) 
            // để khi dừng lại, phần tử trên đỉnh là ≥ A[i]
            while(!st.empty() && A[st.top()] < A[i]) {
                st.pop();
            }
            Rg[i] = st.empty() ? (N+1) : st.top();
            st.push(i);
        }
    }
    // --- Tính Ls[i] = chỉ số gần nhất < i sao cho A[j] < A[i]. Nếu không có, Ls[i]=0 ---
    {
        stack<int> st;
        for(int i = 1; i <= N; i++) {
            while(!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            Ls[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
    }

    // --- Tính Rs[i] = chỉ số gần nhất > i sao cho A[j] <= A[i]. Nếu không có, Rs[i]=N+1 ---
    {
        stack<int> st;
        for(int i = N; i >= 1; i--) {
            while(!st.empty() && A[st.top()] > A[i]) {
                st.pop();
            }
            Rs[i] = st.empty() ? (N+1) : st.top();
            st.push(i);
        }
    }
    // for (int i = 1; i <= N; ++i) cerr << Rs[i] << ' ';

    // Tính S_max và S_min bằng __int128 để tránh tràn khi N lớn
    __int128 Smax = 0, Smin = 0;
    for(int i = 1; i <= N; i++) {
        // S_max += A[i] * (i - Lg[i]) * (Rg[i] - i)
        __int128 leftCnt  = i - (long long)Lg[i];
        __int128 rightCnt = (long long)Rg[i] - i;
        Smax += (__int128)A[i] * leftCnt * rightCnt;

        // S_min += A[i] * (i - Ls[i]) * (Rs[i] - i)
        __int128 leftCnt2  = i - (long long)Ls[i];
        __int128 rightCnt2 = (long long)Rs[i] - i;
        Smin += (__int128)A[i] * leftCnt2 * rightCnt2;
    }

    __int128 ans = Smax - Smin;

    // In __int128 ra chuỗi
    long long sign = (ans < 0 ? -1 : 1);
    if(ans < 0) ans = -ans;
    string out;
    while(ans > 0) {
        int digit = (int)(ans % 10);
        out.push_back(char('0' + digit));
        ans /= 10;
    }
    if(out.empty()) out = "0";
    if(sign < 0) out.push_back('-');
    reverse(out.begin(), out.end());

    cout << out << "\n";
    return 0;
}
