#!/usr/bin/python
from Tkinter import *
import random
import ros
import rospy
import threading
from time import sleep
from jobqueue.srv import addJobToQueue
from jobqueue.srv import getAllJobs


def exitProgram():
    root.destroy()

def senditems(listbox, pinda):
    list = listbox.get(0,END)
    list2 = []
    for element in list:
        i = 0
        for ingredient in pinda:
            i += 1
            if element == ingredient:
                list2.append(i)
    if len(list2) > 0:
        global currentbox
        currentbox.insert(END, list2)
        rospy.wait_for_service('addJobToQueue')
        try:
            addJobToQ = rospy.ServiceProxy('addJobToQueue', addJobToQueue)
            resp1 = addJobToQ(list2)
        except rospy.ServiceException, e:
            print "Service call failed: %s"%e

    listbox.delete(0,END)

def nexttask():
    global currentbox
    rospy.wait_for_service('getAllJobs')
    try:
        getAll = rospy.ServiceProxy('getAllJobs', getAllJobs)
        resp1 = getAll()
        currentbox.delete(0, END)
        for item in resp1.items:
            currentbox.insert(END, item)
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

    root.after(1000, nexttask)

def createbutton(pinda):
    button = Button(pindabuttons, text=pinda, command=lambda newbox = newbox: newbox.insert(END, pinda))
    button.pack(side=TOP, fill=X, expand=1)
    button['font'] = buttonfont
    button['background'] = nutbuttoncolor

taskarray = []

listboxcolor = 'LightBlue'
nutbuttoncolor = '#f5f5dc' #Beige

buttonfont = ("Helvetica Neue", 30, "bold")
listfont = ("Helvetica Neue", 24)
quefont = ("Helvetica Neue", 15)
closefont = ("Helvetica Neue", 10, "bold")
pinda = ["Dop pinda's", "Gepelde dop pinda's", "Gepelde vlies pinda's"]

root = Tk()
rospy.init_node('gui')
root.config(height=1080, width=1940)
root.attributes("-fullscreen", False)

topframeleft = Frame(root, width = 540)

topframeleft.pack(side = LEFT, fill=BOTH, expand=1)
topframeleft.config(bd=10)

topframemid = Frame(root, width = 800)
topframemid.pack(side = LEFT, fill=BOTH, expand=1)

topframeright = Frame(root, width = 800)
topframeright.pack(side = LEFT, fill=BOTH, expand=1)

close = Button(topframeleft, text="close", command=exitProgram)
close.pack()
close['font'] = closefont

buttonframe2 = Frame(topframemid)
buttonframe2.pack(side=TOP)

buttonframe3 = Frame(topframeright)
buttonframe3.pack(side=TOP)

newbox = Listbox(topframemid, height = 500)
newbox.pack(side=TOP, fill=BOTH)
newbox['font'] = listfont
newbox['background']= "White"

currentbox = Listbox(topframeright, height = 500)
currentbox.pack(side=TOP, fill=BOTH)
currentbox['font'] = quefont
currentbox['background']= "White"

send = Button(buttonframe2, text="send", command=lambda: senditems(newbox, pinda))
send.pack(side=LEFT)
send['font'] = buttonfont
send['background'] = 'LightGreen'

cancel = Button(buttonframe2, text="cancel", command=lambda newbox = newbox: newbox.delete(0,END))
cancel.pack(side=RIGHT)
cancel['font'] = buttonfont
cancel['background'] = '#f66060' #red

# ntask = Button(buttonframe3, text="Next Task", command=randomtaskarray)

# ntask.pack(side=LEFT)

# ntask['font'] = buttonfont

# ntask['background'] = 'LightBlue'



# delete = Button(buttonframe3, text="Delete", command=lambda currentbox=currentbox: currentbox.delete(ANCHOR))

# delete.pack(side=RIGHT)

# delete['font'] = buttonfont

pindabuttons = Frame(topframeleft)

pindabuttons.pack(side=TOP)

for element in pinda:
    button = createbutton(element)

root.after(1000, nexttask)
root.mainloop()
