# Q:在发起Http请求时，会有一个请求头Request Headers 
#   那么如何设置这个请求头呢？
# A:使用Headers参数

import requests

headers = {
    'User-Agent':'Mozilla/5.0 (macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36(KHTML,Like Gecko) Chrome/52.0.2743.116 Safari/ 537.36',
    'name' :'Feichuan',
    'date' : '2001/2/3'
}
r = requests.get('https://ssr1.scrape.center/',headers=headers)
print(r.text)
print(r.headers)
