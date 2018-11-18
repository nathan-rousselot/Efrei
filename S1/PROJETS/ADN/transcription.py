def transcription():
    """Converts ADN into ARNm."""
    file = open("ADN_perfect.txt", 'r')
    ARNm = open("ARNm.txt", 'w')
    A = file.readlines()
    for i in range(len(A)):
        c = A[i][2]
        if c == 'T':
            ARNm.write("U\n")
        else:
            ARNm.write(A[i][2] + "\n")

transcription()