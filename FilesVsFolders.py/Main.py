import os
path = []
for c,folders,files in os.walk('C:\Windows'):
     path.append(c)
     for file in files:
          temp_path = os.path.join(c,file)
          path.append(temp_path)
for i in path:
     print(i)