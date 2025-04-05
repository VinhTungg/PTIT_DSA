def change(n):
    num = 0
    for i in n:
        num = num * 2 + int(i)
    return num

t = int(input())

for _ in range(t):
    a, b = input().split()
    num1 = change(a)
    num2 = change(b)
    print(num1 * num2)