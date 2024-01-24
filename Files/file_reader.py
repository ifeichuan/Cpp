with open('pi_digits.txt') as file_object:
    contents = file_object.read()
contents.removeprefix('\n')
print(contents.rstrip())