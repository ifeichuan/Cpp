from urllib.request import ProxyHandler,build_opener
from urllib.error import URLError

proxy_handler = ProxyHandler(
    {
        'http': 'http://127.0.0.1:8080',
        'https': 'https://127.0.0.1:8080'
    }
)

opener = build_opener(proxy_handler)
# 需要事先搭建http代理，并让其运行在8080端口上
# ProxyHandler,参数为字典，键名为协议类型（HTTP，HTTPS） 键值是代理链接 可以添加多个代理
try:
    response = opener.open('https://www.baidu.com')
    print(response.read().decode('utf-8'))
except URLError as e:
    print(e.reason)

