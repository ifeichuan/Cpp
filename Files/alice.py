filename = 'alice.txt'

try:
    with open(filename,,encoding='utf-8') as f:
        contents = f.read()
except FileNotFoundError:
    print("File Not Found！")
