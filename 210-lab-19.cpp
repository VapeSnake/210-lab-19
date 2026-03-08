// COMSC-210 | Lab 19 | Noel Mier-Luna
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

// Keep Review struct from lab 18
struct Review
{ // Node for linked list with review data.
    float rating;
    string comment;
    Review *next; // Pointer to the next review in the linked list.
};

// Movie class to hold movie name and linked list of reviews.
class Movie
{
    string title;
    Review *head; // Pointer to the head of the linked list of reviews.
public:
    void setTitle(string t)
    {
        title = t;
    };
    string getTitle()
    {
        return title;
    };
    void addReview(Review *&head, float rating, string comment)
    {
        if (!head)
        { // if this is the first node, it's the new head
            head = new Review;
            head->next = nullptr;
            head->rating = rating;
            head->comment = comment;
        }
        else
        { // its a second or subsequent node; place at the head
            Review *newReview = new Review;
            newReview->next = head; // point new review to the current head
            newReview->rating = rating;
            newReview->comment = comment;
            head = newReview; // update head to point to the new review
        }
    };
    void readCommentFromFile(Review *&head, string filename)
    {
        ifstream inFile("Movie_Comments.txt");
        if(!inFile)
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }
        string line;
        getline(inFile, line); // Read the first review comment from the file
        
        if (line.empty())
        {
            cout << "No reviews found in the file." << endl;
            return;
        }
    }
    void displayReviewsAndAverage(Review *head)
    {
        if (!head)
        {
            cout << "No reviews to display." << endl;
            return;
        }
        Review *current = head;
        float totalRating = 0.0;
        int reviewCount = 0;

        cout << "Reviews for " << title << ":" << endl;
        while (current)
        {
            cout << fixed << setprecision(1) << current->rating << " - " << current->comment << endl;
            totalRating += current->rating;
            reviewCount++;
            current = current->next;
        }
        if (reviewCount > 0)
        {
            cout << "Average Rating: " << fixed << setprecision(1) << (totalRating / reviewCount) << endl;
        }
    };
};


int main()
{

    return 0;
}

