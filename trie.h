// https://www.techiedelight.com/ko/trie-implementation-insert-search-delete/

#define CHAR_SIZE 26
#define NUM_SIZE 10
#define SP1 15
#define SP2 7
#define SP3 6
#define SP4 4
 
struct Trie
{
    int isLeaf;           
    struct Trie* character[CHAR_SIZE];
    struct Tire* num[NUM_SIZE];
    struct Trie* sp1[SP1];
    struct Trie* sp2[SP2];
    struct Trie* sp3[SP3];
    struct Trie* sp4[SP4];
    
};
 
 
struct Trie* getNewTrieNode();
 

void trie_insert(struct Trie *head, char* str);


int trie_find(struct Trie* head, char* str);
