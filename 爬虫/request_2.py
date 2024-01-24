import requests

data = {
	'age':'25',
	'name' :'germey'

}
r = requests.get('https://www.httpbin.org/get',params=data)
print(r.text)
