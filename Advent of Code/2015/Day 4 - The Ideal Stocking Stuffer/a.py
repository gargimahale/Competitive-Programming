import hashlib
import itertools

data = "iwrupvqb"
for i in itertools.count():
    hex = hashlib.md5((data + str(i)).encode()).hexdigest()
    if hex.startswith('000000'): # '00000'
        print(i)
        break