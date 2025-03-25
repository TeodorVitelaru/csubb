import math


def pr2(v1, v2):
    first = abs((v1[0]-v2[0])*(v1[0]-v2[0]))  # abs???? redundant
    second = abs((v1[1]-v2[1])*(v1[1]-v2[1]))
    rez = math.sqrt(first+second)
    return rez


def pr2_ai(p1, p2):
    return math.sqrt((p2[0] - p1[0])**2 + (p2[1] - p1[1])**2)


print(pr2([1, 5], [4, 1]))
print(pr2_ai([1, 5], [4, 1]))
