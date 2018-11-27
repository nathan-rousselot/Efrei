from tkinter import *
from Board import play


root = Tk()


slow = Button(root, text='Slow Play', command=lambda : play('slow'))
slow.pack()

fast = Button(root, text='Fast Play', command=lambda : play('fast'))
fast.pack()


root.mainloop()