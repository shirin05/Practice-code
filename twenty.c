#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node* create_game_tree() {
    struct node* root = NULL;
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "a carrot");
    insert(root, 35, "", "a parsnip");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "a radish");
    insert(root, 85, "", "a potato");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "an apple");
    insert(root, 135, "", "a peach");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "a tomato");
    insert(root, 185, "", "a pea");
    return root;
}

int main() {
    struct node* game_tree = create_game_tree();
    char c;
    
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    while (1) {
        scanf(" %c", &c);
        if (c == 'q') break;
        
        printf("You think of a fruit or vegetable and I will try to guess it!\n");
        play_game(game_tree);
        
        printf("Press 'q' to quit or any other key to continue:\n");
    }

    free_tree(game_tree);  
    printf("Bye Bye!\n");
    return 0;
}
