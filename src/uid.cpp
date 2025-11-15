#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <thread>

namespace UltraFastId {
    static const char CHARS[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "_-"
        "0123456789";
    constexpr int CHARS_SIZE = sizeof(CHARS) - 1;

    inline uint64_t splitmix64(uint64_t& state) noexcept {
        uint64_t z = (state += 0x9E3779B97F4A7C15ULL);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        return z ^ (z >> 31);
    }

    static thread_local uint64_t state = std::random_device{}();

    std::string generate_id(std::size_t k) {
        std::string result;
        result.resize(k);
        uint64_t random_bits = 0;
        int bits_available = 0;
        for (std::size_t i = 0; i < k; ++i) {
            if (bits_available < 6) {
                random_bits = splitmix64(state);
                bits_available = 64;
            }
            result[i] = CHARS[random_bits & 0x3F];
            random_bits >>= 6;
            bits_available -= 6;
        }
        return result;
    }
}
