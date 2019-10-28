def split_(line):
    line = line[:-1].split(' ')
    while '' in line:
        line.remove('')
    return line


regtab = {'A': "0000", 'X': "0001", 'L': "0010", 'B': "0011",
          'S': "0100", 'T': "0101", 'PC': "1000", 'SW': "1001"}

# creating opcode table
op = open('optab')
op = op.readlines()
op = [split_(i) for i in op]
op = [[i[0], i[2], i[3]] for i in op]
optab = {}
for i in op:
    optab[i[0]] = {'len': int(i[1]), 'hex': i[2]}


with open('temp.txt') as f:
    line = f.readline()[:-1].split(' ')
    if 'START' in line:
        if line[0] != '-':
            prg_name = line[0]
        linr = f.readline()[:-1].split(' ')
    print(f'H^{prg_name}^{line[-1]}^{len}')
    while line:
        flag = 0
        addr, op, opr = line
        if '+' in op:
            flag = 1
            op = op[1:]
        if op in optab:
            if optab[op]['len'] == 2:
                pc = + 2
                if ',' in opr:
                    #                     print(f"{optab[op]['hex']}{regtab[opr[0]]}{regtab[opr[-1]]}")
            if optab[op]['len'] == 3:
                pc += 3
                if flag:                            # extended mode
                    pc += 1
                    op = hex(int(optab[op]['hex'], 16) ^ 3)[2:].zfill(2) + '1'
                    opr = symtab[opr].zfill(5)
#                     print(op+opr)
                elif '#' in opr:  # immediate
                    op = hex(int(optab[op]['hex'], 16) ^ 1)[2:].zfill(2)
                    if (opr[1:]).isdigit:
                        opr = hex(int(opr[1:]))[2:].zfill(4)
#                     print(op+opr)
                elif '@' in opr:  # indirect
                    #                     print('ooops')
                    op = hex(int(optab[op]['hex'], 16) ^ 2)[2:].zfill(2)
                else:
                    disp = int(symtab[op], 16) - pc
#                     if disp >= -2048 and disp <= 2047:
                    print(disp)
                    op = hex(int(optab[op]['hex'], 16) ^ 3)[2:].zfill(2)

        line = f.readline()[:-1].split(' ')
        if 'END' in line:
            break
