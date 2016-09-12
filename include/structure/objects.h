#ifndef OBJECT_STACK_H

#define OBJECT_STACK_H

/*
 * Each object should be represents by this Node. To store objects Drawable was
 * created a stack, declared bellow, that will keep objects to use in any time.
 */
typedef struct node {
  struct object_node *next;
  char *name;
  int scope_id;
  void *structure;
} ObjectNode;

/*
 * When compiler is active, only one stack must be alive!
 */
typedef struct stack {
  ObjectNode *head;
} ObjectStack;

ObjectStack *object_stack;

/*
 * Insert a new object into stack
 */
int push(char* name, int scope_id, void* structure);

/*
 * Create node! Used by push function
 */
ObjectNode* create_object_node(char* name, int scope_id, void* structure);

/*
 * Remove last element from stack
 */
ObjectNode* pop(void);

/*
 * Remove all elements in stack that have id like scope_id
 */
int remove_all_from_scope(int scope_id);

/*
 * Prints object stack from node
 */
int print_object_stack(ObjectNode* node);

/*
 * Search objects by name into stack
 */
ObjectNode* search_element(char* name);

/*
 * @deprecated
 */
ObjectNode* search_element_with_same_name(ObjectNode*, char*);

#endif
