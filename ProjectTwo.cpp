#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//=========================================================
// Course Structure
//=========================================================

struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;

    Course() {

    }

    Course(string number, string title){
        courseNumber = number;
        courseTitle = title;
    }

};


//===========================================================
// Node Strucuture
//===========================================================

struct Node {
    Course course;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(Course aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }

};

//=============================================================
// Binary Search Tree Class
//=============================================================

class BinarySearchTree {
    private:

        Node* root;

        void addNode(Node* node, Course course);
        void inOrder(Node* node);

    public:

        BinarySearchTree();

        void Insert(Course course);

        void InOrder();

        Course Search(string courseNumber);

};

//================================================================
// Constructor
//================================================================

BinarySearchTree::BinarySearchTree() {
    root = nullptr;

}

//================================================================
// Insert
//================================================================

void BinarySearchTree::Insert(Course course) {

    if(root == nullptr) {
        root = new Node(course);
    }
    else {
        addNode(root, course);
    }
}

//===============================================================
// addNode
//===============================================================

void BinarySearchTree::addNode(Node* node, Course course) {

    if (course.courseNumber < node->course.courseNumber) {

        if (node->left == nullptr) {
            node->left = new Node(course);
        }
        else {
            addNode(node->left, course);
        }

    }
}


//============================================================
// Search
//============================================================

Course BinarySearchTree::Search(string courseNumber) {

    Node* current = root;

    while (current !=nullptr) {

        if (current->course.courseNumber == courseNumber) {
            current = current->left;
        }
        else {
            current = current->right;

        }
    }

    return Course();
}




















//=================================================================================================
// Main
//=================================================================================================

int main() {

    cout << "Project Two Starting..." << endl;

    return 0;
}