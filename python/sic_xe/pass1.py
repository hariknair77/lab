#Program file
# path = input('Enter file : ')
path = 'fib.txt'
#preprocessing line...
def split_(line):
    line = line[:-1].split(' ')  
    while '' in line:
        line.remove('')
    if len(line) == 2:
        line.insert(0,'-')
    if len(line) == 1:
        line.insert(0,'-')
        line.insert(2,'-')
    return line

#creating opcode table
op = open('optab')
op = op.readlines()
op = [split_(i) for i in op]
op = [ [i[0],i[2],i[3]] for i in op]
optab = {}
for i in op:
    optab[i[0]] = {'len':int(i[1]),'hex':i[2]}

#first pass...
locctr = 0
temp = []
symtab = {}
sym  = open('symtab.txt','w')
temp = open('temp.txt','w')

with open(path,'r') as f:
    line = split_(f.readline())
    if 'START' in line:
        locctr = int(line[-1],16)
        start_addr = locctr
        temp.write(f'{line[0]} {line[1]} {hex(locctr)[2:].zfill(5)}\n')
        line = split_(f.readline())
    else:
        locctr=start_addr=0
    while line:
        if '.' not in line:
            if line[0] != '-':
                if line[0] in symtab:
                    print('Duplicate error')
                else:
                    symtab[line[0]] = locctr
                    sym.write(f'{line[0]} {hex(locctr)[2:].zfill(5)}\n')
            temp.write(f'{hex(locctr)[2:].zfill(5)} {line[1]} {line[2]}\n')
            if line[1] in optab or line[1][1:] in optab:
                if '+' in line[1]:
                        locctr += 4
                elif optab[line[1]]['len'] == 1:
                    locctr += 1
                elif optab[line[1]]['len'] == 2:
                    locctr += 2
                else:
                    locctr += 3
            elif line[1] == 'WORD':
                locctr += 3
            elif line[1] == 'BYTE':
                if 'x' in line[2]:
                    locctr += (len(line[2])-3)/2
                else:
                    locctr += len(line[2])-3
            elif line[1] == 'RESW':
                locctr += 3*int(line[2])
            elif line[1] == 'RESB':
                locctr += int(line[2])
            elif line[1] == 'END':
                temp.write(f'{hex(locctr)[2:].zfill(5)} {line[1]} {start_addr}\n')
                break
        line = split_(f.readline())

prg_len = hex(locctr-start_addr)[2:].zfill(5)
temp.close()
sym.close()