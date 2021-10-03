import os
import sys
import subprocess
from tkinter import *

if os.geteuid() == 0:
    print("We're root!")
    root = Tk()

    root.title("Py Proxy Updater")

    def changebtn():

        file = open(r"/etc/apt/apt.conf", "w+")
        data = [f'Acquire::http::proxy "http://{addressvalue.get()}:{portvalue.get()}";\n',f'Acquire::https::proxy "https://{addressvalue.get()}:{portvalue.get()}";\n',f'Acquire::ftp::proxy "ftp://{addressvalue.get()}:{portvalue.get()}";\n',f'Acquire::socks::proxy "socks://{addressvalue.get()}:{portvalue.get()}";\n' ]  
        file.writelines(data)
        print(f'Address : {addressvalue.get()}')
        print(f'Port : {portvalue.get()}')
        root.destroy()

    def resetbtn():
        file = open(r"/etc/apt/apt.conf", "w+")
        data = ""  
        file.write(data)
        print("Proxy removed successfully")
        root.destroy()

    ## for screen size
    root.geometry("300x100")
    heading = Label(text="")
    user=Label(text="Enter Address :").grid(row=1,column=0)
    passwd=Label(text="Enter Port       :").grid(row=2)

    addressvalue = StringVar()
    portvalue = StringVar()

    addressentry = Entry(root, textvariable=addressvalue).grid(row=1,column=1)
    portentry = Entry(root, textvariable=portvalue).grid(row=2,column=1)

    Button(text="Reset",command=resetbtn).grid(row=3, column=0)
    Button(text="Change",command=changebtn).grid(row=3, column=1)

    root.mainloop()

else:
    print("Root access is required.")
    subprocess.call(['sudo', 'python3', *sys.argv])
    sys.exit()
