//Word Search II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* next[26];
        string word;   
        TrieNode() {
            memset(next, 0, sizeof(next));
            word = "";
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* cur = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!cur->next[idx]) cur->next[idx] = new TrieNode();
                cur = cur->next[idx];
            }
            cur->word = w; 
        }
        return root;
    }

    vector<string> ans;
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || !node->next[c - 'a']) return; 

        node = node->next[c - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = ""; 
        }

        board[i][j] = '#'; 

        // explore neighbours
        if (i > 0) dfs(board, i - 1, j, node);
        if (j > 0) dfs(board, i, j - 1, node);
        if (i < m - 1) dfs(board, i + 1, j, node);
        if (j < n - 1) dfs(board, i, j + 1, node);

        board[i][j] = c; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};
int main() {
    Solution obj;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> result = obj.findWords(board, words);
    for (const auto& res : result) {
        cout << res << endl; 
    }
    return 0;
}
