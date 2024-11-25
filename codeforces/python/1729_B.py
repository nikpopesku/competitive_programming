import sys

input = sys.stdin.readline

if __name__ == '__main__':
    tests = int(input())

    counter = 0
    length = {}
    codes = {}
    values = []
    for i in range(tests):
        length[counter] = int(input())
        codes[counter] = input().strip()
        counter += 1

    for code in codes.values():
        value = []
        i = len(code)

        while i > 0:
            step = 1 if code[i-1] != '0' else 3
            element = int(code[i - step:i])
            element = element // 10 if element >= 100 else element
            value.append(chr(element + ord('a') - 1))
            i -= step

        values.append(''.join(value[::-1]))

    for v in values:
        print(v)




