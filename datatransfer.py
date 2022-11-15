log = 0
f = open("fall.txt", "r")
lines = f.readlines()
f.close()
if(len(lines) > 0):
    log = 1
f = open("fall.txt", "w")
f.write("")
f.close()