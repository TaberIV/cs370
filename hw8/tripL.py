#trip.py
#Taber McFarlin, Chris Byrne, Luke Loposky
#We pledge our honor that we have abided by the Stevens Honor System

matrix = [[0 for i in range(100)] for j in range(100)]


def main():

    t = int(input())

    while (t > 0):

        #grab input and lengths
        alice = input()
        bob = input()

        lengtha = len(alice)
        lengthb = len(bob)

        #dp
        #call lcslength to find length of lcs in the very last [index][index]
        lcslength(alice, bob, lengtha, lengthb)

        #output
        res = sb(alice, bob, lengtha, lengthb)

        print(res)

        #decrement
        t -= 1


def sb(list1, list2, i, j):

    result = []

    if i == 0 or j == 0:
        return ['']

    if list1[i - 1] == list2[j - 1]:
        temp = sb(list1, list2, i - 1, j - 1)
        for k in temp:
            result.append(k + list1[i - 1])
    elif matrix[i - 1][j] > matrix[i][j - 1]:
        result = sb(list1, list2, i - 1, j)
    elif matrix[i][j - 1] > matrix[i - 1][j]:
        result = sb(list1, list2, i, j - 1)
    else:
        p1 = sb(list1, list2, i - 1, j)
        p2 = sb(list1, list2, i, j - 1)
        result = p1 + p2

    return result


def lcslength(list1, list2, length1, length2):

    #could pass it length+1 in main
    for index1 in range(length1 + 1):

        for index2 in range(length2 + 1):

            if index1 == 0 or index2 == 0:
                matrix[index1][index2] = 0
            elif list1[index1 - 1] == list2[index2 - 1]:
                matrix[index1][index2] = matrix[index1 - 1][index2 - 1] + 1
            else:
                matrix[index1][index2] = max(matrix[index1 - 1][index2],
                                             matrix[index1][index2 - 1])


if __name__ == '__main__':
    main()
