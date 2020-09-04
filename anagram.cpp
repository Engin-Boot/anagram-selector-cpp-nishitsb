#include "anagram.h"

void incrementCharCount(const std::string &word1, int *charCount)
{
    for (int i = 0; i < word1.length(); i++)
    {
        if (word1[i] != ' ')
            charCount[tolower(word1[i]) - 97]++;
    }
}

void decrementCharCount(const std::string &word2, int *charCount)
{
    for (int i = 0; i < word2.length(); i++)
    {
        if (word2[i] != ' ')
            charCount[tolower(word2[i]) - 97]--;
    }
}

bool Anagram::WordPairIsAnagram(const std::string &word1, const std::string &word2)
{
    int charCount[26] = {0};

    incrementCharCount(word1, charCount);

    decrementCharCount(word2, charCount);

    for (int i = 0; i < 26; i++)
    {
        if (charCount[i])
            return false;
    }

    return true;
}

std::vector<std::string> Anagram::SelectAnagrams(
    const std::string &word,
    const std::vector<std::string> &candidates)
{
    std::vector<std::string> filteredCandidates;

    for (std::string s : candidates)
    {
        if (WordPairIsAnagram(word, s))
        {
            filteredCandidates.push_back(s);
        }
    }
    return filteredCandidates;
}