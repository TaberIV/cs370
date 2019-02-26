def operand(op):
    return op >= 'a' and op <= 'z'


if __name__ == '__main__':
    n = int(input())
    operators = ['+', '-', '*', '/', '^']

    for i in range(n, 0, -1):
        exp = input()
        stack = []

        for op in exp:
            if operand(op):
                print(op, end="")
            elif op == '(':
                stack.append(op)
            elif op == ')':
                while stack[len(stack) - 1] != '(':
                    print(stack.pop(), end="")
                stack.pop()
            elif op in operators:
                while (not operand(op)) and (stack[len(stack) - 1] in operators) and
                operators.index(op) < operators.index(stack[len(stack) - 1]):
                    print(stack.pop(), end="")
                stack.append(op)
        print()
