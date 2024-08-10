def next_build(pattern:str):
    # next数组中每个数字代表的是当前字符不匹配时，模式串应该跳转到的下标
    next = [0]* pattern.__len__()
    next[0] = 0
    i = 1
    # 当前相同前后缀长度
    len = 0
    while i<len(pattern):
        if pattern[i]==pattern[len]:
            next[i] = len+1
            i+=1
            len+=1
        else:
            if len==0:
                next[i] = 0
                i+=1
            else:
                len = next[len-1]
    return next

def kmp_search(string,pattern):
    next = next_build(pattern)
    i = 0
    # j 为 当前匹配到的模式串的字符位置
    j = 0
    while i<len(string):
        if string[i]==pattern[j]:
            # 若string[i]==pattern[j]
            i+=1
            j+=1
        else:
            if j==0:
                i+=1
            else:
                # 若j!=0,则令j = next[j-1],即跳到模式串中next[j-1]位置
                j = next[j-1]
        if j==len(pattern):
            return i-j
    return -1



string = "ABABABCAA"
pattern = "ABABC"
pos = kmp_search(string,pattern)
print(f"{pattern} is in {string} at position {pos}")
