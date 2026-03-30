#include "Trie.hpp"
#include <string>
#include <iostream>
#include <cctype>

Trie::Trie() {
    root = new TrieNode();
}

Trie::Trie(const std::vector<std::string>& v) : Trie()
{
    for (const std::string& s : v)
    {
        insert(s);
    }
}

void Trie::insert(const std::string& s) {
    TrieNode* cur = root;
    for (char c : s) {
        if (!isalpha(c)) {
            continue;
        }
        int i = tolower(c) - 'a';
        if (!cur->children[i]) { // no path exists, so create one
            cur->children[i] = new TrieNode();
        }
        cur = cur->children[i];
    }
    cur->end_of_word = true;
}

bool Trie::search(const std::string& s) const {
    TrieNode* cur = root;

    for (char c : s) {
        if (!isalpha(c)) continue;
        int i = tolower(c) - 'a';
        if (!cur->children[i]) return false; // no word in pool
        cur = cur->children[i];
    }
    return cur && cur->end_of_word;
}

void Trie::remove(const std::string& s)
{
    removeHelper(root, s, 0);
}

bool Trie::removeHelper(TrieNode*& node, const std::string& s, int depth)
{
    if (!node) return false;

    // reached end of word string
    if (depth == s.length()) {
        if (node->end_of_word) {
            node->end_of_word = false;
        }

        // no other children
        return hasNoChildren(node);
    }

    // move to next char
    int i = tolower(s[depth] - 'a');
    if (removeHelper(node->children[i], s, depth + 1))
    {
        delete node->children[i];
        node->children[i] = nullptr;
        return !node->end_of_word && hasNoChildren(node);
    }

    return false;
}

bool Trie::hasNoChildren(TrieNode* node) const
{
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) return false;
    }
    return true;
}

void Trie::print() const
{
    std::string word = "";
    print(root, word);
}

void Trie::print(const TrieNode* node, std::string& word) const
{
    if (!node) return;

    if (node->end_of_word) {
        std::cout << word << std::endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i]) {
            char c = 'a' + i;
            word.push_back(c);
            print(node->children[i], word);
            word.pop_back();
        }
    }

}