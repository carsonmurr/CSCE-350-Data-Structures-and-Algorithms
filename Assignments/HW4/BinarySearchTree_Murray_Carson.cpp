// Carson Murray 2022 CSCE350
#include <iostream>
#include <cstddef>

struct Node {
  int data;
  Node* rightChild;
  Node* leftChild;
};

Node* newNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  return newNode;
}

Node* Add(Node* root, int data) {
  if (root == NULL) {
    root = newNode(data); 
  } else if (data <= root->data) {
    root->leftChild = Add(root->leftChild, data);
  } else {
    root->rightChild = Add(root->rightChild, data);
  }
  return root;
}

Node* findMinInTree(Node* root) {
  if(root == NULL)
    return NULL;
  else if(root->leftChild == NULL)
    return root;
  else
    return findMinInTree(root->leftChild);
}

Node* deleteNode(Node* root, int data) {
  if (root == NULL) {
    return root;
  }
  if (data < root->data) {
    root->leftChild = deleteNode(root->leftChild,data);
  }
  else if(data > root->data) {
    root->rightChild = deleteNode(root->rightChild,data);
  }
  else {
    if(root->leftChild == NULL && root->rightChild == NULL) {
      return NULL;
    }
    else if(root->leftChild == NULL) {
      struct Node* temp = root->rightChild;
      free(root);
      return temp;
    }
    else if(root->rightChild == NULL) {
      struct Node* temp = root->leftChild;
      free(root);
      return temp;
    }
    struct Node* temp2 = findMinInTree(root->rightChild);
    root->data = temp2->data;

    root->rightChild = deleteNode(root->rightChild,temp2->data);

  }
  return root;
}

bool searchForNode(Node* root, int data, int temp) {
  if (temp == 0) {
    std::cout << "searching... Traversal Pattern:" << std::endl;
  }

  if (root == NULL) {
    std::cout << "Search Key: "<< data << " not found" << std::endl;
    return false;
  }
  else if (root->data == data) {
    std::cout << root->data << std::endl;
    std::cout << "Search Key: " << data << " was found" << std::endl;
    return true;
  }
  else if (data <= root->data  && root->leftChild != NULL) {
    std::cout << root->data << std::endl;
    return searchForNode(root->leftChild, data, 1);
  }
  else if (data >= root->data && root->rightChild != NULL) {
    std::cout << root->data << std::endl;
    return searchForNode(root->rightChild, data, 1);
  }
  else if (data <= root->data && root->leftChild == NULL) {
    std::cout << root->data << std::endl;
    std::cout << "Search key: " << data << " was not found" << std::endl;
    return false;
  }
  else if (data >= root->data && root->rightChild == NULL) {
    std::cout << root->data << std::endl;
    std::cout << "Search key: " << data << " was not found" << std::endl;
    return false;
  }
  else {
    return false;
  }
}

int main() {
  struct Node* root = NULL;
  bool running = true;

  std::cout << "Welcome to the Binary Search Tree!\ntype \"add\" to insert a node\ntype \"delete\" to delete a node\n"
                "type \"search\" to search for a node\nor type \"exit\" to exit the program." << std::endl;
  std::string input;
  int value = 0;
  while (running == true) {
    std::cin >> input;
    if (input == "add") {
      std::cout << "Enter an integer value that you would like to add to the tree:" << std::endl;
      std::cin >> value;
      root = Add(root, value);
      std::cout << value << " was added to the tree!\n\nEnter a new argument into the console (\"add\", \"delete\", \"search\", or \"exit\")" << std::endl;
    } 
    else if (input == "delete") {
      std::cout << "Enter an integer value thet you would like to delete from the tree:" << std::endl;
      std::cin >> value;
      deleteNode(root,value);
      std::cout <<"Node Deleted\n\nEnter a new argument into the console (\"add\", \"delete\", \"search\", or \"exit\") " << std::endl;
    } 
    else if (input == "search") {
      std::cout << "Enter an integer value that you would like to search for:" << std::endl;
      std::cin >> value;
      searchForNode(root,value,0);
      std::cout <<"\n\nEnter a new argument into the console (\"add\", \"delete\", \"search\", or \"exit\") " << std::endl;
    } 
    else if (input == "exit") {
      std::cout<< "Goodbye!" << std::endl;
      running = false;
    } else {
      std::cout << "Invalid argument try again" << std::endl;
      std::cout <<"Enter a new argument into the console (\"add\", \"delete\", \"search\", or \"exit\") " << std::endl;
    }
  }
} 