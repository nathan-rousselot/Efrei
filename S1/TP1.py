def HelloWorld():
    """Prints Hello World"""
    print("Hello World")


def affect():
    """Affects a value to myvar and prints it"""
    myvar = 5
    print(myvar)


def name(name):
    """Takes the name as parameter and prints it with a sentence"""
    print("Bonjour " + name + ", comment allez-vous ?")


def product(a, b):
    """Takes two integers in parameters and multiplies them"""
    if type(a) is not int or type(o) is not int:
        print("You haven't entered integers")
    print(a, "x", b, "=", a * b)


def power_of_two(n):
    """Takes an integer as parameter, and prints all the power of two to this integer"""
    for i in range(0, n + 1):
        """print(i, ":", pow(2, i)) will print with spaces around ":", so we use .format"""
        print("{}:{}".format(i, pow(2, i)))


def switch1(a, b):
    """Worst way of exchanging the value of two variables"""
    z = a
    a = b
    b = z
    return a, b


def switch2(a, b):
    """Ok way to exchange two values of variables"""
    a = a + b
    b = a - b
    a = a - b
    return a, b


def switch3(a, b):
    """Best way to exchange two values of variables"""
    a, b = b, a
    return a, b


def switch_5_numbers(a, b, c, d, e):
    """7 switches applied to a 5-uple"""
    for i in range(0, 7):
        a, b, c, d, e = e, a, b, c, d
    return (a, b, c, d, e)


def fibonacci():
    """Prints the 10th first numbers of fibonacci-s sequence"""
    a, b = 1, 1
    for i in range(0, 10):
        print(a)
        a, b = b, a + b

        
def __fibonacci_better(n, a, b):
    """Recursive function called by fibonacci_better"""
    if n <= 0:
        return 0
    else:
        print(a)
        print(b)
        return __fibonacci_better(n - 2, a + b, a + 2 * b)

    
def fibonacci_better(n):
    """Prints the nth first fibonacci-s sequence"""
    __fibonacci_better(n - 1, 1, 1)
