import std.stdio;
import std.algorithm;

void print(A...)(A args)
{
    foreach (var; args)
    {
        write(var, " ");
    }
}

void println(A...)(A args)
{
    foreach (var; args)
    {
        write(var, " ");
    }
    writeln();
}

void main()
{

    struct Disjoint
    {
        public int size;
        private int[] rank, par;

        this(int len)
        {
            size = len;
            rank.length = size;
            par.length = size;
            foreach (i; 0 .. size)
            {
                par[i] = i;
            }
        }

        int find(int a)
        {
            while (a != par[a])
            {
                par[a] = par[par[a]];
                a = par[a];
            }
            return a;
        }

        void join(int a, int b)
        {
            int parA = find(a);
            int parB = find(b);
            if (parA != parB)
            {
                if (rank[parA] < rank[parB])
                {
                    swap(parA, parB);
                }
                par[parB] = parA;
                if (rank[parA] == rank[parB])
                {
                    ++rank[parA];
                }
            }
        }
    }

    struct Edge
    {
        bool flight;
        int u, v, w;
    }

    int N, M, P, Q, a, b, c, energy, ans;
    readf!"%d %d %d %d"(N, M, P, Q);
    Edge[] edges;
    int planetsLeft = N;
    int citiesLeft = M;
    auto planets = Disjoint(N + 1);
    auto cities = Disjoint(M + 1);

    foreach (i; 1 .. P + 1)
    {
        readf!" %d %d %d"(a, b, c);
        edges ~= Edge(true, a, b, c);
        energy += c * N;
    }
    foreach (i; 1 .. Q + 1)
    {
        readf!" %d %d %d"(a, b, c);
        edges ~= Edge(true, a, b, c);
        energy += c * M;
    }
    sort!"a.w > b.w"(edges);

    // For better understanding: The nodes of the minimum spanning tree (minimum energy required to connect all nodes)
    Edge[] minReqEdges;

    foreach (e; edges)
    {
        if (e.flight && cities.find(e.u) != cities.find(e.v))
        {
            cities.join(e.u, e.v);
            --citiesLeft;
            ans += e.w * planetsLeft;

            minReqEdges ~= e;
        }
        else if (!e.flight && planets.find(e.u) != planets.find(e.v))
        {
            planets.join(e.u, e.v);
            --planetsLeft;
            ans += e.w * citiesLeft;

            minReqEdges ~= e;
        }
    }

    println("These edges are the minimum required to connect all planets and cities");
    foreach (reqEdge; minReqEdges)
    {
        print(reqEdge);
    }
    println();

    ans = energy - ans;
    writeln(ans);
}
