#!/usr/bin/python
from Tkinter import *

def exitProgram():
    root.destroy()


root = Tk()
root.attributes("-fullscreen", True)

frame = Frame(root)
frame.pack( side = LEFT)

selectedQueue = Frame(root)
selectedQueue.pack( side = RIGHT )

bottomframe = Frame(root)
bottomframe.pack( side = BOTTOM )


for x in range(0, 3):
    redbutton = Button(frame, text="Red", fg="red", width=50, height=5)
    redbutton.pack()




bluebutton = Button(selectedQueue, text="Send order!", fg="blue")
bluebutton.pack( side = BOTTOM )

blackbutton = Button(bottomframe, text="Exit", fg="black", command=exitProgram).pack()

root.mainloop()
