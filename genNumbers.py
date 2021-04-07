import random

file_100 = open('files/100numbers.txt', 'w')
file_1000 = open('files/1000numbers.txt', 'w')
file_10000 = open('files/10000numbers.txt', 'w')
file_100000 = open('files/100000numbers.txt', 'w')
file_1000000 = open('files/1000000numbers.txt', 'w')

files = [file_100, file_1000, file_10000, file_100000, file_1000000]

for i in range(100):
    line = str(random.randint(1, 100)) + '\n'
    file_100.write(line)

for i in range(1000):
    line = str(random.randint(1, 100)) + '\n'
    file_1000.write(line)

for i in range(10000):
    line = str(random.randint(1, 100)) + '\n'
    file_10000.write(line)
    
for i in range(100000):
    line = str(random.randint(1, 100)) + '\n'
    file_100000.write(line)

for i in range(1000000):
    line = str(random.randint(1, 100)) + '\n'
    file_1000000.write(line)

for file in files:
    file.close()
