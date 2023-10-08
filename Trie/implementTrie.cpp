#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* letters[26];
    bool isTerminal;

    TrieNode(char c)
    {
        data = c;
        for(int i=0; i<26; i++)
        letters[i] = NULL;

        isTerminal = false;
    }
};

class Trie{
    private:
     //code addWordUtil function
    void addWordUtil(string word, TrieNode* &root,int curr)
    {
        if(curr == word.length()-1)  // if reached last char of word then exit
        { 
            root->isTerminal = true;
            return ;
        }
        else{
            TrieNode* child;
            int getIndex = word[curr] - 'A';    //getIndex has the index of the mapping of current char
            if(root->letters[getIndex] != NULL)                // root currently has the char as child
            {
                child = root->letters[getIndex];
                
            }
            else{
                  child = new TrieNode(word[curr]);
                  root->letters[getIndex] = child;
            }
            addWordUtil(word,child,++curr);

        }
    }

    //function of searchutil
    bool searchWordUtil(string &word,TrieNode* root,int curr)
    {
        if(curr == word.length()-1)
        return  root->isTerminal;

        else{
            int getIndex = word[curr] - 'A';
            TrieNode* child;
            if(root->letters[getIndex] == NULL)
            return false;

            else{
                    child = root->letters[getIndex];
                    return searchWordUtil(word,child,++curr);
            }
        }
    }
    void removeWordUtil(string word, TrieNode* root, int curr)
    {
        if(curr == word.length() -1)
        {    root->isTerminal = false;
            return;
        }
        TrieNode* child;
        int getIndex = word[curr] - 'A';
        child = root->letters[getIndex];
        removeWordUtil(word,child,++curr);
        return;
    }
    public:
    TrieNode* root = NULL;
    Trie()
    {
        root = new TrieNode('\0');
    }
    // function that will add a word in trie
    void addWord(string word)
    {
        
        // a util function that will actually do all the work 
        addWordUtil(word, root,0);
    }
    //function that will check if word is present in trie or not
    bool searchWord(string word)
    {
        return searchWordUtil(word,root,0);
    }

    //function that will remove a word
    void removeWord(string &word)
    {
        if(searchWord(word))
        removeWordUtil(word,root,0);

        else
        cout<<"errorrrrrrrr ";
        
        return;
    }
};


int main()
{
    string word = "DHRUV";
    Trie t;
    t.addWord(word);
    cout<<"The word "<<word<<" is ";
    if(t.searchWord(word))
    cout<<"present";
    else
    cout<<"not present";
    t.removeWord(word);
    cout<<" \n after deletion \n";
    cout<<"The word "<<word<<" is ";
    if(t.searchWord(word))
    cout<<"present";
    else
    cout<<"not present";

    return 0;
}