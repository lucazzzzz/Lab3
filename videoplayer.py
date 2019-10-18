
import tkinter as tk
import myModule

from tkinter import filedialog



class Application():
    def __init__(self):
        self.root = tk.Tk()
        self.search = tk.Button(self.root, text="Search File", fg="black", command=lambda: self.file())
        self.search.pack()
        self.play = tk.Button(self.root, text="Play/Pause", fg="black", command=lambda : myModule.manager("1"))
        self.play.pack()
        self.avance = tk.Button(self.root, text="Avance Rapide", fg="black", command=lambda: myModule.manager("2"))
        self.avance.pack()
        self.reset = tk.Button(self.root, text="Reset", fg="black", command=lambda: myModule.manager("3"))
        self.reset.pack()
        self.quit = tk.Button(self.root, text="Quitter", fg="black", command=lambda: quit())
        self.quit.pack()


        self.root.mainloop()

    def quit(self):
        myModule.manager("4")
        self.root.quit()

    def file(self):
        self.root.filename = filedialog.askopenfilename(initialdir="/", title="Select file",
                                                        filetypes=(("All Files", "*.*"),("Avi Files", "*.avi")))
        myModule.manager(self.root.filename)



app = Application()
