class Resistor:
    resistorList = []
    resistance = 0
    error = 0

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
            sol = Resistor([closest], target)
            if sol.error <= tolerance:
                return sol
            else:
                return Resistor({}, target)
        elif index == len(resistorList):
            closest = resistorList[index - 1]
            sol = Resistor([closest], target)
            if sol.error <= tolerance:
                return sol
            else:
                return Resistor([], target)
        elif resistorList[index] == target:
            return Resistor([target], target)
        else:
            # Remove resistors that are too small
            closest = resistorList[index - 1]
            del resistorList[0:index - 1]

            return Resistor._calc_resistors(target, tolerance, num_resistors,
                                            resistorList)

    def _calc_resistors(target, tolerance, num_resistors, resistorList):
        aboveSol = Resistor([], target)
        bestSol = Resistor([], target)

        # Add greatest resistor until
        resistor = resistorList[-1]
        resList = aboveSol.resistorList
        for i in range(num_resistors):
            resList = resList.copy()
            resList.append(resistor)

            currSol = Resistor(resList, target)

            # Check if solution is better than existing ones
            if currSol.resistance > target:
                aboveSol = currSol
            if currSol.error < bestSol.error:
                bestSol = currSol

            # Adding more resistors only goes lower
            if currSol.resistance < target:
                break

        # For each other resistor, try replacing higher in resistors
        # aboveSol to check if that gets you closer to target
        for i in range(len(resistorList) - 2, 0, -1):
            resistor = resistorList[i]

            # Replace old resistors with lower ones
            while True:
                resList = aboveSol.resistorList.copy()
                resList.pop()
                resList.insert(0, resistor)
                currSol = Resistor(resList, target)

                if currSol.error <= bestSol.error:
                    bestSol = currSol

                if currSol.resistance > target:
                    aboveSol = currSol
                else:
                    resList2 = resList
                    while True:
                        resList2 = resList2.copy()
                        resList2.pop()
                        currSol = Resistor(resList2, target)

                        if currSol.error <= bestSol.error:
                            bestSol = currSol

                        if currSol.resistance > target:
                            if currSol.error <= aboveSol.error:
                                aboveSol = currSol
                            break
                    break

                if resList[-1] == resistor:
                    break

        if bestSol.error > tolerance:
            bestSol = Resistor([], target)
        return bestSol

    # Parameterized constructor
    def __init__(self, resList, target):
        self.resistorList = resList

        if len(resList) != 0:
            for res in resList:
                self.resistance += 1 / res
            self.resistance = 1 / self.resistance

        self.error = abs(target - self.resistance) * 100 / target
