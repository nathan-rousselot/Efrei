import random


def create_flawed_ADN():
    """Creates an ADN with 1/20 errors."""
    file = open("ADN.txt", 'w')
    for i in range(1000):
        a = random.randint(1,20)
        if a == 1:
            c = random.randint(0, 3)
            if c == 0:
                file.write("A")
            elif c == 1:
                file.write("T")
            elif c == 2:
                file.write("C")
            elif c == 3:
                file.write("G")
            file.write("=")
            c = random.randint(0, 3)
            if c == 0:
                file.write("A\n")
            elif c == 1:
                file.write("T\n")
            elif c == 2:
                file.write("C\n")
            elif c == 3:
                file.write("G\n")
        else:
            c = random.randint(0, 3)
            if c == 0:
                file.write("A=T\n")
            elif c == 1:
                file.write("G=C\n")
            elif c == 2:
                file.write("C=G\n")
            elif c == 3:
                file.write("T=A\n")
    file.close()


create_flawed_ADN()