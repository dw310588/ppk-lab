#pragma once

#include <vector>

enum Color {
    BLACK,
    RED
};

struct Node {
  int val;
  Node *parent;
  Node *left;
  Node *right;
  Color color;
};

void tree_init();

void tree_left_rotate(Node *x);

void tree_right_rotate(Node *x);

void tree_init_null_node(Node *node, Node *parent);

void tree_insert_fix(Node *k);

Node* tree_search_helper(Node *node, int key);

void tree_delete_fix(Node *x);

void tree_transplant(Node *u, Node *v);

Node* tree_minimum(Node *node);

void tree_delete_node_helper(Node *node, int key);

Node* tree_search(int k);

Node* tree_successor(Node *x);

Node* tree_maximum(Node *node);

Node* tree_predecessor(Node *x);

void tree_insert(int key);

Node* tree_get_root();

void tree_delete_node(int data);

void tree_print();

std::vector<int> tree_get_nodes();
