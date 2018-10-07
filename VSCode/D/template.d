import std.stdio;

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
}
