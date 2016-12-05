import math
from sys import exit, argv, stdin, stdout, stderr

__LOCAL__ = True if (len(argv) > 1 and argv[1] == 'LOCAL') else False

inp = 0
outp = 0

if __LOCAL__:
    inp = open('input.txt', "r")
    outp = open('output.txt', 'w')

def getline():
    if __LOCAL__:
        return inp.readline().strip()
    return stdin.readline()

def puts(*ans, sep=' ', end='\n', file=0):
    if file == 0:
        if __LOCAL__:
            outp.write(str(ans[0]))
            for i in range(1, len(ans)):
                outp.write(sep + str(ans[i]))
            outp.write(str(end))
            return
        stdout.write(str(ans[0]))
        for i in range(1, len(ans)):
            stdout.write(sep + str(ans[i]))
        stdout.write(str(end))
        return
    file.write(str(ans[0]))
    for i in range(1, len(ans)):
        file.write(sep + str(ans[i]))
    file.write(str(end))


def main():
    geg = [1254, 235, 235]
    puts(geg)

if __name__ == '__main__':
    main()

if __LOCAL__:
    inp.close()
    outp.close()