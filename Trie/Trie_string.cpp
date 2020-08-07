#include <bits/stdc++.h>

using namespace std;

struct Trie {
    const char key = 'a';
    struct Node {
        Node *next[26];
        int isleaf;
        Node() {
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
            isleaf = false;
        }
        ~Node() {
            for (int i = 0; i < 26; ++i)
                if (next[i]) delete next[i];
        }
        bool isbottom() {
            for (int i = 0; i < 26; ++i)
                if (next[i]) return false;
            return true;
        }
    } *root;

    // ========== init | destroy ========== //

    Trie() { root = new Node(); }
    ~Trie() { delete root; }

    // ========== insert | find | ... ========== //

    void insert(string &s) {
        Node *p = root;
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i]-key;
            if (!p->next[c]) p->next[c] = new Node();
            p = p->next[c];
        }
        p->isleaf = true;
    }
    bool empty() {
        return root->isbottom();
    }
    bool find(string &s) {
        Node *p = root;
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i]-key;
            if (!p->next[c]) return false;
            p = p->next[c];
        }
        return p->isleaf;
    }

    // ========== remove ========== //

    void erase(Node*&p, string &s, int deg) {
        if (!p) return;
        if (deg==s.size()) {
            if (!p->isleaf) return;
            p->isleaf = false;
            if (p->isbottom()) {
                delete p;
                p = nullptr;
            }
            return;
        }
        int c = s[deg]-key;
        erase(p->next[c], s, deg+1);
        if (p->isbottom()&&!p->isleaf&&deg) {
            delete p;
            p = nullptr;
        }
    }
    void erase(string &s) {
        erase(root, s, 0);
    }
    void clear() {
        delete root;
        root = new Node();
    }
};
