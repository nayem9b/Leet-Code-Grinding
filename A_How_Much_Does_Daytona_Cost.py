test = int(input())

for tests in range(test):

nk = str(input())

    nkn = nk.split(' ')

    n = int(nkn[0])

    k = str(nkn[1])

    a = str(input())
    b = a.split(' ')
    c = list(b)

    t = 0
    s = 0

    for i in range (n):
        at = c[t]
        t = t + 1
        if at == k:
            print("YES")
            s = s + 1
            break
    if s == 0:
        print("NO")