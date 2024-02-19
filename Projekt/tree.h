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

void tree_organize_after_insert(Node *k);

void tree_organize_after_delete(Node *x);

void tree_move_node(Node *u, Node *v);

Node* tree_minimum(Node *node);

void tree_delete_node(double key);

Node* tree_maximum(Node *node);

Node* tree_predecessor(Node *x);

void tree_insert(double key);

std::vector<double> tree_get_nodes();

std::vector<std::vector<std::pair<double,Color>>> tree_get_levels();
