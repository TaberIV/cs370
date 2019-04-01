#trip.py
#Taber McFarlin, Chris Byrne, Luke Loposky
#We pledge our honor that we have abided by the Stevens Honor System


def main():
    t = int(input())

    for i in range(t):
        # grab input and lengths
        list1 = input()
        list2 = input()

        trips = getTrips(list1, list2)

        for trip in sorted(trips):
            print(trip)


def getTrips(list1, list2):
    width = len(list2) + 1
    height = len(list1) + 1

    matrix = [[0 for i in range(width)] for j in range(height)]

    # Get lenths at each index
    for i in range(1, height):
        for j in range(1, width):
            if list1[i - 1] == list2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])

    # Traverse matrix to find paths of maxLength
    path_matrix = [[set() for i in range(width)] for j in range(height)]
    for i in range(height):
        path_matrix[i][0].add('')
    for j in range(width):
        path_matrix[0][j].add('')

    stack = []
    i = height - 1
    j = width - 1
    stack.append((i, j))

    while stack:
        i, j = stack[-1]

        if path_matrix[i][j]:
            stack.pop()
        elif list1[i - 1] == list2[j - 1]:
            if path_matrix[i - 1][j - 1]:
                c = list1[i - 1]
                paths = path_matrix[i - 1][j - 1]
                path_matrix[i][j] = set(map(lambda path: path + c, paths))
            else:
                stack.append((i - 1, j - 1))
        elif matrix[i - 1][j] > matrix[i][j - 1]:
            if path_matrix[i - 1][j]:
                path_matrix[i][j] = path_matrix[i - 1][j]
            else:
                stack.append((i - 1, j))
        elif matrix[i][j - 1] > matrix[i - 1][j]:
            if path_matrix[i][j - 1]:
                path_matrix[i][j] = path_matrix[i][j - 1]
            else:
                stack.append((i, j - 1))
        else:
            if path_matrix[i - 1][j] and path_matrix[i][j - 1]:
                path_matrix[i][j] = path_matrix[i - 1][j].union(
                    path_matrix[i][j - 1])
            else:
                stack.append((i - 1, j))
                stack.append((i, j - 1))

    return path_matrix[height - 1][width - 1]


if __name__ == '__main__':
    main()
