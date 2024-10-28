//============================================================================
// Name        : ProjectTwo.cpp 
// Author      : Eleen Limon
// Description : C++ program to load, store, and display course information with a menu interface.
//============================================================================

#include <iostream>  // For input/output
#include <fstream>   // For file handling
#include <sstream>   // For parsing data from file
#include <vector>    // To store prerequisites as a list
#include <map>       // To store courses using a key-value pair (course number, course object)
#include <algorithm> // For sorting functions

using namespace std;

// Structure to hold course information
struct Course {
    string courseNumber;          // Unique identifier for the course
    string courseName;            // Course title
    vector<string> prerequisites; // List of prerequisite courses
};

// Function declarations
void loadCourses(const string& filename, map<string, Course>& courses);
void printCourseList(const map<string, Course>& courses);
void printCourseInfo(const map<string, Course>& courses, const string& courseNumber);

int main() {
    map<string, Course> courses;  // Data structure to hold all the courses
    string filename, courseNumber;
    int choice = 0;  // Variable to store user's menu selection

    // Main menu loop
    while (choice != 9) {
        // Display menu options
        cout << "Welcome to the course planner." << endl;
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course Information" << endl;
        cout << "9. Exit" << endl;
        cout << "What would yout like to do? ";
        cin >> choice;  // Get user input

        // Process user's choice
        switch (choice) {
            case 1:
                // Option 1: Load the course data from the file
                cout << "Enter the filename: ";
                cin >> filename;  // Get file name from the user
                loadCourses(filename, courses);  // Load the file data into the course map
                break;
            case 2:
                // Option 2: Print the full course list in alphanumeric order
                printCourseList(courses);
                break;
            case 3:
                // Option 3: Print specific course information by course number
                cout << "Enter the course number: ";
                cin >> courseNumber;  // Get the course number from the user
                printCourseInfo(courses, courseNumber);  // Print details of the selected course
                break;
            case 9:
                // Option 9: Exit the program
                cout << "Thank you for using the course planner!" << endl;
                break;
            default:
                // Invalid option
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;  // Exit the program
}

// Function to load course data from a file and store it in the data structure
void loadCourses(const string& filename, map<string, Course>& courses) {
    ifstream file(filename);  // Open the file for reading
    string line;  // To hold each line of the file

    if (!file.is_open()) {
        // Error message if the file cannot be opened
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Read the file line by line
    while (getline(file, line)) {
        stringstream ss(line);  // Use stringstream to parse the line
        string courseNumber, courseName, prerequisite;
        vector<string> prerequisites;  // To store the prerequisites

        // Parse the course number and name (comma-separated values)
        getline(ss, courseNumber, ',');
        getline(ss, courseName, ',');

        // Parse the prerequisites, if any (also comma-separated)
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }

        // Create a Course object and store it in the map
        Course course = {courseNumber, courseName, prerequisites};
        courses[courseNumber] = course;
    }
    file.close();  // Close the file after reading
    cout << "Data loaded successfully!" << endl;
}

// Function to print an alphanumeric list of all courses
void printCourseList(const map<string, Course>& courses) {
    if (courses.empty()) {
        cout << "No courses available. Please load the data first." << endl;
        return;
    }

    // Since the map stores keys in sorted order by default, iterating through the map will print the courses in alphanumeric order
    cout << "Here is a sample schedule:\n" << endl;
    for (const auto& pair : courses) {
        cout << pair.first << ": " << pair.second.courseName << endl;  // Print course number and name
    }
    cout << endl;
}

// Function to print detailed course information
void printCourseInfo(const map<string, Course>& courses, const string& courseNumber) {
    if (courses.empty()) {
        cout << "No courses available. Please load the data first." << endl;
        return;
    }

    // Find the course in the map using the course number
    auto it = courses.find(courseNumber);

    if (it != courses.end()) {
        // If the course is found, print its details
        cout << it->second.courseNumber << ": " << it->second.courseName << endl;

        // Check if there are any prerequisites
        if (!it->second.prerequisites.empty()) {
            cout << "Prerequisites: ";
            // Print all prerequisites
            for (const auto& prereq : it->second.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        } else {
            // No prerequisites
            cout << "No prerequisites." << endl;
        }
    } else {
        // Error message if the course is not found
        cout << "Course not found." << endl;
    }
}
