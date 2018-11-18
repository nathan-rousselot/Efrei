def base_menu():
    ok = True
    while ok:
        print("a) Execute HelloWorld \nb) Execute HowAreYour \nc) Quit")
        choice = input()
        if choice == 'a':
            print("Hello World !")
        elif choice == 'b':
            print("How are you ?")
        elif choice == 'c':
            ok = False
        else:
            print("base_menu: Error, you entered an option that doesn't exist")


def secretnb():
    secretnumber = 182
    i = 10
    while i > 0:
        guess = input()
        if guess > secretnumber:
            print("Le nombre secret est plus petit !")
        elif guess < secretnumber:
            print("Le nombre secret est plus grand !")
        else:
            print("Gagné !")
            i = 101
        i -= 1
    if i == 0:
        print("Perdu !")


def PGCD(a, b):
    if a < b:
        a, b = b, a
    r = a % b
    while r != 0:
        a, b = b, r
        r = a % b
    print("Le PGCD est", b)


def PPCM(a, b):
    c, d = a, b
    while a != b:
        if a > b:
            b += d
        elif a < b:
            a += c
    print("Le PPCM est", a)


def sum(n, m):
    sum = 0
    while n > 0:
        sum += pow(n,m)
        n -= 1
    print(sum)


def prime(n):
    A = [True]*n
    i = 2
    p = 0
    while i < pow(n, 1/2):
        if A[i]:
            while pow(i, 2) + p * i < n:
                A[pow(i, 2) + p * i] = False
                p += 1
        i += 1
        p = 0
    for j in range(2, n):
        if A[j]:
            print(j)


def perfect(n):
    for i in range(1, n):
        sum = 0
        for j in range(1, (i // 2) + 1):
            if i % j == 0:
                sum += j
        if i == sum:
            print(i, "est un nombre parfait \n")


def triangle(h):
    for i in range(0, h):
        print('*' * i)
    for i in range(0, h):
        print('*' * (h - i))


def several_triangles(h, n):
    for i in range(0, n + 1):
        for j in range(0, h + 1):
            print('*' * j)


