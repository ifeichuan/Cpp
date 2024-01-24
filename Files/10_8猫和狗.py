cats = "cats.txt"
dogs= "dogs.txt"


with open(dogs,"a",encoding="gbk") as f:
    while True:
        print("Enter ’q‘ to quit")
        text = input("Please Enter dog's name:")
        if(text == 'q'):
            break
        f.write(text+"\n")
try:
    with open(dogs) as f:
        lines = f.readlines()
        for line in lines:
            print(line)
except FileNotFoundError:
    pass








