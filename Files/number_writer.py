import json

numbers = [2,3,5,7,11,13]

filename = "numbers.json"
with open(filename,"w") as f:
    json.dump(numbers,f)
    numbers.append(2)

with open(filename,'r') as f:
    numbers = json.load(f)
print(numbers)