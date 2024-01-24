import random

lives = 3
words = ['Python','yield','Code','Feichuan','Mingzhi','Creamy ice']

secret_word = random.choice(words)
clue = list('?'*len(secret_word))
guessed_word_correctly = False

def update_clue(guessed_letter,secret_word,clue):
    index = 0
    while index < len(secret_word):
        if guessed_letter == secret_word[index]:
            clue[index] = guessed_letter
        index = index +1




input('按任意键开始:')
# print(secret_word)
while (lives>0):
    print(clue)
    guess = input('请输入一个字母或整个单词:')

    if(guess == secret_word):
        guessed_word_correctly = True
        break
    if(guess in secret_word):
        update_clue(guess,secret_word,clue)
    else:
        print('你猜错了，再试一次吧！')
        print(f'您还有{lives-1}条命')
        lives = lives - 1

if guessed_word_correctly:
    print('You win')
else:
    print('You Choice')
