import requests
import  re
# 匹配所有h2标签中的内容
r = requests.get('https://ssr1.scrape.center/')
patten = re.compile('<h2.*>(.*?)</h2>',re.S)
titles = re.findall(patten,r.text)
print(titles)
