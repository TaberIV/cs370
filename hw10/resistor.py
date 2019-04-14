class Resistor:
    resistorDict = {}
    resistance = 0
    percentError = 0

    def calc_resistors(target, tolerance, num_resistors, resistorList):
        # Binary search for target in resistorList
        def found_index(index):
            if index == 0 or index == len(resistorList):
                return True
            else:
                r_i = resistorList[index]
                r_j = resistorList[index - 1]

                return r_i == target or r_i > target and r_j < target

        index = len(resistorList) // 2
        low = 0
        high = len(resistorList)
        while not found_index(index):
            if resistorList[index] < target:
                low = index + 1
            else:
                high = index - 1

            index = (low + high) // 2

        closest = 0
        if index == 0:
            closest = resistorList[0]
            return Resistor({closest: 1})
        elif index == len(resistorList):
            closest = resistorList[index - 1]
            return Resistor({closest: 1})
        else:
            closest = resistorList[index - 1]

        return Resistor({})

    # Parameterized constructor
    def __init__(self, dict):
        self.resistorDict = dict