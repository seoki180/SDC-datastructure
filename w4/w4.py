
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None   
        self.right = None  


class BinaryTree:
    def __init__(self):
        self.nodes = {}

    
    def get_node(self, data):
        if data == '.':
            return None
        if data not in self.nodes:
            self.nodes[data] = Node(data)
        return self.nodes[data]

    
    def preorder(self, node):
        if node:
            print(node.data, end='')
            self.preorder(node.left)
            self.preorder(node.right)

    
    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(node.data, end='')
            self.inorder(node.right)

    
    def postorder(self, node):
        if node:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.data, end='')


def solve():
    import sys
    
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    tree = BinaryTree()
    
    
    idx = 1
    for _ in range(n):
        root_data = input_data[idx]
        left_data = input_data[idx+1]
        right_data = input_data[idx+2]
        
        parent = tree.get_node(root_data)
        parent.left = tree.get_node(left_data)
        parent.right = tree.get_node(right_data)
        idx += 3

    
    root_node = tree.nodes['A']

    # 결과
    tree.preorder(root_node)
    print()
    tree.inorder(root_node)
    print()
    tree.postorder(root_node)
    print()

if __name__ == "__main__":
    solve()