package Main

import java.io.DataInputStream
import java.io.InputStream
import java.io.FileInputStream


class FastScanner {
    private val BUFFER_SIZE = 1 shl 16
    private var din: DataInputStream? = null
    private var buffer: ByteArray = ByteArray(BUFFER_SIZE)
    private var bufferPointer: Int = 0
    private var bytesRead: Int = 0

    constructor(IS: InputStream) {
        din = DataInputStream(IS)
        buffer = ByteArray(BUFFER_SIZE)
        bytesRead = 0
        bufferPointer = bytesRead
    }

    constructor(file_name: String) {
        din = DataInputStream(FileInputStream(file_name))
        buffer = ByteArray(BUFFER_SIZE)
        bytesRead = 0
        bufferPointer = bytesRead
    }

    fun readLine(): String {
        val buf = ByteArray(64) // line length
        var cnt = 0
        var c: Int
        c = read().toInt()
        while (c != -1) {
            c = read().toInt()
            if (c == '\n'.toInt())
                break
            buf[cnt++] = c.toByte()
        }
        return String(buf, 0, cnt)
    }

    fun nextInt(): Int {
        var ret = 0
        var c = read()
        while (c <= ' '.toByte())
            c = read()
        val neg = c == '-'.toByte()
        if (neg)
            c = read()
        do {
            ret = ret * 10 + c - '0'.toInt()
            c = read()
        } while (c >= '0'.toByte() && c <= '9'.toByte())

        return if (neg) -ret else ret
    }

    fun nextLong(): Long {
        var ret: Long = 0
        var c = read()
        while (c <= ' '.toByte())
            c = read()
        val neg = c == '-'.toByte()
        if (neg)
            c = read()
        do {
            ret = ret * 10 + c - '0'.toLong()
            c = read()
        } while (c >= '0'.toByte() && c <= '9'.toByte())
        return if (neg) -ret else ret
    }

    fun nextDouble(): Double {
        var ret = 0.0
        var div = 1.0
        var c = read()
        while (c <= ' '.toByte())
            c = read()
        val neg = c == '-'.toByte()
        if (neg)
            c = read()

        do {
            ret = ret * 10 + c - '0'.toDouble()
            c = read()
        } while (c >= '0'.toByte() && c <= '9'.toByte())

        if (c == '.'.toByte()) {
            c = read()
            while (c >= '0'.toByte() && c <= '9'.toByte()) {
                div *= 10.0
                ret += (c - '0'.toByte()) / div
                c = read()
            }
        }

        return if (neg) -ret else ret
    }

    private fun fillBuffer() {
        bufferPointer = 0
        bytesRead = din!!.read(buffer, bufferPointer, BUFFER_SIZE)
        if (bytesRead == -1)
            buffer[0] = -1
    }

    private fun read(): Byte {
        if (bufferPointer == bytesRead)
            fillBuffer()
        return buffer[bufferPointer++]
    }

    fun close() {
        if (din == null)
            return
        din!!.close()
    }
}