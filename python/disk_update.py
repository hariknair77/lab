#c-scan

disk = [176, 79, 34, 60, 92, 11, 41, 114]
cp = 50
start = 0
end = 199
dist = 0
seq = []
mode = 1
# mode = int(input('Towards large(1) or small(2)'))
if mode == 1: # towards big
    disk.sort()
    for i in range(len(disk)):
        if disk[i] >= cp:
            dist += (abs(cp-disk[i]) + abs(disk[-1]-disk[i]))
            temp = disk[-1]
            seq.extend(disk[i:])
            disk = disk[:i]
            break
    if disk:
        dist += abs(end-temp) + abs(start-disk[0]) + abs(disk[0]-disk[-1])    
        seq.extend(disk)
# else:
#     disk.sort(reverse=True)
#     for i in range(len(disk)):
#         if disk[i] <= cp:
#             dist += (abs(cp-disk[i]) + abs(start-disk[i]))
#             disk = disk[:i]
#             break
#     if disk:
#         dist += abs(end-disk[0]) + abs(disk[0]-disk[-1])            

# print(dist)    


#scan
disk = [176, 79, 34, 60, 92, 11, 41, 114]
cp = 50
start = 0
end = 199
dist = 0
seq = []
mode = 1
# Direction = left (We are moving from right to left)
disk.sort(reverse=True)
for i in range(len(disk)):
    if disk[i] <= cp:
        dist += (abs(cp-disk[i]) + abs(disk[-1]-disk[i]))
        temp = disk[-1]
        seq.extend(disk[i:])
        disk = disk[:i]
        break
if disk:
    seq.append(0)
    dist += abs(start-temp)+abs(start-disk[i-1]) + abs(disk[i-1] - disk[0])  
    disk.reverse()
    seq.extend(disk)
    
    
#fcfs disk scheduling
# cp = 55
disk = [55,93,176,42,148,27,14,180]
dist = 0
for i in range(len(disk)-1):
    dist += abs(disk[i]-disk[i+1])
print(dist)    