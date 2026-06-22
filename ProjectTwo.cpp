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

//===================================================================================================
// InOrder (Search Method)
//===================================================================================================

void BinarySearchTree::InOrder() {
    inOrder(root);
}




//=============================================================
//inOrder
//=============================================================

void BinarySearchTree::inOrder(Node* node) {

    if (node == nullptr) {
        return;
    }

    inOrder(node->left);

    cout << node->course.courseNumber
    << ", "
    << node->course.courseTitle
    << endl;

}


//==================================================================
// Load Courses Function
//==================================================================

void loadCourses(string fileName, BinarySearchTree* bst) {


    /* OPENS CSV FILE */
    ifstream file(fileName);

    /* HANDLES WHEN FILE IS BAD - PREVENTS CRASHING */
    if (!file.is_open()){
        cout << "Error opening file." << endl;
        return;
    }

    string line;

    while (getline(file, line)) {



    }

    file.close();

    cout << "Courses loaded successfully." << endl;
}

























//======================================================================
// Function prototype
//======================================================================

void loadCourses(string fileName, BinarySearchTree* bst);





//=================================================================================================
// Main
//=================================================================================================

int main() {

    cout << "Project Two Starting..." << endl;

    return 0;
}