from random import randint

def create_ADN():
    """Creates an ADN with 5% errors."""
    file = open("ADN.txt", "w")
    for i in range(1000):
        c = randint(0, 3)
        if c == 0:
            file.write("A=T\n")
        elif c == 1:
            file.write("G=C\n")
        elif c == 2:
            file.write("C=G\n")
        elif c == 3:
            file.write("T=A\n")


create_ADN()