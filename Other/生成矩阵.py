import numpy as np  
  
# 生成50个样本，每个样本有3个特征：身高、体重和性别  
samples = np.random.randint(50, 70, 50)  # 身高范围在150-180之间  
weights = np.random.randint(100, 200, 50)    # 体重范围在40-80之间  
genders = np.random.choice(['1', '0'], size=50)  # 男性和女性的比例为1:1  
  
# 将三个特征合并成一个矩阵  
matrix = np.column_stack((samples, weights, genders))  
matrix = str(matrix)
filename = "data.txt"
with open(filename,mode="w+",encoding='utf-8') as f:
    f.write(str(matrix))