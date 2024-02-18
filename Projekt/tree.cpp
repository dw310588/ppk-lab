#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

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

Node *root;
Node *TNULL;

void tree_init() {
    TNULL = new Node;
    TNULL->color = BLACK;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
}

void tree_left_rotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void tree_right_rotate(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void tree_init_null_node(Node *node, Node *parent) {
    node->val= 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = BLACK;
}

void tree_insert_fix(Node *k) {
    Node *u;
    while (k->parent->color == RED) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == RED) {
          u->color = BLACK;
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            tree_right_rotate(k);
          }
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          tree_left_rotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == RED) {
          u->color = BLACK;
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            tree_left_rotate(k);
          }
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          tree_right_rotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = BLACK;
}

Node* tree_search_helper(Node *node, int key) {
    if (node == TNULL || key == node->val) {
      return node;
    }

    if (key < node->val) {
      return tree_search_helper(node->left, key);
    }
    return tree_search_helper(node->right, key);
}

void tree_delete_fix(Node *x) {
    Node *s;
    while (x != root && x->color == BLACK) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == RED) {
          s->color = BLACK;
          x->parent->color = RED;
          tree_left_rotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == BLACK && s->right->color == BLACK) {
          s->color = RED;
          x = x->parent;
        } else {
          if (s->right->color == BLACK) {
            s->left->color = BLACK;
            s->color = RED;
            tree_right_rotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->right->color = BLACK;
          tree_left_rotate(x->parent);
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == RED) {
          s->color = BLACK;
          x->parent->color = RED;
          tree_right_rotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == BLACK && s->right->color == BLACK) {
          s->color = RED;
          x = x->parent;
        } else {
          if (s->left->color == BLACK) {
            s->right->color = BLACK;
            s->color = RED;
            tree_left_rotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = BLACK;
          s->left->color = BLACK;
          tree_right_rotate(x->parent);
          x = root;
        }
      }
    }
    x->color = BLACK;
}

void tree_transplant(Node *u, Node *v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
}

Node* tree_minimum(Node *node) {
    while (node->left != TNULL) {
      node = node->left;
    }
    return node;
}

void tree_delete_node_helper(Node *node, int key) {
    Node *z = TNULL;
    Node *x, *y;
    while (node != TNULL) {
      if (node->val == key) {
        z = node;
      }

      if (node->val <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == TNULL) {
      cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      tree_transplant(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      tree_transplant(z, z->left);
    } else {
      y = tree_minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        tree_transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      tree_transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (y_original_color == BLACK) {
      tree_delete_fix(x);
    }
}

Node* tree_search(int k) {
    return tree_search_helper(root, k);
}

Node* tree_successor(Node *x) {
    if (x->right != TNULL) {
      return tree_minimum(x->right);
    }

    Node *y = x->parent;
    while (y != TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
}

Node* tree_maximum(Node *node) {
    while (node->right != TNULL) {
      node = node->right;
    }
    return node;
}

Node* tree_predecessor(Node *x) {
    if (x->left != TNULL) {
      return tree_maximum(x->left);
    }

    Node *y = x->parent;
    while (y != TNULL && x == y->left) {
      x = y;
      y = y->parent;
    }

    return y;
}

void tree_insert(int key) {
    Node *node = new Node;
    node->parent = nullptr;
    node->val = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = RED;

    Node *y = nullptr;
    Node *x = root;

    while (x != TNULL) {
      y = x;
      if (node->val < x->val) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->val < y->val) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = BLACK;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    tree_insert_fix(node);
}

Node* tree_get_root() {
    return root;
}

void tree_delete_node(int data) {
    tree_delete_node_helper(root, data);
}

void tree_print() {
  std::vector<Node*> stack = {root};
  while(!stack.empty()) {
      int size = stack.size();
      int i;
      for(i = 0; i < size; i++) {
          if(stack[i]->color == BLACK) {
              printf("[%d] ",stack[i]->val);
          } else if(stack[i]->color == RED) {
              printf("(%d) ",stack[i]->val);
          }
          if(stack[i]->left) {
              stack.push_back(stack[i]->left);
          }
          if(stack[i]->right) {
              stack.push_back(stack[i]->right);
          }
      }
      printf("\n");
      for(int j = 0; j < i; j++) {
          stack.erase(stack.begin());
      }
  }
}

void tree_get_nodes_helper(std::vector<int>& output, Node *n) {
    if(!n) return;
    tree_get_nodes_helper(output,n->left);
    output.push_back(n->val);
    tree_get_nodes_helper(output,n->right);
}

std::vector<int> tree_get_nodes() {
    std::vector<int> vec;
    tree_get_nodes_helper(vec,root);
    return vec;
}
