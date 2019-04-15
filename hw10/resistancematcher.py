# Authors: Taber McFarlin, Chris Byrne and Luke L
# We pledge our honor that we have abided by the Stevens Honor System

import sys
from resistor import Resistor


def main():
    # Parse Input
    if len(sys.argv) == 1:
        print(("Usage: python3.7 resistancematcher <target>"
               " <tolerance %> <num resistors> <input file>"))
        return
    elif len(sys.argv) < 5:
        print("Expected 4 arguments, got " + str(len(sys.argv) - 1) + ".")
        return

    # Check Input
    try:
        target = float(sys.argv[1])
        assert target > 0
    except (ValueError, AssertionError) as e:
        print("Error: Invalid target value '" + sys.argv[1] + "'.")
        return

    try:
        tolerance = float(sys.argv[2])
        assert tolerance >= 0 and tolerance < 100
    except (ValueError, AssertionError) as e:
        print("Error: Invalid tolerance value '" + sys.argv[2] + "'.")
        return

    try:
        num_resistors = int(sys.argv[3])
        assert num_resistors > 0 and num_resistors <= 10
    except (ValueError, AssertionError) as e:
        print("Error: Invalid number of resistors '" + sys.argv[3] + "'.")
        return

    try:
        input_file = sys.argv[4]
        resistors_file = open(input_file, "r")
    except FileNotFoundError:
        print("Error: Input file '" + input_file + "' not found.")
        return

    # Read input_file
    resistors = []
    line = resistors_file.readline()
    line_no = 1
    while line:
        try:
            resistor = float(line)

            assert resistor > 0
            resistors.append(resistor)
            line = resistors_file.readline()
            line_no += 1
        except (ValueError, AssertionError) as e:
            print("Error: Invalid value '" + line.strip() + "' on line " +
                  str(line_no) + ".")
            return

    if len(resistors) == 0:
        print("Empty input file.")

    # Display arguments
    print("Max resistors in parallel: " + str(num_resistors))
    print("Tolerance: " + str(tolerance) + " %")

    # Run program
    resistors = sorted(resistors)
    sol = Resistor.calc_resistors(target, tolerance, num_resistors, resistors)

    if len(sol.resistorList) > 0:
        print("Target resistance of " + str(target) +
              " ohms is possible with " + str(sol.resistorList) +
              " ohm resistors.")
        print("Best fit: {:0.5} ohms".format(sol.resistance))
        print("Percent error: {:0.3} %".format(sol.error))
    else:
        print("Target resistance of " + str(target) + " ohms is not possible.")


if (__name__ == "__main__"):
    main()