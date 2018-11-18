def est_pair(a):
    if a % 2 == 0:
        print(a, "est pair")
    else:
        print(a, "est impair")


def compare(a, b):
    if a > b:
        print(a, ">", b)
    elif a < b:
        print(b, ">", a)
    else:
        print(a, "=", b)


def intervalle(a, b, n):
    if a > b:
        a, b = b, a
    if n >= a and n <= b:
        print(n, "est dans l'intervalle [", a, ";", b, "]")
    else:
        print(n, "n'est pas dans l'intervalle [", a, ";", b, "]")


def identity(name, age, genre):
    if genre == 'H':
        print("Bonjour", name, ", tu as", age, "ans et tu es un garçon")
    elif genre == 'F':
        print("Bonjour", name, ", tu as", age, "ans et tu es une fille")
    else:
        print("Identity: Error, wrong variable for Genre")


def tests(x, y, z):
    if x == y and y == z:
        print("True")
    else:
        print("False")
    if x == y or x == z or y == z:
        print("True")
    else:
        print("False")
    if (x == y and y != z) or (x == z and z != y) or (y == z and z != x):
        print("True")
    else:
        print("False")


def calculator(a, b, op):
    if op == '+':
        print(a, "+", b, "=", a + b)
    elif op == '-':
        print(a, "-", b, "=", a - b)
    elif op == '*':
        print(a, "x", b, "=", a * b)
    elif op == '/':
        if b == 0:
            print("Error, can't divide by 0")
        else:
            print(a, "/", b, "=", a // b)
    else:
        print("Error, wrong operator")


def GameOfLife(nw, nn, ne, ww, c, sw, ss, se):
    if c == 1:
        c = (nw + nn + ne + sw + ww + se + ss >= 2)
    else:
        c = (nw + nn + ne + sw + ww + se + ss >= 3)
    if c == 1:
        print("True")
    else:
        print("False")


def quadratic_eq(a, b, c):
    delta = pow(b, 2) - 4*a*c
    if delta > 0:
        x1 = (-b - pow(delta, 1 / 2)) / 2 * a
        x2 = (-b + pow(delta, 1 / 2)) / 2 * a
        print("x1 =", x1)
        print("x2 =", x2)
    elif delta == 0:
        x = -b / (2 * a)
        print("x =", x)
    else:
        delta = - delta
        print("x1 =", -b / (2 * a), "+ i", pow(delta, 1 / 2) / (2 * a))
        print("x2 =", -b / (2 * a), "- i", pow(delta, 1 / 2) / (2 * a))

