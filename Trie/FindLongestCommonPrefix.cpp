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

string getCommonPrefix(vector<string>& input)
{
    Trie t;
    for (int i = 0; i < input.size(); i++)
    {
        t.addWord(input[i]);
    }
    string ans;
    
    TrieNode* temp = t.root;
    while (true)
    {
        int check = 0;
        int i;
        for (i = 0; i < 26; i++)
        {
            if (temp->letters[i] != NULL)
            {
                check++;
                if (check > 1)
                {
                    return ans; // If more than one child, return the common prefix found so far.
                }
                char c = i + 'A';
                ans.push_back(c);
                temp = temp->letters[i]; // Move to the next level.
            }
        }

        if (check == 0)
        {
            return ans; // If no children found at this level, return the common prefix found so far.
        }
    }

    return ans; // This should not be reached.
}



int main()
{
    vector<string> input = {"ANT", "ANNA", "ANKIT"};
    string ans = getCommonPrefix(input);
    cout<<ans;
    return 0;

}