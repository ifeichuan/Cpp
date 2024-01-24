import requests

r = requests.get('https://www.baidu.com')
print(r.cookies)
for key,vaule in r.cookies.items():
    print(key + '=' + vaule)

