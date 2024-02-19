#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

enum Color {
    BLACK,
    RED
};

struct Node {
  double val;
  Node *parent;
  Node *left;
  Node *right;
  Color color;
};

Node *root;
Node *dummy_node;

void tree_init() {
    dummy_node= new Node;
    dummy_node->color = BLACK;
    dummy_node->left = nullptr;
    dummy_node->right = nullptr;
    root = dummy_node;
}

void tree_left_rotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != dummy_node) {
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
    if (y->right != dummy_node) {
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

void tree_organize_after_insert(Node *k) {
    Node *u;
    while (k->parent != nullptr && k->parent->color == RED) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u != nullptr && u->color == RED) {
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

        if (u != nullptr && u->color == RED) {
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

void tree_organize_after_delete(Node *x) {
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

void tree_move_node(Node *u, Node *v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    if(v != dummy_node) {
        v->parent = u->parent;
    }
}

Node* tree_minimum(Node *node) {
    while (node->left != dummy_node) {
      node = node->left;
    }
    return node;
}

void tree_delete_node(double key) {
    Node *node = root;
    Node *z = dummy_node;
    Node *x, *y;
    while (node != dummy_node) {
      if (node->val == key) {
        z = node;
      }

      if (node->val <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == dummy_node) {
      cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == dummy_node) {
      x = z->right;
      tree_move_node(z, z->right);
    } else if (z->right == dummy_node) {
      x = z->left;
      tree_move_node(z, z->left);
    } else {
      y = tree_minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        tree_move_node(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      tree_move_node(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    if (y_original_color == BLACK) {
      tree_organize_after_delete(x);
    }
    delete z;
}

Node* tree_successor(Node *x) {
    if (x->right != dummy_node) {
      return tree_minimum(x->right);
    }

    Node *y = x->parent;
    while (y != dummy_node && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
}

void tree_insert(double key) {
    Node *node = new Node;
    node->parent = nullptr;
    node->val = key;
    node->left = dummy_node;
    node->right = dummy_node;
    node->color = RED;

    Node *y = nullptr;
    Node *x = root;

    while (x != nullptr && x != dummy_node) {
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

    tree_organize_after_insert(node);
}

std::vector<std::vector<std::pair<double,Color>>> tree_get_levels() {
    std::vector<std::vector<std::pair<double,Color>>> res;
    std::vector<Node*> stack = {root};
    while(!stack.empty()) {
        int size = stack.size();
        int i;
        std::vector<std::pair<double,Color>> level;
        for(i = 0; i < size; i++) {
            std::pair<double,Color> element;
            element.first = stack[i]->val;
            element.second = stack[i]->color;
            level.push_back(element);
            if(stack[i]->left) {
                stack.push_back(stack[i]->left);
            }
            if(stack[i]->right) {
                stack.push_back(stack[i]->right);
            }
        }
        for(int j = 0; j < i; j++) {
            stack.erase(stack.begin());
        }
        res.push_back(level);
    }
    return res;
}

void tree_get_nodes_helper(std::vector<double>& output, Node *n) {
    if(!n) return;
    tree_get_nodes_helper(output,n->left);
    output.push_back(n->val);
    tree_get_nodes_helper(output,n->right);
}

std::vector<double> tree_get_nodes() {
    std::vector<double> vec;
    tree_get_nodes_helper(vec,root);
    return vec;
}
