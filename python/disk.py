def fcfs():
    #fcfs disk scheduling
    # cp = 55
    disk = [55,93,176,42,148,27,14,180]
    dist = 0
    for i in range(len(disk)-1):
        dist += abs(disk[i]-disk[i+1])
    return dist  

def sttf():
    #sjf disk scheduling
    def seek_time(i):
        return abs(cp-i)

    dist = 0
    cp = 55
    disk = [93,176,42,148,27,14,180]
    while disk:    
        new_cp = sorted(disk,key=seek_time)[0]
        dist += abs(cp-new_cp)
        disk.remove(new_cp)
        cp = new_cp
    return dist 
    
def cscan():
    #c-scan
    disk = [93,176,42,148,27,14,180]
    cp = 55
    start = 0
    end = 199
    dist = 0
    # mode = int(input('Towards large(1) or small(2)'))
    mode = 1
    if mode == 1: # towards big
        disk.sort()
        for i in range(len(disk)):
            if disk[i] >= cp:
                dist += (abs(cp-disk[i]) + abs(end-disk[i]))
                disk = disk[:i]
                break
        if disk:
            dist += (end - start) + abs(start-disk[0]) + abs(disk[0]-disk[-1])            
    else:
        disk.sort(reverse=True)
        for i in range(len(disk)):
            if disk[i] <= cp:
                dist += (abs(cp-disk[i]) + abs(start-disk[i]))
                disk = disk[:i]
                break
        if disk:
            dist += (end - start) + abs(end-disk[0]) + abs(disk[0]-disk[-1])            
            
    return dist 

print(f'FCFS -> {fcfs()}')
print(f'STTF -> {sttf()}')
print(f'CSCAN -> {cscan()}')