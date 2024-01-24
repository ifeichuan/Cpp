def add(first_name:int,second_number:int) -> int:
    return first_name + second_number


while True:
    try:
        a = int(input("Please Enter first number: "))
        b = int(input("Please Enter second number: "))
    except ValueError:
        print("Don't Enter alphabet")
        print("Enter again")
    else:
        print(f"{add(a,b)}")

        









