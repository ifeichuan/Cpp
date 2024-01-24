import socket
import urllib.request , urllib.error

try:
    response = urllib.request.urlopen('https://www.baidu.com',timeout=0.01)
except urllib.error.URLError as e:
    if isinstance(e.reason,socket.timeout):
        print('timeout')

        