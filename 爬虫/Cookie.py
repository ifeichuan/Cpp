import http.cookiejar,urllib.request

cookie = http.cookiejar.CookieJar()
handler = urllib.request.HTTPCookieProcessor(cookie)
opener = urllib.request.build_opener(handler)
response = opener.open('https://www.baidu.com')
#创建一个cookie类，将其调入handler处理 写入opener 最后调用opener.open方法打开特定网页，使用cookie

for item in cookie:
    print(item.name + '=' + item.value)


