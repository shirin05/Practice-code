#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct node* create_node(int data, char* question, char* guess) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->question = strdup(question);
    new_node->guess = strdup(guess);
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node* root, int data, char* question, char* guess) {
    if (root == NULL)
        return create_node(data, question, guess);
    if (data < root->data)
        root->left = insert(root->left, data, question, guess);
    else if (data > root->data)
        root->right = insert(root->right, data, question, guess);
    return root;
}

void free_tree(struct node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->question);
    free(root->guess);
    free(root);
}

void play_game(struct node* root) {
    struct node* current = root;
    char answer[10];

    while (current != NULL) {
        if (strcmp(current->guess, "") != 0) {  
            printf("Is it %s?\n", current->guess);
            printf("y/n: ");
            scanf("%s", answer);
            if (answer[0] == 'y') {
                printf("I win!\n");
            } else {
                printf("You win! I couldn't guess.\n");
            }
            break;
        } else {  
            printf("%s\n", current->question);
            printf("y/n: ");
            scanf("%s", answer);
            if (answer[0] == 'y')
                current = current->left;
            else
                current = current->right;
        }
    }
}
