#include <iostream>
// #include <format>

#include "EmojiPlusPlus.hpp"

int main() {
    auto set = emojiplusplus::EmojiString("Emoji :smile: for c++ :admission_tickets:");

    std::cout << "Data: \"Emoji :book: for c++ :admission_tickets:\"\n"
              << "Generated data: " << set << '\n'
              << "Tokenizer based generated data: " << emojiplusplus::EmojiToken(set) << '\n';

    //std::cout << std::format("Generated data: {}\n", set);
    //std::cout << std::format("Reverse generated data: {}\n", emojiplusplus::EmojiToString(set));

    return 0;
}
