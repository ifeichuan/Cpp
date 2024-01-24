import requests 
proxies = {
    'http' : 'http://127.0.0.1:8080',
    'https' :'http://127.0.0.1:443'
}
requests.get('https://www.httpbin.org/get',proxies=proxies)
