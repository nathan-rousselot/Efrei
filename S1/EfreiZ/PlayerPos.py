import random

class Players:

    def __init__(self, x, y, grid, alive):
        self.x = x
        self.y = y
        self.grid = grid
        self.alive = alive

    def move_player(self):
        c = random.randint(0, 3)
        if c == 0:
            return [1, 0]
        elif c == 1:
            return [0, 1]
        elif c == 2:
            return [-1, 0]
        elif c == 3:
            return [0, -1]


"""Uncomment the line you want. Fast == 1000 simulations of your code in a blink of an eye (just kidding, my gross code is slow).
Slow == basic display to sse what your algorithm is doing."""

def plays():
    return 'slow'
    #return 'fast'