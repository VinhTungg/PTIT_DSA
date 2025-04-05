t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    l, r, cnt = 0, 1, 0
    while r < n and l <= r:
        if arr[r] - arr[l] < k:
            cnt += (r - l)
            r += 1
        else: l += 1
    print(cnt)