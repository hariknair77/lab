from random import randint
from operator import add

# utility function


def disp(process):
    print('pno\tArival\tBurst')
    print('*'*25)
    for i in process:
        for j in i:
            print(j, end='\t')
        print('\n')


n = int(input('Enter number of process :'))
# creating process using randint
process_list = [[i, randint(1, 20), randint(1, 20)] for i in range(n)]
print('\nProcess list')
disp(process_list)
# sort with arival time
process_list.sort(key=lambda x: (x[1], x[2]))

sjf = []
wt = [0]
bt = [process[2] for process in process_list]
current_time = process_list[0][1]+process_list[0][2]
sjf.append(process_list.pop(0))  # first  arrived process

for _ in range(len(process_list)):
    temp = [p for p in process_list if p[1] <= current_time]
    if temp:
        next_process = min(temp, key=lambda x: x[2])
        process_list.remove(next_process)
    else:
        next_process = process_list.pop(0)

    # incrementing current
    if next_process[1] <= current_time:
        wt.append(current_time-next_process[1])
        current_time += next_process[2]
    else:
        wt.append(0)
        current_time = (next_process[1]+next_process[2])
        
    sjf.append(next_process)

print('SJF')
disp(sjf)
tt = list(map(add, wt, bt))
print(f'Average waiting time = {sum(wt)/n}')
print(f'Average Turn around time time = {sum(tt)/n}')
