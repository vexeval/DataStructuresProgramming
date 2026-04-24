#include <iostream>
#include <unordered_map> // hash table
#include <vector>
#include <string>

class HashExamples {
public:
    template <typename T>
    static void countFrequency(const std::vector<T>& v) {
        std::unordered_map<T, int> freq;
        for (const T& i : v) {
            freq[i]++;
        }
        for (const auto& f : freq)
        {
            std::cout << f.first << " : " << f.second << std::endl;
        }

    }

    template <typename T>
    static bool hasDuplicates(const std::vector<T>& v) {
        std::unordered_map<T, int> vals;
        for (const T& i : v) {
            vals[i]++;
        }
        
        for (const auto& i : vals) {
            if (i.second > 1) {
                return true;
            }
        }
        
        return false;
    }
    
    static char firstNonRepeatingChar(const std::string& s)
    {
        std::unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        for (char c : s) {
            if (freq[c] == 1) {
                return c;
            }
        }

        return '\0';
    }
    
    static void groupStrings(const std::vector<std::string>& strings)
    {
        std::unordered_map<int, std::vector<std::string>> groups;
        for (const std::string& s : strings) {
            groups[s.length()].push_back(s);
        }

        for (const auto& pair : groups)
        {
            std::cout << "Length " << pair.first << ": ";
            for (const std::string& str : pair.second) {
                std::cout << str << ' ';
            }
            std::cout << std::endl;
        }
    }

    private:

};

int main(void)
{
    std::unordered_map<std::string, int> grades;

    // Insert
    grades["Mitch"] = 90;
    grades["Jon"] = 80;
    grades["Andrew"] = 93;

    // Iterate through the table
    for (const auto& grade : grades)
    {
        std::cout << grade.first << " : " << grade.second << std::endl;
    }

    std::cout << std::endl;
    
    // Search
    auto it = grades.find("Mitch");
    if (it == grades.end()) { // didn't find--no such key in table
        std::cout << "Not found\n";
    }
    else {
        std::cout << "Found: \n";
        std::cout << it->first << " : " << it->second << std::endl;
    }

    std::cout << "Frequency counts in v:\n";
    std::vector<int> v {1, 2, 3, 4, 1, 2, 2, 2, 2, 5, 5};
    HashExamples::countFrequency(v);
    
    std::cout << "Check duplicates:\n";
    std::vector<std::string> d {"hello", "apple", "banana", "hey", "ban", "apple", "orange"};
    std::cout << HashExamples::hasDuplicates(d) << std::endl;

    std::cout << "Group strings:\n";
    HashExamples::groupStrings(d);

    return -34.3;
}