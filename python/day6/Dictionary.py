import tkinter as ola
import csv

def passw():
    if (userbox.get() == "admin") and (passbox.get() == "1234"):
        label3.config(text="LoginSuccesfull")
        wind.destroy()
        dictn()
    else:
        label3.config(text="LoginFailed")

def dictn():
    wind2 = ola.Tk()
    wind2.geometry("800x400")
    wind2.title("Dictionary")
    ola.Label(wind2,text="Dictionary").pack()
    inp = ola.Entry(wind2)
    inp.pack()
    op = ola.Label(wind2)
    op.pack()
    ola.Button(wind2,text="CheckMeaning",command = lambda:check(inp.get(),op)).pack()
    ola.Button(wind2,text="StartWithCount",command = lambda:StrtWith(inp.get(),op)).pack()
    ola.Button(wind2,text="FirstWordOfLen",command = lambda:FirstWordOfLen(inp.get(),op)).pack()

def check(a,op):
    found = False
    with open("day6/word.csv") as f1:
        f1_read = csv.reader(f1)
        for row in f1_read:
            if a == row[0]:
                op.config(text =f"Meaning : {row[1]}")
                found = True
                break
    if found == False:
        op.config(text = "ErrorWordNotFound !")

def StrtWith(a,op):
    count = 0
    with open("day6/word.csv") as f1:
        f1_read = csv.reader(f1)
        for row in f1_read:
            if row[0].startswith(a):
                count += 1
    op.config(text = f"count :{count}")

def FirstWordOfLen(a,op):
    flag = 0
    try:
        n = int(a)
    except ValueError:
        op.config(text = "Enter a valid number")
        return
    with open("day6/word.csv") as f1:
        f1_read = csv.reader(f1)
        for row in f1_read:
            if len(row[0]) == n:
                op.config(text = f"1stWordOfLength :{row[0]}")
                flag = 1
                return
    if flag == 0:
        op.config(text = "NothingFound")

wind = ola.Tk()
wind.geometry("800x400")
wind.title("LoginPage")
ola.Label(wind, text="Enter UserName :").pack()
userbox = ola.Entry(wind)
userbox.pack()
ola.Label(wind, text="Enter Password :").pack()
passbox = ola.Entry(wind)
passbox.pack()
ola.Button(wind, text="Submit", command = passw).pack()
label3 = ola.Label(wind)
label3.pack()

wind.mainloop()