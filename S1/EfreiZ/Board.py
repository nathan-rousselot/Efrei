from PlayerPos import *
from tkinter import *
from time import sleep
from math import sqrt
from pylab import *


grid = [[0 for i in range(30)] for j in range(30)]
player = Players(14, 15, grid, True)
grid[player.x][player.y] = 3
score = 0
pastpos = [player.x, player.y]

def refresh_game():
    for i in range(30):
        for j in range(30):
            grid[i][j] = 0
    player.x = 14
    player.y = 15
    copygrid()
    player.alive = True
    grid[player.x][player.y] = 3


def copygrid():
    A = [[0 for i in range(30)] for j in range(30)]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            A[i][j] = grid[i][j]
    player.grid = A


copygrid()


def newboard(grid):
    for i in range(30):
        for j in range(30):
            if grid[i][j] == 0:
                print("|   ", sep='', end='')
            else:
                print("| ", "Z" * (grid[i][j] == 7), "P" * (grid[i][j] == 3), " ", sep='', end='')
        print()
        for j in range(30):
            print('---', end=' ', sep='')
        print()


def spawn():
    c = randint(0, 3)
    if c == 1:
        grid[0][0] = 7
    c = randint(0, 3)
    if c == 1:
        grid[0][29] = 7
    c = randint(0, 3)
    if c == 1:
        grid[29][29] = 7
    c = randint(0, 3)
    if c == 1:
        grid[29][0] = 7


def is_close(i, j):
    while grid[i][j] != '3':
        i += 1



def move(i, j):
    if player.x - i > player.y - j > 0:
        if grid[i + 1][j] == 3:
            player.alive = False
        grid[i][j], grid[i + 1][j] = 0, 7
    elif player.y - j > player.x - i > 0:
        if grid[i][j + 1] == 3:
            player.alive = False
        grid[i][j], grid[i][j + 1] = 0, 7
    elif 0 > player.y - j > player.x - i:
        if grid[i - 1][j] == 3:
            player.alive = False
        grid[i][j], grid[i - 1][j] = 0, 7
    elif 0 > player.x - i > player.y - j:
        if grid[i][j - 1] == 3:
            player.alive = False
        grid[i][j], grid[i][j - 1] = 0, 7


def anticheat(pastx, pasty, currx, curry):
    if sqrt((currx-pastx) ** 2 + (curry-pasty) ** 2) != 1:
        sys.exit("VAC Banned")
    count = 0
    for i in range(30):
        for j in range(30):
            if grid[i][j] == 3:
                count += 1
    if count > 1:
        sys.exit("VAC Banned")


def gridEdit(i, j, val):
    if 0 > i + val[0] > 29 or 0 > j + val[1] > 29 or grid[i + val[0]][j + val[1]] != 0 or sqrt(val[0]**2 + val[1]**2) != 1 :
        if grid[i + val[0]][j + val[1]] == 7:
            sys.exit()
        for i in range(30):
            grid[0][i] = 7
        root = Tk()
        root.title("EfreiZ")
        label = Label(root, text="You shall not pass!!!!!")
        label.pack()
        root.mainloop()
        return False
    else:
        pastpos = [player.x, player.y]
        grid[i][j], grid[i + val[0]][j + val[1]] = 0, 3
        player.x += val[0]
        player.y += val[1]
        anticheat(pastpos[0], pastpos[1], player.x, player.y)
        return True


def fastGridEdit(i, j, val):
    if 29 > i + val[0] > 0 or 29 > j + val[1] > 0:
        if grid[i + val[0]][j + val[1]] != 0 or sqrt(val[0]**2 + val[1]**2) != 1 :
            if grid[i + val[0]][j + val[1]] == 7:
                player.alive = False
            return False
    else:
        grid[i][j], grid[i + val[0]][j + val[1]] = 0, 3
        player.x += val[0]
        player.y += val[1]
        return True


def fast_play(score):
    for i in range(1000):
        while player.alive:
            spawn()
            for i in range(30):
                for j in range(30):
                    if grid[i][j] == 7:
                        move(i, j)
            fastGridEdit(player.x, player.y, player.move_player())
            score += 1
            copygrid()
        refresh_game()
    print("Your score is:", score)


def slow_play():
    while player.alive:
        spawn()
        for i in range(30):
            for j in range(30):
                if grid[i][j] == 7:
                    move(i, j)
        gridEdit(player.x, player.y, player.move_player())
        copygrid()
        plt.style.use(['dark_background'])
        plt.figure(1)
        plt.imshow(grid, interpolation='nearest')
        plt.grid(True)
        plt.show(block=False)
        plt.pause(0.1)


def play(play):
    if play == 'slow':
        slow_play()
    elif play == 'fast':
        fast_play(0)
    else:
        print("Stop being dumb plz.")
        return (None)


play(plays())