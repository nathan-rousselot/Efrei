from PlayerPos import *
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


def move(i, j):
    c = randint(0,4)
    if c == 3:
        if player.x - i >= player.y - j > 0:
            if grid[i + 1][j] == 3:
                player.alive = False
            grid[i][j], grid[i + 1][j] = 0, 7
        elif player.y - j >= player.x - i > 0:
            if grid[i][j + 1] == 3:
                player.alive = False
            grid[i][j], grid[i][j + 1] = 0, 7
        elif 0 > player.y - j >= player.x - i:
            if grid[i - 1][j] == 3:
                player.alive = False
            grid[i][j], grid[i - 1][j] = 0, 7
        elif 0 > player.x - i >= player.y - j:
            if grid[i][j - 1] == 3:
                player.alive = False
            grid[i][j], grid[i][j - 1] = 0, 7
    else:
        c = randint(0,4)
        if c == 0 and i <= 28:
            if grid[i + 1][j] == 3:
                player.alive = False
            grid[i][j], grid[i + 1][j] = 0, 7
        elif c == 1 and j <= 28:
            if grid[i][j + 1] == 3:
                player.alive = False
            grid[i][j], grid[i][j + 1] = 0, 7
        elif c == 2 and i >= 1:
            if grid[i - 1][j] == 3:
                player.alive = False
            grid[i][j], grid[i - 1][j] = 0, 7
        elif c == 3 and j >= 1:
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
    if (i > 28 and val[0] == 1) or (j > 28 and val[1] == 1) or (i == 0 and val[0] == -1) or (j == 0 and val[1] == -1):
        player.alive = False
    else:
        if grid[i + val[0]][j + val[1]] == 7:
            player.alive = False
        else:
            pastpos = [player.x, player.y]
            grid[i][j], grid[i + val[0]][j + val[1]] = 0, 3
            player.x += val[0]
            player.y += val[1]
            anticheat(pastpos[0], pastpos[1], player.x, player.y)


def fast_play():
    score, alive = 0, True
    for p in range(1000):
        while alive:
            spawn()
            for i in range(30):
                for j in range(30):
                    if grid[i][j] == 7:
                        move(i, j)
            gridEdit(player.x, player.y, player.move_player())
            copygrid()
            score += 1
            alive = player.alive
        refresh_game()
        alive = player.alive
    print("Your score is:", score)


def slow_play():
    score, alive = 0, True
    while alive:
        spawn()
        for i in range(30):
            for j in range(30):
                if grid[i][j] == 7:
                    move(i, j)
        gridEdit(player.x, player.y, player.move_player())
        copygrid()
        plt.style.use('dark_background')
        plt.figure(1)
        plt.title('EfreiZ Slow Simulation')
        plt.xlabel('By Nathan Rousselot')
        plt.imshow(grid, interpolation='nearest')
        plt.grid(False)
        plt.show(block=False)
        plt.pause(0.1)
        score += 1
        alive = player.alive
    print("Your score is:", score)


def play(play):
    if play == 'slow':
        slow_play()
    elif play == 'fast':
        fast_play()
    else:
        print("Stop being dumb plz.")
        return (None)


play(plays())
