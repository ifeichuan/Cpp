from urllib import request,error

try:
    response = request.urlopen('https://cuiqingcai.com/404')
except error.HTTPError as e:
    print(e.reason,e.code,e.headers,sep='\n')
except error.URLError as e:
    print(e.reason)
    #如果不是HTTP原因，则检查url原因 如果都不是，则用else来处理正常的逻辑
else:
    print('Request Successfully//sb沸喘喘')

