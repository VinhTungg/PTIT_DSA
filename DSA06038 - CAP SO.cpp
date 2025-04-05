#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;
int t = 1;

int merge(vector<int> &a, int l, int m, int r){
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l, cnt = 0;
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j])
            a[k++] = left[i++];
        else{
            cnt += left.size() - i;
            a[k++] = right[j++];
        }
    }
    while(i < left.size()) a[k++] = left[i++];
    while(j < right.size()) a[k++] = right[j++];
    return cnt;
}

int mergeSort(vector<int> &a, int l, int r){
    int cnt = 0;
    if(l < r){
        int m = (l + r) >> 1;
        cnt += mergeSort(a, l, m);
        cnt += mergeSort(a, m + 1, r);
        cnt += merge(a, l, m, r);
    }
    return cnt;
}

int main(){
    boost;
    while(t--){
        int n; 
        cin >> n;
        vector<int> a(n), evens;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(!(a[i] & 1))
                evens.push_back(a[i]);
        }
        int res = 0;
        if(!evens.empty()) res = mergeSort(evens, 0, evens.size() - 1);
        int subtract = 0;
        int i = 0;
        for(int i = 0; i < n; ++i){
            if(!(a[i] & 1)){
                vector<int> block;
                block.push_back(a[i]);
                for(int j = i + 1; j < n and !(a[j] & 1); ++j) block.push_back(a[j]);
                if(block.size() > 1) subtract += mergeSort(block, 0, block.size() - 1);
                i += block.size();
            }
        }
        cout << res - subtract << endl;
    }
    return 0;
}
