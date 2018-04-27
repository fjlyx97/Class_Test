import os
import time
import random
import codecs

files = os.listdir()
nowtime = time.ctime()
day = int(nowtime[8:10])
hour = int(nowtime[11:13])
minute = 10
change = 0

#for file in files:
#    name = file
#    name = name[0] + name[2::]
#    os.rename(file,name)

for file in files:
    if (file == "test"):
        continue
    if (file == "test.py"):
        continue
    with open("%s" %(str(file)),'r',encoding='gbk') as f:
        contents = f.read()
    lines = contents.split("\n")
    i = 1
    change += 1
    
    with open("test/%s" %(str(file)) , 'w') as t:
        for line in lines:
            if i == 1:
                t.write("//@作者：周声宽\n")
                i += 1
                continue
            if i == 3:
                sec = random.randint(1,59)
                minute += random.randint(3,8)
                print(minute)
                if (minute >= 60):
                    minute -= 50
                    hour += 1
                    if (hour >= 24):
                        hour = 20
                writeTime = "//时间：2018年4月" + str(day) + "日" + str(hour) + ":" + str(minute) + ":" + str(sec)
                #time.sleep(1)
                t.write(writeTime)
                t.write("\n")
                i += 1
                continue
            i += 1
            t.write(line)
            t.write("\n")
    #cmd = "touch %s -d \"04/%s/2018\"" %(file , str(day))
    #os.system(cmd)
    #cmd = "touch %s -d \"%s:%s\"" %(str(file) , str(hour) , str(minute))
    #os.system(cmd)

    if (change % 11 == 0) :
        day += 1

