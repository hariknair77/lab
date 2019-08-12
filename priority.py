from random import randint
from operator import add

def disp(process):
    print('pno\tArival\tBurst\tPriority')
    print('*'*30)
    for i in process:
        for j in i:
            print(j, end='\t')
        print('\n')


# list with priority
n = int(input('Enter number of process :'))
process_list = [[i, randint(1, 20), randint(1, 20), randint(1, 10)] for i in range(n)]
# printing process list
print('process_list')
disp(process_list)

# sorting process list with arival time and priority
process_list.sort(key=lambda x: (x[1], x[3]))

priority = []
wt = [0]
bt = [process[2] for process in process_list] #burst time
current_time = process_list[0][1]+process_list[0][2]
priority.append(process_list.pop(0)) # select first arrived and high priority process

for _ in range(len(process_list)):
    temp = [p for p in process_list if p[1] <= current_time]
    if temp: 
        next_process = min(temp, key=lambda x: x[3])
        process_list.remove(next_process)
    # temp empty    
    else:
        next_process = process_list.pop(0)

    # incrementing current time adding burst time and arival time
    if next_process[1] <= current_time:
        wt.append(current_time-next_process[1]) #waiting time
        current_time += next_process[2]
    else:
        current_time = (next_process[1]+next_process[2])
    priority.append(next_process)
    
print('Priority Scheduling')
disp(priority)
tt = list(map(add,wt,bt))
print(f'Average waiting time = {sum(wt)/n}')
print(f'Average Turn around time time = {sum(tt)/n}')