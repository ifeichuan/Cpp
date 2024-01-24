import json

filename = "Likenumber.json"

def get_number():
    try:
        with open(filename) as f:
            likenumber = json.load(f)
    except FileNotFoundError:
        return None
    else:
        return likenumber


def get_new_likenumber():
    new_number = input("Enter you like's number")
    with open(filename,'w') as f:
        json.dump(new_number,f)
    return new_number

def greet_use():
    """
        问候用户
    """
    number = get_number()
    if(number):
        print(f" I know your favorite number! It's {number}")
    else:
        number = get_new_likenumber()
        print(f"We'll remember this {number} when you come back ")

greet_use()
        