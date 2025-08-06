class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def order(root):
    if not root.left and not root.right:
        return int(root.val)
    
    left_val = order(root.left)
    right_val = order(root.right)
    
    if root.val == '+':
        return left_val + right_val
    elif root.val == '-':
        return left_val - right_val
    elif root.val == '*':
        return left_val * right_val
    elif root.val == '/':
        return int(left_val / right_val)
        

t = int(input())
for _ in range(t):
    n = int(input())
    v = input().split()
    idx = 0
    root = Node(v[idx])
    idx += 1
    queue = [root]
    
    while queue and idx < n:
        node = queue.pop(0)
        if idx < n:
            node.left = Node(v[idx])
            queue.append(node.left)
            idx += 1
        if idx < n:
            node.right = Node(v[idx])
            queue.append(node.right)
            idx += 1
    
    print(order(root))
