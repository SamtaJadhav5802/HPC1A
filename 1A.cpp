#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    node *left, *right;
    int data;
};

class Breadthfs {
public:
    node* insert(node*, int);
    void bfs(node*);
};

node* Breadthfs::insert(node* root, int data) {
    if (!root) {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new node;
            temp->left->left = NULL;
            temp->left->right = NULL;
            temp->left->data = data;
            return root;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new node;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp->right->data = data;
            return root;
        } else {
            q.push(temp->right);
        }
    }

    return root;
}

void Breadthfs::bfs(node* head) {
    if (!head)
        return;

    queue<node*> q;
    q.push(head);

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            node* currNode = q.front();
            q.pop();
            cout << "\t" << currNode->data;

            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
    }
}

int main() {
    node* root = NULL;
    int data;
    char ans;

    do {
        cout << "\nEnter data => ";
        cin >> data;

        Breadthfs b;
        root = b.insert(root, data);

        cout << "Do you want to insert one more node? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    Breadthfs b;
    b.bfs(root);

    return 0;
}

/*
OUTPUT
gescoe@gescoe-OptiPlex-3010:~$ g++ -o gfg -fopenmp 1A.cpp
gescoe@gescoe-OptiPlex-3010:~$ ./gfg

Enter data => 0
Do you want to insert one more node? (y/n): y

Enter data => 1
Do you want to insert one more node? (y/n): y

Enter data => 2
Do you want to insert one more node? (y/n): y

Enter data => 3
Do you want to insert one more node? (y/n): y

Enter data => 4
Do you want to insert one more node? (y/n): y

Enter data => 5
Do you want to insert one more node? (y/n): y

Enter data => 6
Do you want to insert one more node? (y/n): n
	0	1	2	3	4	5	6

*/
