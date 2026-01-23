import sys

# 강의 자료의 배열 형태 구현
class Stack:
    def __init__(self):
       
        self.items = []

    def push(self, x):
        
        self.items.append(x)

    def pop(self):
        if self.empty():
            return -1
        return self.items.pop()

    def size(self):
        return len(self.items)

    def empty(self):
        return 1 if not self.items else 0

    def top(self):
        if self.empty():
            return -1
        return self.items[-1]


def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return

    n = int(input_data[0])
    stack = Stack()
    results = []

    for i in range(1, n + 1):
        command = input_data[i].split()
        
        if command[0] == "push":
            stack.push(int(command[1]))
        elif command[0] == "pop":
            results.append(str(stack.pop()))
        elif command[0] == "size":
            results.append(str(stack.size()))
        elif command[0] == "empty":
            results.append(str(stack.empty()))
        elif command[0] == "top":
            results.append(str(stack.top()))

    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    solve()