def main():
    t = int(input())
    while t > 0:
        t -= 1
        n = int(input())
        a = list(map(int, input().split()))

        isOdd = [False] * n
        odd, even = [], []

        for i in range(n):
            if a[i] % 2 == 1:
                isOdd[i] = True
                odd.append(a[i])
            else:
                even.append(a[i])

        even.sort(reverse=True)
        odd.sort(reverse=True)

        for i in range(n):
            if isOdd[i]:
                a[i] = odd.pop()
            else:
                a[i] = even.pop()

        if a == sorted(a):
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()