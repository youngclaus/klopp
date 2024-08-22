#include <iostream>

using namespace std;

class TreeNode {
public:
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode() {
    data = 0;
    left = NULL;
    right = NULL;
  }
};

class BST {
public:
  TreeNode* root;

  BST() {
    root = NULL;
  }

  //1. Add Nodes to the BST
  void addNode(int value) {
    TreeNode* temp = new TreeNode;
    temp->data = value;                   //temp node has asset data that is now equal to the input value

    if (root == NULL) {                   //Checking if tree is empty
      root = temp;                        //Essentially makes value the root value
    }
    else {
      TreeNode* slow, * fast;
      slow = fast = root;                 //Starts at top of tree, check branches until fast falls off tree and fallback to slow in case

      while (fast != NULL) {
        if (fast->data == value) {
          cout << "i ain't doin that twice\n";
          return;
        }
        if (fast->data > value) {
          slow = fast;
          fast = fast->left;
        }
        else {
          slow = fast;
          fast = fast->right;
        }
      }

      if (value < slow->data) {
        slow->left = temp;
      }
      else {
        slow->right = temp;
      }
    }
    if (value == 69) {
      cout << "nice.\n";
    }
    else {
      cout << "welcome to the thunderdome " << value << endl;
    }
  }

  //2. Search for value
  void search(int key, TreeNode* start) {
    if (start == NULL) {
      cout << "couldn't find it\n";
      return;
    }
    else {
      if (key == start->data) {
        cout << "got it fam\n";
        return;
      }
      else if (key < start->data) {
        search(key, start->left);
      }
      else {
        search(key, start->right);
      }
    }
  }

  //3. Delete a value
  void remove(int key, TreeNode* start) {
    if (start == NULL) {
      cout << "ain't nuttin there chief\n";
      return;
    }
    else {
      TreeNode* slow, * fast;
      slow = fast = root;

      while (fast != NULL && fast->data != key) {   //find value check if deletable
        if (key < fast->data) {
          slow = fast;
          fast = fast->left;
        }
        else {
          slow = fast;
          fast = fast->right;
        }
      }

      if (fast == NULL) {
        cout << "i promise it isn't here\n";
        return;
      }

      // to get to this point means the value exists somewhere
      if (fast->left == NULL && fast->right == NULL) {            //Case 1 Delete
        if (slow->left == fast) {
          slow->left = NULL;
          cout << "Kicking " << fast->data << " for toxicity.\n";
          delete fast;
        }
        else {
          slow->right = NULL;
          cout << "Kicking " << fast->data << " for leaving/afk.\n";
          delete fast;
        }
      }
      else if (fast->left != NULL && fast->right == NULL) {       //Case 2 delete
        if (slow->left == fast) {
          slow->left = fast->left;
          cout << "Kicking " << fast->data << " for cheating.\n";
          delete fast;
        }
        else {
          slow->right = fast->left;
          cout << "Kicking " << fast->data << " for toxicity.\n";
          delete fast;
        }
      }
      else if (fast->left == NULL && fast->right != NULL) {
        if (slow->right == fast) {
          slow->right = fast->right;
          cout << "Kicking " << fast->data << " for cheating.\n";
          delete fast;
        }
        else {
          slow->right = fast->left;
          cout << "Kicking " << fast->data << " for leaving/afk.\n";
          delete fast;
        }
      }
      else {                                                    //Case 3 Delete
        cout << "Case 3 delete\n";

        int minVal = minValueRightSubtree(fast->right);         //swap current node with minVal

        fast->data = minVal;                                    //delete minVal from the right subtree
        remove(minVal, fast->right);
      }
    }   //essentially finding the number closest to input by going to right side of tree and following left path to the smallest number, setting input node equal to new minValue,
  }     //deleting original minValue node (easy because it is already and end node with no branches)

  int minValueRightSubtree(TreeNode* start) {
    if (start == NULL) {
      return -1;
    }
    else {
      TreeNode* temp = start;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      return temp->data;
    }
  }

  //4. Functions to traverse the tree
  //4.1. Preorder
  void preorder(TreeNode* start) {
    if (start == NULL) {       //base case
      return;
    }
    else {        //recursive step
      cout << start->data << endl;      //root
      preorder(start->left);            //left
      preorder(start->right);           //right
    }
  }

  void postorder(TreeNode* start) {
    if (start == NULL) {
      return;
    }
    else {
      postorder(start->left);
      postorder(start->right);
      cout << start->data << endl;
    }
  }

  void inorder(TreeNode* start) {
    if (start == NULL) {
      return;
    }
    else {
      inorder(start->left);
      cout << start->data << endl;
      inorder(start->right);
    }
  }
};

int main() {
  BST myTree;
  int choice, value;
  myTree.addNode(30);
  myTree.addNode(15);
  myTree.addNode(60);
  myTree.addNode(7);
  myTree.addNode(22);
  myTree.addNode(45);
  myTree.addNode(75);
  myTree.addNode(17);
  myTree.addNode(27);

  while (1) {
    cout << "[0] to exit\n[1] to add value\n[2] for pre-order\n[3] for postorder\n[4] for inorder\n[5] for search\n[6] for delete\n";
    cin >> choice;
    cout << "\n";
    switch (choice) {
    case 0:
      exit(1);
    case 1:
      cout << "What value to add?\n";
      cin >> value;
      myTree.addNode(value);
      break;

    case 2:
      cout << "=================\n";
      myTree.preorder(myTree.root);
      cout << "=================\n";
      break;

    case 3:
      cout << "=================\n";
      myTree.postorder(myTree.root);
      cout << "=================\n";
      break;

    case 4:
      cout << "=================\n";
      myTree.inorder(myTree.root);
      cout << "=================\n";
      break;

    case 5:
      cout << "Whachu want?\n";
      cin >> value;
      myTree.search(value, myTree.root);
      cout << "=================\n";
      break;

    case 6:
      cout << "What we kickin boss?\n";
      cin >> value;
      myTree.remove(value, myTree.root);
      break;

    default:
      cout << "Pick an option funny guy.\n";
    }
  }
}