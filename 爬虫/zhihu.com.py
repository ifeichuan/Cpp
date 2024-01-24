import urllib.request
import urllib.error
import socket

reponse = urllib.request.urlopen('https://www.zhihu.com/column/c_1449641468377485312')

print(reponse.read())
