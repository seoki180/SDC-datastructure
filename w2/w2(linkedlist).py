import sys

# 링크드 리스트 형태로 구현
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedStack:
    def __init__(self):
        self.top_node = None
        self.current_size = 0

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.top_node
        self.top_node = new_node
        self.current_size += 1

    def pop(self):
        if self.empty_status():
            return -1
        
        pop_data = self.top_node.data
        self.top_node = self.top_node.next
        self.current_size -= 1
        return pop_data

    def size(self):
        return self.current_size

    def empty_status(self):
        return self.top_node is None

    def top(self):
        if self.empty_status():
            return -1
        return self.top_node.data

def solve():
    input = sys.stdin.read().splitlines()
    if not input:
        return

    n = int(input[0])
    stack = LinkedStack()
    output = []

    for i in range(1, n + 1):
        command = input[i].split()
        
        if command[0] == "push":
            stack.push(int(command[1]))
        elif command[0] == "pop":
            output.append(str(stack.pop()))
        elif command[0] == "size":
            output.append(str(stack.size()))
        elif command[0] == "empty":
            # 문제 조건에 따라 비어있으면 1, 아니면 0 출력
            output.append("1" if stack.empty_status() else "0")
        elif command[0] == "top":
            output.append(str(stack.top()))

    sys.stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    solve()