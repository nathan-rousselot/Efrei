def sudoku_getline(A, i):
    return A[i]


def sudoku_getcol(A, j):
    n = len(A)
    B = [0 for i in range(n)]
    for i in range(n):
        B[i] = A[i][j]
    return B

def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

def sudoku_getregion(A, i):
    n = len(A)
    j = isqrt(n)
    numl = i // j
    numc = i % j
    B = [[0 for s in range(j)] for p in range(j)]
    for k in range(j):
        for m in range(j):
            B[k][m] = A[k + (numl * j)][m + (numc * j)]
    return B


def sudoku_region_to_line(A):
    n = len(A)
    B = [0 for i in range(n*n)]
    for i in range(n):
        for j in range(n):
            B[i + j * n] = A[j][i]
    return B

def sudoku_isready(A):
    x = isqrt(len(A))
    if x*x == len(A):
        return True
    return  False


def __sudoku(A):
    if not sudoku_isready(A):
        print("Invalid Grid")
        return None
    else:
        n = len(A)
        x, seen = isqrt(n), [0 for i in range(n)]
        for i in range(n):
            line = sudoku_getline(A, i)
            for v in line:
                if v in seen:
                    return "Invalid"
                else:
                    seen[i] = v
            seen = [0 for i in range(n)]
        for i in range(n):
            line = sudoku_getcol(A, i)
            for v in line:
                if v in seen:
                    return "Invalid"
                else:
                    seen[i] = v
            seen = [0 for i in range(n)]
        for i in range(n):
            line = sudoku_region_to_line(sudoku_getregion(A, i))
            for v in line:
                if v in seen:
                    return "Invalid"
                else:
                    seen[i] = v
            seen = [0 for i in range(n)]
        return "Valid"