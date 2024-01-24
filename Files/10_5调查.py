with open("reason.txt","w",encoding="utf-8",) as file_object:
    reason = input("请输入你喜欢编程的原因:(输入None退出)")
    
    while(reason!="None"):
        file_object.write(reason+"\n")
        reason = input("请输入你喜欢编程的原因:(输入None退出)")
