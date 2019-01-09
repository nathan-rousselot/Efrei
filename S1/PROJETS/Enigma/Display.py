import tkinter
import webbrowser
import Enigma


#init of the display
root = tkinter.Tk()
root.geometry("1000x1000")
root.title("Enigma")
head = tkinter.Label(root, text="Enigma Toolkit", anchor='w', font=("Helvetica", 13))

#All the boring text
welcome_message = "Hello and welcome to Enigma Toolkit. This small software will allow you to simulate the simplified functioning of an Enigma machine, used by the Germans during the Second World War. Several options are offered to you, I let you Explore them and have fun with these little cryptography tools!"
github = "Enigma Tool is still being developped, as other Efrei related-projects such as EfreiZ, or personal projects. Follow all these here :  "


#functions
def shuffle():
    entry_rotor1.delete(0, tkinter.END)
    entry_rotor2.delete(0, tkinter.END)
    entry_rotor1.insert(0, Enigma.shuffle())
    entry_rotor2.insert(0, Enigma.shuffle())


def entry_to_tab(entry):
    tab = [0 for i in range(26)]
    i = 0
    for j in entry:
        if j != " ":
            tab[i] = j
            i += 1
    return tab


def decode():
    code, rotor1, rotor2 = coded_message.get("1.0", tkinter.END), entry_to_tab(entry_rotor1.get()), entry_to_tab(entry_rotor2.get())
    print(code, "\n", rotor1, "\n", rotor2)
    decoded_message.delete("1.0", tkinter.END)
    decoded_message.insert("1.0", Enigma.decode(rotor1, rotor2, code))


def go_to_git():
    webbrowser.open("https://github.com/RousselotN")


#widgets
welcome = tkinter.Frame(root, width=300, height=200, borderwidth=1)
welcome_text = tkinter.Label(welcome, text=welcome_message, wraplength=1000, anchor='w', justify='center', font=("Helvetica", 11))
github_text = tkinter.Label(root, text=github, wraplength=1000, anchor='w', justify="center", font=("Helvetica", 11))
github_button = tkinter.Button(root, text="My GitHub", command=go_to_git)
coded = tkinter.LabelFrame(root, width=500, height=200, borderwidth=1, text="Texte Codé")
coded_message = tkinter.Text(coded, height=8, width=80)
decoded = tkinter.LabelFrame(root, width=500, height=200, borderwidth=1, text="Texte Décodé")
decoded_message = tkinter.Text(decoded, height=8, width=80) 
rotor = tkinter.LabelFrame(root, width=500, height=200, borderwidth=1, text="Rotors")
abc = tkinter.Label(rotor, text="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z")
entry_rotor1 = tkinter.Entry(rotor, width=41)
entry_rotor1.insert(0, "Rotor1")
entry_rotor2 = tkinter.Entry(rotor, width=41)
entry_rotor2.insert(0, "Rotor2")
shuffle = tkinter.Button(rotor, text="Create random rotors", command=shuffle)
decode_b = tkinter.Button(coded, text="Simple decode", command=decode)



#Display construction
head.pack(side="top")
welcome.pack(side="top")
welcome_text.pack(fill="both")
coded.pack(padx=50, pady=5, fill="both")
coded_message.pack(fill="both", padx=10, pady=5)
decode_b.pack()
rotor.pack(padx=50, pady=5, fill="both")
abc.pack()
entry_rotor1.pack()
entry_rotor2.pack()
shuffle.pack()
decoded.pack(padx=50, pady=5, fill="both")
decoded_message.pack(fill="both", padx=10, pady=5)
github_text.pack()
github_button.pack()
root.mainloop()
