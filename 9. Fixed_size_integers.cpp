// 9. Fixed_size_integers.cpp : 
#include <iostream>
#include <cinttypes>
#include <cstdint>

int main()
{
    std::cout << "Fixed size integer demo\n\n";

    int8_t int8{};
    std::cout << "size of int8_t  : " << sizeof(int8_t) << " bytes\n";
    std::cout << "Max : " << static_cast<int>(INT8_MAX) << "\tMIN : " << INT8_MIN << "\n\n";

    int16_t int16{};
    std::cout << "size of int16_t : " << sizeof(int16_t) << " bytes\n";
    std::cout << "Max : " << INT16_MAX << "\tMIN : " << INT16_MIN << "\n\n";

    int32_t int32{};
    std::cout << "size of int32_t : " << sizeof(int32_t) << " bytes\n";
    std::cout << "Max : " << INT32_MAX << "\tMIN : " << INT32_MIN << "\n\n";

    int64_t int64{};
    std::cout << "size of int64_t : " << sizeof(int64_t) << " bytes\n";
    std::cout << "Max : " << INT64_MAX << "\tMIN : " << INT64_MIN << "\n\n";


    uint8_t uint8{};
    std::cout << "size of uint8_t  : " << sizeof(uint8_t) << " bytes\n";
    std::cout << "Max : " << static_cast<int>(UINT8_MAX)  << "\n\n";

    uint16_t uint16{};
    std::cout << "size of uint16_t : " << sizeof(uint16_t) << " bytes\n";
    std::cout << "Max : " << UINT16_MAX << "\n\n";

    uint32_t uint32{};
    std::cout << "size of uint32_t : " << sizeof(uint32_t) << " bytes\n";
    std::cout << "Max : " << UINT32_MAX << "\n\n";

    uint64_t uint64{};
    std::cout << "size of uint64_t : " << sizeof(uint64_t) << " bytes\n";
    std::cout << "Max : " << UINT64_MAX << "\n\n";

    int_fast8_t fint8{};
    std::cout << "size of int_fast8_t : " << sizeof(int_fast8_t) * 8 << " bits\n";

    int_fast16_t fint16{};
    std::cout << "size of int_fast16_t : " << sizeof(int_fast16_t) * 8 << " bits\n";

    uint_least16_t lint16{};
    std::cout << "size of uint_least16_t : " << sizeof(uint_least16_t) * 8 << " bits\n";

    return 0;
}
