#include <stdint.h>
#include <iostream>
#include <string>

class ByteStream {

    private:
        char* buffer; // or unsigned char, or std::byte, or uint8_t
        uint32_t* currentByteIndex;

    public:
        char readByte(); // or unsigned char, or std::byte, or uint8_t
        std::string readASCIIString(int lenght); // or char*

        // good idea to write unit tests for these:
        int32_t readInt32(int32_t signedNumber); // LEB128 decoded!
        uint32_t readUInt32(uint32_t unsignedNumber); // LEB128 decoded!

        // later add readInt64, readFloat64, etc.

        void seek(int offset); // move the currentByteIndex by offset (can be negative!)
        
        // optional:
        // currentByteIndex();
        // remainingByteCount();
        // totalByteCount();
        // etc. 

        // recommended (not necessarily on this class though):
        // printHex(char byte)
        // printBinary(char byte)
        // printBinary(int32_t val)
        // printBinary(uint32_t val)
};

// https://stackoverflow.com/questions/22746429/c-decimal-to-binary-converting
std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int32_t readInt32(int32_t num) {
    // 1. represent the number in binary
    std::string binNum = toBinary(num);

    int binNumSize = binNum.length();
    // 2. zero extend the number up to a multiple of 7 bits
    while(binNumSize%7 != 0) {
        binNum.insert(0, 1, '0');
    }
    // 3. negating all bits (one's complement) bv: 1010 wordt 0101
    // 4. adding one (two's complement) bv: 111100001110110111111 wordt
    //                                      111100001110111000000
    // 5. split into 7-bit groups
    // 6. add high 1 bits on all but last (most significant) group to form bytes
    // 7. in hexadecimal
    // 8. output stream (LSB to MSB)
}

uint32_t readUInt32(uint32_t uNum) {
    // 1. represent the number in binary
    std::string binUNum = toBinary(uNum);
    // 2. zero extend the number up to a multiple of 7 bits
    
    // 3. split into 7-bit groups
    // 4. add high 1 bits on all but last (most significant) group to form bytes
    // 5. in hexadecimal
    // 6. output stream (LSB to MSB)
    
}