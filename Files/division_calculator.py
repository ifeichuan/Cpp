print("Give me two numbers, and I'll divide them.")
print("Enter 'q' to quit")

while True:
    first_number = input("\nFirst number: ")
    if first_number == 'q':
        break
    second_number = input("Second number: ")
    if second_number == 'q':
        break
    try:
        answer = int(first_number)/int(second_number)
        print(answer)

    except ZeroDivisionError:
        print("Don't enter 0 for the second number")
        print("Please enter again")
    """
    try-except-else 代码块的工作原理大致如下。Python尝试执行try 代码块中的
代码，只有可能引发异常的代码才需要放在try 语句中。有时候，有一些仅在try
代码块成功执行时才需要运行的代码，这些代码应放在else 代码块中。except
代码块告诉Python，如果尝试运行try 代码块中的代码时引发了指定的异常该怎么
办。
    """