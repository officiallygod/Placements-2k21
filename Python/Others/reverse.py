from collections import deque


class Stack:

    def __init__(self):
        self.container = deque()

    def push(self, val):
        self.container.append(val)

    def pop(self):
        return self.container.pop()

    def peek(self):
        return self.container[-1]

    def is_empty(self):
        return len(self.container) == 0

    def size(self):
        return len(self.container)

    def reverseString(self, strings):
        for ch in strings:
            # print(ch)
            self.container.append(ch)
        # print(self.container)

        rstr = ''
        while (self.size()) != 0:
            rstr += self.pop()  # this line not working says "pop from an empty deque"

        return rstr


c = Stack()

if __name__ == "__main__":
    print(c.reverseString("We will conquere COVI-19"))
    # print(c.container)
