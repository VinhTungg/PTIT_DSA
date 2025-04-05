Catalan = [0] * 101

def init():
    Catalan[0] = 1
    for i in range(1, 101):
        for j in range(0, i):
            Catalan[i] += Catalan[j] * Catalan[i - j - 1]

t = int(input())
init()

for _ in range(t):
    n = int(input())
    print(Catalan[n])
