import re
seq = "AATkdfhksjhgkdshgkAATTATATTsdfl"
for i in range(6,2,-1):
    strings = re.findall("[AT]{"+str(i)+"}",seq)
    print("strings of len :",i," :",strings)