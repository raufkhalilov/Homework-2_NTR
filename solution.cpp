#include <iostream>
#include <iomanip>

void invertBits(char* ptr, int length) {
    if (ptr == nullptr || length <= 0) {
        std::cerr << std::endl << "Invalid pointer or length" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        char byte = *(ptr + i);
        byte ^= 0xAA; // 0xAA в двоичном: 10101010
        *(ptr + i) = byte;
    }

}


void invertBits(char* ptr, size_t length, int startBit, int endBit) {
    if (startBit >= 0 && endBit >= 0 && startBit <= 7 && endBit <= 7 && startBit <= endBit) 
    {
        for (size_t i = 0; i < length; ++i) {
            for (int j = startBit; j <= endBit; ++j) {
                ptr[i] ^= (1 << j);
            }
        }
    }
    else
    {
        std::cerr << std::endl <<"Incorrect data" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    const int length = 3;
    char bytes[3] = { 0xAA, 0xCC, 0xF0 };

    std::cout << "Before inverting bits(Ox): ";
    for (int i = 0; i < 3; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)bytes[i] << " ";
    }

    invertBits(bytes, length);    //-инвертирование нечетных бит (если счет начать нуля)
    //invertBits(bytes, length, 2, 5);//-инвертирование участка в каждом байте

    std::cout << std::endl << "After inverting bits(Ox): ";
    for (int i = 0; i < 3; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)bytes[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
