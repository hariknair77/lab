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
# process_list = [[0, 2, 18], [1, 25, 4], [2, 30, 6], [3, 15, 1], [4, 16, 2]]
print('\nProcess list')
disp(process_list)
# sort with arival time
process_list.sort(key=lambda x: x[1])
print('\nFCFS')
disp(process_list)

wt = [0]
bt = [process[2] for process in process_list]
current_time = process_list[0][1]+process_list[0][2]

for next_process in process_list[1:]:
    # incrementing current
    if next_process[1] <= current_time:
        wt.append(current_time-next_process[1])
        current_time += next_process[2]
    else:
        wt.append(0)
        # current_time += (next_process[1]+next_process[2])
        current_time = (next_process[1]+next_process[2])

tt = list(map(add, wt, bt))

print(f'Average waiting time = {sum(wt)/n}')
print(f'Average Turn around time time = {sum(tt)/n}')
