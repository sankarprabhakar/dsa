/*
 * trie.h
 *
 *  Created on: Jan 9, 2017
 *      Author: sankarsa
 */

#ifndef TRIE_H_
#define TRIE_H_

#define MAX_CHARACTER 26
typedef struct TrieNode
{
	struct TrieNode *character[MAX_CHARACTER];
	int prefix_count;
	int leaf_node;
}TRIE_NODE;
int insertString(TRIE_NODE **head, char *input);
int searchOccurance(TRIE_NODE *head, char *input);
int searchString(TRIE_NODE *head, char *input);
#endif /* TRIE_H_ */
