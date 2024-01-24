name = input("请输入你的名字:(输入exit结束)\n")
name +="\n"
with open("guest_book.txt","w") as file_object:
    
    while(name != 'exit\n'):
        file_object.write(name)
        name = input("请输入你的名字:(输入exit结束)\n")
        name += "\n"