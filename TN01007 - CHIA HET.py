for _ in range(int(input())):
    a, b = map(int, input().split())
    print("YES" if a % b == 0 or b % a == 0 else "NO")