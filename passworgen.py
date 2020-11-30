from tkinter import *
import string
import struct
import time
import pyperclip
root = Tk()
root.configure(bg="grey")
root.title("Password Generator")
root.geometry("800x400")
root.configure(bg="black")
def copy_():
    global s
    pyperclip.copy(s)
def Onclick():
    a = list(string.ascii_lowercase)
    b = list(string.ascii_uppercase)
    c = list(string.digits)
    d = list(string.punctuation)
    l1 = []
    l1.extend(a)
    l1.extend(b)
    l1.extend(c)
    l1.extend(d)
    global s 
    g = random(0 , 25)
    s = a[g]
    y = random(12 , 29)
    for x in range(y):
        v = random(0 , 90)
        s1 = l1[v]
        s = s + s1
    l = random(0 , 8)
    s = s + c[l]
    h = random(0 , 25)
    s = s + b[h]
    e1 = Label(root, width=40, text = s, font=19, bg="black", fg="white").grid(row=9, column=5)
def random(i , j):
    def lastbit(f):
        return struct.pack('!f', f)[-1] & 1
    def getrandbits(k):
        result=0
        for _ in range(k):
            time.sleep(0)
            result <<= 1
            result |= lastbit(time.perf_counter())
        return result
    def randint(a, b):
        return a + randbelow(b - a + 1)
    def randbelow(n):
        if n <=0:
            raise ValueError
        k = n.bit_length()
        r = getrandbits(k)
        while r>=n:
           r=getrandbits(k)
        return r
    return randint(i , j)
    
Button(root, text="GENERATE PASSWORD", command=Onclick, border=5).grid(row=2 ,column=5)
Label(root, text="YOUR GENERATED PASSWORD WILL BE BETWEEN 12-32 CHARACTERS LONG", fg="white", bg="black", padx=30, pady=20).grid(row=5, column=5 )
Label(root, text="Your Password is: ", font="bold", bg="black", fg="white").grid(row=9 ,column=0 )
Button(root, text="COPY PASSWORD", command=copy_, border=5).grid(row=20, column=5, pady=10)
root.mainloop()
