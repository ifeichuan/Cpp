import requests

r = requests.get('https://scrape.center/favicon.ico')

with open('favicon.ico','wb') as f:
    f.write(r.content)
    # 这里运用了open方法 第一个参数是文件名称，第二个代表以二进制写的形式打开文件
    #可以向文件里写入二进制数据

