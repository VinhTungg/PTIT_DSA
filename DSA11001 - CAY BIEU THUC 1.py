class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(s):
    st = []
    for c in s:
        if c == '+' or c == '-' or c == '*' or c == '/':
            right = st.pop()
            left = st.pop()
            node = Node(c)
            node.left = left
            node.right = right
            st.append(node)
        else:
            st.append(Node(c))
    return st[0] if st else None

def inorder(root):
    if root:
        if root.val in "+-*/":
            inorder(root.left)
            print(" " + root.val + " ", end="")
            inorder(root.right)
        else:
            print(root.val, end="")

t = int(input())
for _ in range(t):
    s = input()
    root = build_tree(s)
    inorder(root)
    print()