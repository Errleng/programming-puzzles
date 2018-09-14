package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;

public class ccc15s3 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int G = in.nextInt();
        int P = in.nextInt();
        boolean[] docked = new boolean[G + 1];
        AVLTree tree = new AVLTree();
        for (int i = 1; i <=G; ++i) {
            tree.Insert(-i);
        }
        for (int i = 1; i <= P; ++i) {
            int g = in.nextInt();
            if (tree.LowerBound(-g) != null) {
                out.println(i);
                return;
            }
            Node get = tree.LowerBound(-g);
            if (get != null) {
                tree.Delete(get.val);
            }
//            boolean fail = true;
//            for (int j = g; j > 0; --j) {
//                if (!docked[j]) {
//                    fail = false;
//                    docked[j] = true;
//                    ++planes;
//                    break;
//                }
//            }
//            if (fail) {
//                break;
//            }
        }
        out.println(P);
    }
}

class Node {
    public int val;
    public int height;
    public Node left;
    public Node right;

    public Node (int data) {
        val = data;
        height = 1;
    }

    int shift;
}

class AVLTree {
    Node root;

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int GetHeight(Node n) {
        if (n == null)
            return 0;
        return n.height;
    }

    int GetHeightDifference(Node n) {
        if (n == null)
            return 0;
        return (GetHeight(n.left) - GetHeight(n.right));
    }

    Node RightRotation(Node y) {
        Node x = y.left; // Shift left child to be new root
        Node temp = x.right; // Save x right child to give to y
        x.right = y; // Set y to x right child
        y.left = temp; // Give x right child to y as left child
        y.height = max(GetHeight(y.left), GetHeight(y.right)) + 1;
        x.height = max(GetHeight(x.left), GetHeight(x.right)) + 1;
        return x; // New root n of the subtree
    }

    Node LeftRotation(Node x) {
        Node y = x.right;
        Node temp = y.left;
        y.left = x;
        x.right = temp;
        x.height = max(GetHeight(x.left), GetHeight(x.right)) + 1;
        y.height = max(GetHeight(y.left), GetHeight(y.right)) + 1;
        return y;
    }

    Node Get(int val) {
        return GetNode(root, val);
    }

    Node GetNode(Node n, int val) {
        if (n == null) {
            return null;
        }
        if (n.val < val) {
            return GetNode(n.left, val);
        } else if (n.val > val) {
            return GetNode(n.right, val);
        } else {
            return n;
        }
    }

    Node LowerBound(int val) {
        return LowerBoundNode(root, val);
    }

    Node LowerBoundNode(Node n, int val) {
        if (n == null) {
            return null;
        }
        if (n.val == val) {
            return n;
        } else if (n.val > val) {
            return GetNode(n.left, val);
        } else {

        }
    }
    void Insert(int val) {
        root = InsertNode(root, val);
    }

    Node InsertNode(Node n, int val) {
        if (n == null)
            return (new Node(val));

        if (val < n.val)
            n.left = InsertNode(n.left, val);
        else if (val > n.val)
            n.right = InsertNode(n.right, val);
        else
            return n;

        n.height = max(GetHeight(n.left), GetHeight(n.right)) + 1;

        int balance = GetHeightDifference(n);

        if (balance > 1 && val < n.left.val)
            return RightRotation(n);
        if (balance > 1 && val > n.left.val) {
            n.left = LeftRotation(n.left);
            return RightRotation(n);
        }
        if (balance < -1 && val > n.right.val)
            return LeftRotation(n);
        if (balance < -1 && val < n.right.val) {
            n.right = RightRotation(n.right);
            return LeftRotation(n);
        }
        return n;
    }

    Node MinNode(Node n)
    {
        Node cur = n;
        while (cur.left != null)
            cur = cur.left;
        return cur;
    }

    void Delete(int val) {
        this.DeleteNode(root, val);
    }

    Node DeleteNode(Node n, int val) {
        if (n == null) {
            return n;
        }
        if (val < n.val) {
            n.left = DeleteNode(n.left, val);
        } else if (val > n.val) {
            n.right = DeleteNode(n.right, val);
        } else {
            if ((n.left == null) || (n.right == null)) {
                Node t = null;
                if (t == n.left) {
                    t = n.right;
                } else {
                    t = n.left;
                }
                if (t == null) {
                    t = n;
                    n = null;
                } else {
                    n = t;
                }
            } else {
                Node t = MinNode(n.right);
                n.val = t.val;
                n.right = DeleteNode(n.right, t.val);
            }
        }
        if (n == null) {
            return n;
        }
        n.height = max(GetHeight(n.left), GetHeight(n.right));
        int balance = GetHeightDifference(n);
        if (balance > 1 && GetHeightDifference(root.left) >= 0)
            return RightRotation(root);
        if (balance > 1 && GetHeightDifference(root.left) < 0)
        {
            root.left = LeftRotation(root.left);
            return RightRotation(root);
        }
        if (balance < -1 && GetHeightDifference(root.right) <= 0)
            return LeftRotation(root);
        if (balance < -1 && GetHeightDifference(root.right) > 0)
        {
            root.right = RightRotation(root.right);
            return LeftRotation(root);
        }
        return root;
    }

    void Traverse(Node n) {
        if (n != null) {
            Traverse(n.left);
            System.out.println(n.val + " ");
            Traverse(n.right);
        }
    }

    void BFSPrint() {
        LinkedList<Node> ns = new LinkedList<>();
        ns.add(root);
        int depthCount = ns.size();
        root.shift = GetHeight(root) * 4;
        while (ns.size() != 0) {
            Node n = ns.poll();
            depthCount = depthCount - 1;
            if (depthCount < 0) {
                System.out.println();
                depthCount = ns.size();
            }
            if (n != null) {

                for (int i = 0; i < n.shift; ++i) {
                    System.out.print(' ');
                }

                System.out.print(n.val);

                if (n.left != null) {
                    n.left.shift = n.shift - root.shift/2;
                    ns.add(n.left);
                }

                if (n.right != null) {
                    n.right.shift = n.shift;
                    ns.add(n.right);
                }
            }
        }
    }
}