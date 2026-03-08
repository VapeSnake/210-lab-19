// COMSC-210 | Lab 19 | Noel Mier-Luna
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

// Keep Review struct from lab 18

// NOTE: What if we add our struct to our movie class? It may simplify our linked lists of reviews per movie.
// Movie class to hold movie name and linked list of reviews.
class Movie
{
    struct Review
    { // Node for linked list with review data.
        float rating;
        string comment;
        Review *next; // Pointer to the next review in the linked list.
    };
    string title; // Movie title
    Review *head; // Pointer to the head of the linked list of reviews

public:
    void setTitle(string t)
    {
        title = t;
    };
    string getTitle() const
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
};

    const int NUM_MOVIES = 4; // Constant for the number of movies to be entered (TESTING)

int main()
{
    for (int i = 0; i < NUM_MOVIES; i++) // Loop to enter movie data (TESTING)
    {
        Movie tempMovie; // Create a temporary Movie object to hold the movie data
        tempMovie.
    }

    vector<Movie> movies; // Vector to hold movies
    return 0;
}
