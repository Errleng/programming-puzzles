package main;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class FastReader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public FastReader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public FastReader(InputStream inputStream)
    {
        din = new DataInputStream(inputStream);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public FastReader(String file_name)
    {
        try {
            din = new DataInputStream(new FileInputStream(file_name));
        } catch (IOException e) {
            e.printStackTrace();
        }
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine()
    {
        byte[] buf = new byte[64];
        int cnt = 0, c;
        try {
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return new String(buf, 0, cnt);
    }

    String next()
    {
        byte[] buf = new byte[64];
        int cnt = 0, c;
        try {
            c = read();
            while (c <= ' ')
                c = read();
            buf[cnt++] = (byte) c;
            while ((c = read()) > ' ') {
                buf[cnt++] = (byte) c;
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt()
    {
        int ret = 0;
        try {
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return ret;
    }

    public long nextLong()
    {
        long ret = 0;
        try {
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return ret;
    }

    public double nextDouble()
    {
        double ret = 0, div = 1;
        try {
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg)
                return -ret;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        try {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close()
    {
        if (din == null)
            return;
        try {
            din.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
