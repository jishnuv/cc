#include <iostream>

#include "Trie.h"

int main()
{
    Trie trie;
    
    try
    {
        trie.add("hello", "used as a greeting or to begin a telephone conversation.");
        trie.add("hero", "a person who is admired for their courage, outstanding achievements, or noble qualities.");
        trie.add("hope", "a feeling of expectation and desire for a particular thing to happen.");
        trie.add("atomi", "the smallest particle of a chemical element that can exist.");

        std::cout << trie.getExplanation("atom");

    }
    catch(const std::string& ex)
    {
        std::cout << ex << std::endl;
    }

    return 0;
}
