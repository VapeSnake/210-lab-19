// COMSC-210 | Lab 19 | Noel Mier-Luna
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Keep Review struct from lab 18
struct Review { // Node for linked list with review data.
    float rating;
    string comment;
    Review * next; // Pointer to the next review in the linked list.
};

// Movie class to hold movie name and linked list of reviews.
class Movie {
    string title;
    Review * head; // Pointer to the head of the linked list of reviews.
    public:
    void setTitle(string t) {
        title = t;
    };
    string getTitle() {
        return title;
    };
    
}

// BREAK OVER

int main() {

    return 0;
}