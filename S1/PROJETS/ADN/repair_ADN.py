def repair_ADN():
    """Creates an ADN_perfect file without the errors inside ADN file."""
    file = open("ADN.txt", 'r')
    file_perfect = open("ADN_Perfect.txt", 'w')
    A = file.readlines()
    for i in range(len(A)):
        if A[i] == "A=T\n" or A[i] == "T=A\n" or A[i] == "G=C\n" or A[i] == "C=G\n":
            file_perfect.write(A[i])
    file.close()
    file_perfect.close()


repair_ADN()