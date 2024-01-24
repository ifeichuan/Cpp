# 保存和读取用户生成的数据
import json


def get_stored_username():
    """获取名字"""
    filename = "username.json"
    try:
        with open(filename,"r") as f:
            username = json.load(f)
    except FileNotFoundError:
        return None
    else:
        return username

def get_new_name():
    """获取新名字"""
    filename = "username.json"
    username = input("What is your name")
    with open(filename,"w") as f:
        json.dump(username,f)
    return username


def greet_user():
    """
    问候用户，并指出其名字
    """
    username = get_stored_username()
    if username:
        check = input("用户名是否正确？(Y/N)")
        if check == "Y":
            pass
        else:
            username = get_new_name()
        print(f"Welcome back,{username}")

    else:
        username = get_new_name()
        print(f"We'll remember you when you come backm,{username}")



greet_user()
