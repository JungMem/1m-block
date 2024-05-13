#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SITE_MAX_LEN 255

void* parse(unsigned char* file){

	char line[SITE_MAX_LEN] = {0, };
	Dictionary* dict = dict_new();
	struct Trie* head = 0;
	
	FILE* fd = fopen(file, "r");
	if(fd == NULL){
		printf("fopen error\n");
		exit(-1);
	}
	
	int num = 1;
	
	while(fgets(line, sizeof(line), fd) != NULL){
		
		char* host = strstr(line, ",") + 1;
		char* dot = strstr(line, ".");
		
		*dot = NULL;
		dot += 1;
		*(dot + strlen(dot)-1) = NULL;
		
		if(dict_has(dict, dot) == NULL){
			head = getNewTrieNode();
			
			dict_add(dict, dot, head);
			trie_insert(head, host);
		}
		else{
			head = dict_get(dict, dot);
			trie_insert(head, host);
			
		}
		
		num++;
	
	
	}
	
	printf("\nend\n");
	
	dict_show(dict);
	
	return dict;
}
