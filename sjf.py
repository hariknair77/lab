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
process_list.sort(key=lambda x: (x[1], x[2]))


# i = 0
# tot_wt = 0
# tot_turn_around_time = process_list[0][2]  # first prorcess burst time
# wt.append([0, process_list[0][1], process_list[0][2]])  # first prorcess


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
        # current_time += (next_process[1]+next_process[2])
        current_time = (next_process[1]+next_process[2])
        
    sjf.append(next_process)

    # waiting_time = sum(wt[i])-next_process[1]
    # if waiting_time < 0:
    #     waiting_time = 0
    # wt.append([waiting_time, next_process[1], next_process[2]])
    # tot_wt += waiting_time
    # tot_turn_around_time += (waiting_time+next_process[2])
    # i += 1


print('SJF')
disp(sjf)

tt = list(map(add, wt, bt))

print(f'Average waiting time = {sum(wt)/n}')
print(f'Average Turn around time time = {sum(tt)/n}')
