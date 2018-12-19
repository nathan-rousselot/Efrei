def how_many_negatives():
    occ = 0
    print("Please enter 10 integers.")
    for i in range(0, 10):
        entry = int(input())
        if entry < 0:
            occ += 1
    print("There are", occ, "negative numbers.")


def multiple_average():
    s = int(input("Combien de séries voulez-vous évaluer ?"))
    A = [0] * s
    for i in range(0, s):
        moy = 0
        v = int(input("Combien de valeurs souhaitez-vous entrer ?"))
        for j in range(0, v):
            print("Valeur", j + 1, ':')
            n = int(input())
            moy += n
        A[i] = moy / v
    for i in range(0, s):
        print('S', i + 1, ':', A[i])


def __pascal_triangle(n, k):
    if k == n or k == 0:
        return 1
    return __pascal_triangle(n - 1, k - 1) + __pascal_triangle(n - 1, k)


def pascal_triangle(n):
    for row in range(n):
        for i in range(n - row, 0, -1):
            print(' ', end='')
        for k in range(row + 1):
            print(__pascal_triangle(row, k), end=' ')
        print()


def multiplication_table():
    A = [[0 for x in range(10)] for y in range(10)]
    print('   |  ', end='')
    for i in range(10):
        print(i + 1, end='   ')
    print()
    for i in range(44):
        print('-', end='')
    print()
    for i in range(10):
        print(i + 1, end='  |  ' * (i != 9))
        print('', end=' |  ' * (i == 9))
        for j in range(10):
            A[i][j] = (i + 1) * (j + 1)
            print(A[i][j], " " * (A[i][j] != 90), end=' ' * (A[i][j] % 10 == A[i][j]))
        print()
    return A


def magic_perfect_square(n):
    A = [[0 for x in range(n)] for y in range(n)]
    sum = 0
    isok = True
    for i in range(n):
        for j in range(n):
            A[i][j] = int(input("Entrez la case suivante:"))
    for i in range(n):
        sum += A[0][i]
    for i in range(n):
        sum1 = 0
        for j in range(1, n):
            sum1 += A[i][j]
        isok = (sum1 == sum)
        sum1 = 0
        for j in range(0, n):
            sum1 += A[j][i]
        isok = (sum1 == sum)
    if isok:
        print("Le carré est magique")
    else:
        print("Le carré n'est pas magique")
    isperfect = True
    for i in range(n):
        for j in range(n):
            if n * n + 1 <= A[i][j] or A[i][j] <= 0:
                isperfect = False
    if isperfect:
        print("Le carré est parfait")
    else:
        print("Le carré n'est pas parfait")


def secret_number_solver():
    print(
        "Pensez à un nombre entre 0 et 1000. Si j'ai juste, entrez '=' sinon '+' si je suis en dessous et '-' si je suis au dessus...")
    guess, intguess1, intguess2 = 0, 0, 1000
    answer = ' '
    i = 1
    while (answer != '=' and i <= 10):
        guess = (intguess1 + intguess2) // 2
        print(guess, '?')
        answer = input()
        if answer == '+':
            intguess1 = guess
        elif answer == '-':
            intguess2 = guess
        else:
            print("J'ai gagné! La réponse est:", guess)
        i += 1
    if answer != '=':
        print("Bravo, vous m'avez fait perdre.")

##################################BONUS############################################

def __conway(N):
    result = ""
    check = N[0]
    N = N[1:] + " "
    count = 1
    for i in N:
        if i != check:
            result += str(count) + check
            count = 1
            check = i
        else:
            count += 1
    return result


def conway(n):
    N = "1"
    for i in range(1, n):
        N = __conway(N)
    print(N)


#####################################Exercices sur les Tableaux############################


def GetAt(index, tab, size):
    if size != len(tab):
        print("wrong argument for size")
    else:
        if index >= size:
            print("GetAt: Index out of range")
        else:
            return tab[index]


def SetAt(index, elm, tab, size):
    if index >= size:
        print("SetAt: Index out of range")
    else:
        tab[index] = elm


def GetMax(tab, size):
    if size != len(tab):
        print("GetMax: Wrong size entered.")
    else:
        max = tab[0]
        for i in range(1, size):
            if tab[i] > max:
                max = tab[i]
        return max


def IsSorted(tab, size):
    if size != len(tab):
        print("IsSorted: Wrong size entered.")
    else:
        i = 0
        while i + 1 < size and tab[i] > tab[i + 1]:
            i += 1
        return i + 1 == size


def Sort(tab, size):
    if size != len(tab):
        print("Sort: Wrong size entered.")
    else:
        for i in range(len(tab) - 1, 0, -1):
            for j in range(i):
                if tab[j] < tab[j + 1]:
                    tab[j], tab[j + 1] = tab[j + 1], tab[j]
    return tab


def PrintArray(tab, size):
    if size  != len(tab):
        print("PrintArray: Wrong size entered.")
    else:
        for i in range(len(tab) - 1):
            if i == len(tab) - 1:
                print(A[i])
            else:
                print(A[i], end=' ')
