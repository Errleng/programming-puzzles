package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.TreeSet;

import static java.lang.Math.max;

public class ccc15s3 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int G = in.nextInt();
        int P = in.nextInt();
        AVLTree free = new AVLTree();
        for (int i = 1; i <=G; ++i) {
            free.Insert(i);
        }
        for (int i = 0; i < P; ++i) {
            int g = in.nextInt();
            Integer next = free.Floor(g);
            if (next == null) {
                out.println(i);
                return;
            }
            free.Delete(next);
        }
        out.println(P);
    }
}

class Node {
    public int val;
    public int GetHeight;
    public Node left;
    public Node right;

    public Node (int data) {
        val = data;
        GetHeight = 1;
    }

    int shift;
}

class AVLTree {
    Node root;

    int GetHeight(Node n) {
        if (n == null)
            return 0;
        return n.GetHeight;
    }

    int GetHeightDifference(Node n) {
        if (n == null)
            return 0;
        return (GetHeight(n.left) - GetHeight(n.right));
    }

    Node RightRotation(Node y) {
        Node x = y.left;
        Node temp = x.right;
        x.right = y;
        y.left = temp;
        y.GetHeight = max(GetHeight(y.left), GetHeight(y.right)) + 1;
        x.GetHeight = max(GetHeight(x.left), GetHeight(x.right)) + 1;
        return x;
    }

    Node LeftRotation(Node x) {
        Node y = x.right;
        Node temp = y.left;
        y.left = x;
        x.right = temp;
        x.GetHeight = max(GetHeight(x.left), GetHeight(x.right)) + 1;
        y.GetHeight = max(GetHeight(y.left), GetHeight(y.right)) + 1;
        return y;
    }

    Node Get(int val) {
        return GetNode(root, val);
    }

    private Node GetNode(Node n, int val) {
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

    Integer Floor(Integer val) {
        return FloorVal(root, val);
    }

    private Integer FloorVal(Node n, Integer val) {
        if (n == null) {
            return null;
        }
        if (n.val == val)
            return n.val;
        if (n.val > val)
            return FloorVal(n.left, val);
        Integer res = FloorVal(n.right, val);
        if (res != null && res <= val) {
            return res;
        } else {
            return n.val;
        }
    }

    void Insert(int val) {
        root = InsertNode(root, val);
    }

    private Node InsertNode(Node n, int val) {
        if (n == null)
            return (new Node(val));

        if (val < n.val)
            n.left = InsertNode(n.left, val);
        else if (val > n.val)
            n.right = InsertNode(n.right, val);
        else
            return n;

        n.GetHeight = max(GetHeight(n.left), GetHeight(n.right)) + 1;

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

    private Node MinNode(Node n)
    {
        Node cur = n;
        while (cur.left != null)
            cur = cur.left;
        return cur;
    }

    void Delete(int val) {
        root = DeleteNode(root, val);
    }

    private Node DeleteNode(Node n, int val)
    {
        if (n == null)
            return n;
        if (val < n.val)
            n.left = DeleteNode(n.left, val);
        else if (val > n.val)
            n.right = DeleteNode(n.right, val);
        else
        {
            if ((n.left == null) || (n.right == null))
            {
                Node temp = null;
                if (temp == n.left)
                    temp = n.right;
                else
                    temp = n.left;
                if (temp == null)
                {
                    temp = n;
                    n = null;
                }
                else
                    n = temp;
            }
            else
            {
                Node temp = MinNode(n.right);
                n.val = temp.val;
                n.right = DeleteNode(n.right, temp.val);
            }
        }
        if (n == null)
            return n;
        n.GetHeight = max(GetHeight(n.left), GetHeight(n.right)) + 1;
        int balance = GetHeightDifference(n);
        if (balance > 1 && GetHeightDifference(n.left) >= 0)
            return RightRotation(n);
        if (balance > 1 && GetHeightDifference(n.left) < 0)
        {
            n.left = LeftRotation(n.left);
            return RightRotation(n);
        }
        if (balance < -1 && GetHeightDifference(n.right) <= 0)
            return LeftRotation(n);
        if (balance < -1 && GetHeightDifference(n.right) > 0)
        {
            n.right = RightRotation(n.right);
            return LeftRotation(n);
        }
        return n;
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