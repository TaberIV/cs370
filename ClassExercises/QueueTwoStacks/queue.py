class Stack(object):
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


class Queue(object):
    def __init__(self):
        self.stack1 = Stack()
        self.stack2 = Stack()

    def enqueue(self, item):
        self.stack1.push(item)

    def dequeue(self):
        if (self.stack2.is_empty()):
            while self.stack1.size() > 0:
                self.stack2.push(self.stack1.pop())

        return self.stack2.pop()

    def front(self):
        if (self.stack2.is_empty()):
            while self.stack1.size() > 0:
                self.stack2.push(self.stack1.pop())

        return self.stack2.peek()


if __name__ == '__main__':
    q = Queue()

    n = int(input())

    for i in range(n, 0, -1):
        cmd = input()
        op = int(cmd[0])

        if op == 1:
            arg = cmd[2:]
            q.enqueue(arg)
        elif op == 2:
            q.dequeue()
        else:
            print(q.front())
