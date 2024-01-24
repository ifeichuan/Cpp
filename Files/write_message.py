filename = 'programming.txt'
# w写入 r 读取 r+ 读写 a 附加模式
# w方法将自动清空已存在的方法，所以更简易r+方法
with open(filename,'w') as flie_object:
    flie_object.write('I love Programming.\n')
    flie_object.write('Xcnsin')