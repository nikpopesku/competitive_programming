

class MyQueue:
    list1 = []
    list2 = []

    def __init__(self):
        self.list1, self.list2 = [], []

    def push(self, x: int) -> None:
        while self.list2:
            self.list1.append(self.list2.pop())

        self.list1.append(x)

    def pop(self) -> int:
        while self.list1:
            self.list2.append(self.list1.pop())

        return self.list2.pop()

    def peek(self) -> int:
        while self.list1:
            self.list2.append(self.list1.pop())

        return self.list2[-1]

    def empty(self) -> bool:
        return not self.list1 and not self.list2

