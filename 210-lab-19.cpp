// COMSC-210 | Lab 19 | Noel Mier-Luna
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
// Keep Review struct from lab 18
// Movie class to hold movie name and linked list of reviews.
class Movie {
    struct Review { // Node for linked list with review data.
        float rating;
        string comment;
        Review * next; // Pointer to the next review in the linked list.
    };
    string title; // Movie title
    Review * head; // Pointer to the head of the linked list of reviews

    public:
        Movie() {
            head = nullptr; // Initialize head to nullptr in the constructor.
            // This ensures that when a Movie object is created, it starts with an empty list of reviews.
        };
    ~Movie() { // Destructor to free memory allocated for reviews when a Movie object is destroyed.
        Review * current = head; // Start at the head of the linked list of reviews.
        while (current) { // Loop through the linked list and delete each review node to free memory.
            Review * temp = current; // Store the current review node in a temporary pointer.
            current = current -> next; // Move to the next review node in the linked list.
            delete temp; // Delete the current review node to free memory.
        }
    };
    void setTitle(string t) {
        title = t;
    };
    string getTitle() const {
        return title;
    };
    void addReview(float rating, string comment) // Function to add a review to the linked list of reviews for the movie.
    {
        if (!head) { // if this is the first node, it's the new head
            head = new Review;
            head -> next = nullptr;
            head -> rating = rating;
            head -> comment = comment;
        } else { // its a second or subsequent node; place at the head
            Review * newReview = new Review;
            newReview -> next = head; // point new review to the current head
            newReview -> rating = rating;
            newReview -> comment = comment;
            head = newReview; // update head to point to the new review
        }
    };
    void displayReviewsWithAverage() const // Function to display all reviews for the movie.
    {
        cout << "Reviews for " << title << ":" << endl;
        Review * current = head; // Start at the head of the linked list of reviews.
        float totalRating = 0; // Variable to keep track of the total rating, used for calculating the average rating.
        int reviewCount = 0; // Variable to keep track of the number of reviews processed, used for calculating the average rating.

        while (current) { // Loop through the linked list until we reach the end (nullptr).
            cout << fixed << setprecision(1) << current -> rating << " - " << current -> comment << endl;
            totalRating += current -> rating; // Add the current review's rating to the total rating.
            reviewCount++; // Increment the review count to keep track of how many reviews we have processed.
            current = current -> next; // Move to the next review node in the linked list.
        }
        if (reviewCount > 0) { // Check if there are any reviews to avoid division by zero when calculating the average rating.
            cout << "Average Rating: " << fixed << setprecision(1) << totalRating / reviewCount << endl;
        }
    };
};

const int NUM_MOVIES = 4; // Constant for the number of movies to be entered.
const int MAX_REVIEWS = 3; // Constant for the maximum number of reviews per movie.

int main() {
    cout << " -- START OF PROGRAM -- " << endl;
    Movie movie1;
    Movie movie2;
    Movie movie3;
    Movie movie4;
    // Create and set titles for Movie objects.
    movie1.setTitle("The Shawshank Redemption");
    movie2.setTitle("The Godfather");
    movie3.setTitle("No Country for Old Men");
    movie4.setTitle("Blade Runner");

    vector < Movie > movies = {
        movie1,
        movie2,
        movie3,
        movie4
    }; // Vector to hold the movies.

    ifstream inFile("Movie_Comments.txt"); // Open the file for reading.
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1; // Exit with an error code if the file cannot be opened.
    }
    for (int i = 0; i < NUM_MOVIES; i++) {
        for (int j = 0; j < MAX_REVIEWS; j++) // Loop to read 3 reviews per movie.
        {
            float rating;
            string comment;
            if (inFile >> rating) // Reads rating from file.
            {
                inFile.ignore(1000, '\n'); // Ignore the newline character after reading
                getline(inFile, comment); // the rating to ensure that getline reads the comment correctly.
                movies[i].addReview(rating, comment);
            } else {
                break; // stop if no more ratings available
            }
        }
    }
    for (const Movie & movie: movies) {
        movie.displayReviewsWithAverage(); // Displays the reviews and average rating for each movie.
        cout << endl; // Print a newline for better formatting between movies.
    }
    cout << " -- END OF PROGRAM -- " << endl;
    return 0;
}