import sys


def main():
    # Input
    numNodes = int(input())
    left = [-1] * (numNodes + 1)
    right = [-1] * (numNodes + 1)
    depth = [0, 1]

    for i in range(1, numNodes + 1):
        nums = input().split(' ')
        left[i] = int(nums[0])
        right[i] = int(nums[1])

        if int(nums[0]) > 0:
            depth.append(1 + depth[i])
        if int(nums[1]) > 1:
            depth.append(1 + depth[i])

    numQueries = int(input())
    queries = [int(input()) for i in range(numQueries)]

    # Flips
    flipped = [False] * (depth[-1] + 1)
    output = []

    for q in queries:
        for k in range(q, len(flipped), q):
            flipped[k] = not flipped[k]
        output.append(printTree(left, right, flipped))

    for out in output:
        print(' '.join(out))


def printTree(left, right, flipped, root=1, depth=1):
    if root < 0:
        return []

    if flipped[depth]:
        return printTree(left, right, flipped, right[root], depth + 1) + [
            str(root)] + printTree(left, right, flipped, left[root], depth + 1)
    else:
        return printTree(left, right, flipped, left[root], depth + 1) + [
            str(root)] + printTree(left, right, flipped, right[root], depth + 1)


if __name__ == '__main__':
    sys.setrecursionlimit(10000)
    main()
