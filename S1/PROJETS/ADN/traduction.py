from traduction_D import proteins, arrayToString


def traduction():
    """Converts the ARNm into Proteines."""
    file = open("ARNm.txt", 'r')
    file1 = open("proteines.txt", 'w')
    A = file.readlines()
    word = ['0', '0', '0']
    start = False
    for i in range(len(A)):
        if i % 3 == 0 and word != ['0', '0', '0']:
            prot = proteins[arrayToString(word)]
            if start and prot != "Stop":
                file1.write(prot + "\n")
            elif prot == "Met":
                start = True
                file1.write(prot + "\n")
            elif prot == "Stop" and start:
                file1.write(prot + "\n\n")
                start = False
        word[i % 3] = A[i][0]


traduction()
