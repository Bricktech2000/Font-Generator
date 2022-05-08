class Char:
    def __init__(self, rows):
        self.rows = rows
    def append(self, arr):
        for i, row in enumerate(self.rows):
            if i >= len(arr): arr.append('')
            arr[i] += row

class Font:
    def __init__(self, charMap):
        self.charMap = charMap
    def gen(self, string):
        ret = []
        for c in string:
            self.charMap[c].append(ret)
        return '\n'.join(ret)

class FontGenerator:
    def __init__(self, font):
        chrs = font.split('\n\n')
        charMap = {}
        for chr in chrs:
            lines = chr.split('\n')
            charMap[lines[0]] = Char(lines[1:])
        self.font = Font(charMap)
    def gen(self, *argv):
        return self.font.gen(*argv)

import sys
filename = sys.argv[1]
font = open(filename, 'r').read()
generator = FontGenerator(font)
while True: print(generator.gen(input('text: ')))
