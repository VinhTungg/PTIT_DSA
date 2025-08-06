n = input()

while len(n) > 1:
    tmp = int(n[0:len(n)//2]) + int(n[len(n)//2:])
    n = str(tmp)
    print(n)
