// https://www.techiedelight.com/ko/trie-implementation-insert-search-delete/

#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
 
 
struct Trie* getNewTrieNode()
{
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf = 0;
 
    for (int i = 0; i < CHAR_SIZE; i++) {
        node->character[i] = NULL;
    }
    
    for (int i = 0; i < NUM_SIZE; i++) {
        node->num[i] = NULL;
    }
    
    for (int i = 0; i < SP1; i++) {
        node->sp1[i] = NULL;
    }
    
    for (int i = 0; i < SP2; i++) {
        node->sp2[i] = NULL;
    }
    
    for (int i = 0; i < SP3; i++) {
        node->sp3[i] = NULL;
    }
    
    for (int i = 0; i < SP4; i++) {
        node->sp4[i] = NULL;
    }
 
    return node;
}
 

void trie_insert(struct Trie *head, char* str)
{

    struct Trie* curr = head;
    while (*str)
    {
    
    	if(*str >= 'a' && *str <= 'z'){
        	
        	if (curr->character[*str - 'a'] == NULL) {
            	curr->character[*str - 'a'] = getNewTrieNode();
        	}
        
        	curr = curr->character[*str - 'a'];
        }
        else if(*str >= '0' && *str <= '9'){
        
        	if (curr->num[*str - '0'] == NULL) {
            	curr->num[*str - '0'] = getNewTrieNode();
        	}
        
        	curr = curr->num[*str - '0'];
        }
        else if(*str >= '!' && *str <= '/'){
        
        	if (curr->sp1[*str - '!'] == NULL) {
            	curr->sp1[*str - '!'] = getNewTrieNode();
        	}
        
        	curr = curr->sp1[*str - '!'];
        }
        else if(*str >= ':' && *str <= '@'){
        
        	if (curr->sp2[*str - ':'] == NULL) {
            	curr->sp2[*str - ':'] = getNewTrieNode();
        	}
        
        	curr = curr->sp2[*str - ':'];
        }
        else if(*str >= '[' && *str <= 0x60){
        
        	if (curr->sp3[*str - '['] == NULL) {
            	curr->sp3[*str - '['] = getNewTrieNode();
        	}
        
        	curr = curr->sp3[*str - '['];
        }
        else if(*str >= '{' && *str <= '~'){
        
        	if (curr->sp4[*str - '{'] == NULL) {
            	curr->sp4[*str - '{'] = getNewTrieNode();
        	}
        
        	curr = curr->sp4[*str - '{'];
        }
        else{
        	printf("%s\n", str);
        	printf("trie_insert error\n");
        	exit(-1);
        }
 
        str++;
    }
 
    curr->isLeaf = 1;
}


int trie_find(struct Trie* head, char* str)
{
    if (head == NULL) {
        return 0;
    }
 
    struct Trie* curr = head;
    while (*str)
    {
 
 	if(*str >= 'a' && *str <= 'z'){
        	curr = curr->character[*str - 'a'];
        }
        else if(*str >= '0' && *str <= '9'){
        	curr = curr->num[*str - '0'];
        }
        else if(*str >= '!' && *str <= '/'){
        	curr = curr->sp1[*str - '!'];
        }
        else if(*str >= ':' && *str <= '@'){
        	curr = curr->sp2[*str - ':'];
        }
        else if(*str >= '[' && *str <= 0x60){
        	curr = curr->sp3[*str - '['];
        }
        else if(*str >= '{' && *str <= '~'){
        	curr = curr->sp4[*str - '{'];
        }
        
        if (curr == NULL) {
            return 0;
        }
        
        str++;
    }
 
    return curr->isLeaf;
}
