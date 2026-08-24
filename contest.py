

squars = [i**2 for i in range(1, int(10**2.5)+1)]
yzh = set()

all = [0 for i in range(10**5+1)]
# print(all)

n = int(input())

for sq1 in squars:
    ind = sq1
    yzh.add(ind)
    all[ind] = 1
# print(all.count(0))


squars2 = []
for sq1 in squars:
    ind = sq1
    for sq2 in squars:
        ind += sq2
        if (ind <= 10**5):
            all[ind] = 2
# print(all.count(0))

if all[n] != 0:
    print(all[n])
else:
    squars3 = []
    for sq2 in squars:
        for sq in squars:
            ind = sq+sq2
            if ind not in yzh:
                yzh.add(ind)
                if (ind <= 10**5):
                    squars3.append(ind)
                    all[ind] = 3    
    # print(all.count(0))

    squars4 = []
    for sq3 in squars3:
        for sq in squars:
            ind = sq3+sq
            if ind not in yzh:
                yzh.add(ind)
                if ind < 10**5:
                    squars4.append(ind)
                    all[ind] = 4
                else:
                    break

    # print(all.count(0))

    squars5 = []
    for sq4 in squars4:
        for sq in squars:
            ind = sq4+sq
            if ind not in yzh:
                yzh.add(ind)
                if ind < 10**5:
                    squars5.append(ind)
                    all[ind] = 5
                else:
                    break
    # print(all.count(0)) 


    for sq5 in squars5:
        for sq in squars:
            ind = sq5+sq
            if ind not in yzh:
                yzh.add(ind)
                if ind < 10**5:
                    all[ind] = 6
                else:
                    break
            




