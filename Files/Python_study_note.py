filename = 'Python_study_note.txt'

with open(filename,encoding='utf-8') as file_object:
   lines = file_object.readlines()

for line in lines:
   print(f"{line.strip()} In Python you can!")