#
# ~oisín~ Python3 Template
#

import sys
import math
import statistics
import datetime
import collections

def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = 1
    e = False
    for x in a:
        if ans > 1000000000000000000:
            print("-1")
            e = True
            break
        ans *= x
    if ans > 1000000000000000000 and e == False:
        print("-1")
    elif e == False:
        print(ans)

if __name__ == '__main__':
    main()
