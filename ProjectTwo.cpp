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

};





//=================================================================================================
// Main
//=================================================================================================

int main() {

    cout << "Project Two Starting..." << endl;

    return 0;
}