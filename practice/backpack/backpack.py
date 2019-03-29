from typing import List, Tuple

Item = Tuple[int, float]
ItemConfig = Tuple[Item, List[Item]]


def maxValid(above: ItemConfig, upOver: ItemConfig, item: Item,
             capacity: int) -> ItemConfig:
    ((aboveWgt, aboveVal), aboveList) = above
    ((upOverWgt, upOverVal), upOverList) = upOver
    (itemWgt, itemVal) = item

    if upOverWgt + itemWgt <= capacity:
        newList: List[Item] = upOverList.copy()
        newList.append(item)
        upOver = ((upOverWgt + itemWgt, upOverVal + itemVal), newList)
        ((upOverWgt, upOverVal), upOverList) = upOver

    choices = [above, upOver, (item, [item])]
    choices = list(filter(lambda config: config[0][0] <= capacity, choices))
    return max(choices, key=(lambda config: config[0][1]))


def maxValue(capacity: int, items: List[Item]) -> ItemConfig:
    # Construct matrix
    numItems = len(items)
    valueMatrix = [[((0, 0), []) for value in range(numItems + 1)]
                   for weight in range(capacity + 1)]

    # Fill matrix
    for i in range(1, capacity + 1):
        for j in range(1, numItems + 1):
            item = items[j - 1]
            above = valueMatrix[i - 1][j]
            upOver = valueMatrix[i - 1][j - 1]

            valueMatrix[i][j] = maxValid(above, upOver, item, i)

    for row in valueMatrix:
        print(row)
    return valueMatrix[capacity][numItems]


def main():
    # Input test cases
    numTrials: int = int(input("Number of test cases: "))

    for i in range(numTrials):
        capacity = int(input("Maximum capacity: "))

        # Input items
        numItems: int = int(input("Number of items: "))
        items: List[Item] = []
        for i in range(numItems):
            weight = int(input("Weight of item " + str(i + 1) + ": "))
            value = float(input("Value of item " + str(i + 1) + ": "))
            item: Item = (weight, value)

            items.append(item)

        # Output
        # ((weight, maxValue), optItems)
        backpack: ItemConfig = maxValue(capacity, items)

        # print("Max Value: " + str(backpack[0][1]))
        print(backpack)


if __name__ == '__main__':
    main()
