import requests

data = {
    'name':'germy',
    'age':'25'
}
headers = {
    'User-Agent' : 'Chrome',
    'Host' :'114.114.114.114'
}
r = requests.post('https://www.httpbin.org/post',data=data,headers=headers)
print(r.text)

