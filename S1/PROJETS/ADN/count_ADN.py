def count_ADN():
    """Counts the number of errors in one ADN file."""
    file = open("ADN_perfect.txt", 'r')
    A, count = file.readlines(), 0
    for i in range(len(A)):
        if A[i] != "A=T\n" and A[i] != "T=A\n" and A[i] != "G=C\n" and A[i] != "C=G\n":
            print(A[i], end='')
            count += 1
    print(count, end='')


count_ADN()