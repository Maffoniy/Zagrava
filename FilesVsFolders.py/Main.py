import os
path = []
for c,folders,files in os.walk('C:\Windows'):
     path.append(c)
     for file in files:
          temp_path = os.path.join(c,file)
          path.append(temp_path)
for i in path:
     if  os.path.isfile(i):
          if '.xml' in i[-4:] or'.exe' in i[-4:] or'.dll' in i[-4:] or'.Manifest' in i[-4:] or'.log' in i[-4:] or'.bin'  in i[-4:] or'.txt' in i[-4:] or'.aux' in i[-4:] or '.txt' in i[-4:]:
               file=open(i,'r',errors='ignore')
               text=file.read()
               if text.find("Windows")>=0 or text.find("windows")>=0:
                    print(i)