#ifndef TRIENODE_HPP
#define TRIENODE_HPP

#define ALPHABET_SIZE 26
class TrieNode {
public:
    TrieNode() : end_of_word(false) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }

    TrieNode* children[ALPHABET_SIZE];
    bool end_of_word;
};

#endif