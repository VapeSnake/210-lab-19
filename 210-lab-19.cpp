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
    Movie() {
        head = nullptr; // Initialize head to nullptr in the constructor.
    };
    void setTitle(string t)
    {
        title = t;
    };
    string getTitle() const
    {
        return title;
    };
    void addReview(float rating, string comment) // Function to add a review to the linked list of reviews for the movie.
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
    void displayReviews() const // Function to display all reviews for the movie.
    {
        cout << "Reviews for " << title << ":" << endl;
        Review *current = head; // Start at the head of the linked list of reviews.
        while (current)
        { // Loop through the linked list until we reach the end (nullptr).
            cout << fixed << setprecision(1) << current->rating << " - " << current->comment << endl; // Display the rating and comment for each review.
            current = current->next; // Move to the next review in the linked list.
        }
    };
};

const int NUM_MOVIES = 4; // Constant for the number of movies to be entered (TESTING)

int main()
{
    Movie movie1;
    Movie movie2;
    Movie movie3;
    Movie movie4;

    movie1.setTitle("The Shawshank Redemption");
    movie2.setTitle("The Godfather");
    movie3.setTitle("No Country for Old Men");
    movie4.setTitle("Blade Runner");

    vector<Movie> movies = {movie1, movie2, movie3, movie4}; // Vector to hold the movies.

    ifstream inFile("Movie_Comments.txt"); // Open the file for reading.
    if (!inFile)
    {
        cerr << "Error opening file!" << endl;
        return 0; // Exits the program if the file cannot be opened.
    }
    float rating;
    string comment;
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        while (inFile >> rating) // Reads rating from file.
        {
            inFile.ignore(); // Ignore the newline character after reading the rating.
            getline(inFile, comment); // Reads line of comment from file.
            movies[i].addReview(rating, comment); // Adds the review to the movie's linked list of reviews.
        }
    }

    for (const Movie &movie : movies)
    {
        movie.displayReviews(); // Displays the reviews for each movie.
        cout << endl; // Print a newline for better formatting between movies.
    }

    return 0;
}
