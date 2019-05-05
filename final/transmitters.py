# Authors: Taber McFarlin, Luke Loposky, Chris Byrne
# We pledge our honor that we have abided by the Stevens Honor System
# Problem: Hackerland Radio Transmitters
# https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem

import os


# Complete the hackerlandRadioTransmitters function below.
def hackerlandRadioTransmitters(x, k):
    # Index of the least element that is not under transmitter coverage
    uncovered_i = 0

    # List of transmitters (unnecessary)
    # transmitters = []
    num_transmitters = 0

    while uncovered_i < len(x):
        # Find place for next transmitter
        # Optimal place to put the next transmitter
        best_distance = k + x[uncovered_i]

        # We iterate until we find the greatest distance <= best_distance
        transmitter_i = uncovered_i + 1
        while transmitter_i < len(x) and x[transmitter_i] <= best_distance:
            transmitter_i += 1
        transmitter_i -= 1

        # transmitters.append(transmitter_i)
        num_transmitters += 1

        # Find next uncovered house
        uncovered_i = transmitter_i + 1
        if uncovered_i < len(x):
            uncovered_dist = x[transmitter_i] + k + 1
            while uncovered_i < len(x) and x[uncovered_i] < uncovered_dist:
                uncovered_i += 1

    return num_transmitters


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    x = list(map(int, input().rstrip().split()))

    result = hackerlandRadioTransmitters(sorted(x), k)

    fptr.write(str(result) + '\n')

    fptr.close()
