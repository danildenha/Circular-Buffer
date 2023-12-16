// Project Circular Buffer
//This project uses technique of circular buffer and manages data

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
    cout << "\nInitial state\n" << endl;
    CircularBuffer<int, 5> IntBuffer;
    cout << IntBuffer;

    //pushing values from 0 to 70
    for (unsigned int i = 0; i <= 70; i += 10)
    {
        cout << "\nPushing " << i << endl;
        IntBuffer.push_back(i);
        cout << IntBuffer;
    }

    for (unsigned int i = 0; i < 5; i++)
    {
        cout << "\nPopping " << IntBuffer.head() << endl;
        IntBuffer.pop();
        cout << IntBuffer;
    }
    cout << endl;

    cout << "\n*************** <string> Circular Buffer Demo ******************\n";

    // creates a vector of words
    // uses back_insert_iterator to fill the buffer
    vector<string> words = {"easy", "project", "the", "wonderful", "world", "of", "oz"};
    CircularBuffer<string, 5> StrBuffer;
    cout << "\nInitial state" << endl;
    cout << StrBuffer;

    //inserts words from vector into buffer using back_insert_iterator
    back_insert_iterator<CircularBuffer<string, 5>> inserter(StrBuffer);
    for_each(words.begin(), words.end(), [&inserter](string word) { *inserter = word; });
    cout << "\nAfter using back_insert_iterator" << endl;
    cout << StrBuffer;

    for (unsigned int i = 0; i < 5; i++)
    {
        cout << "\nPopping " << StrBuffer.head() << endl;
        StrBuffer.pop();
        cout << StrBuffer;
    }
    cout << endl;

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n\n";

    CircularBuffer<dog, 5> DogBuffer;
    //dog(string name = "", string breed = "", int age = 0)
    dog dogs[5] = {
        {"Guiness", "Wheaten", 9}, {"Grimlock", "Lab", 2}, {"Optimus", "Bulldog", 5},
        {"Murphy", "Lab", 14}, {"Floyd", "Beagle", 12} };

    for(auto& i : dogs)
    {
        DogBuffer.push_back(i);
    }

    cout << DogBuffer << endl;
    cout << endl;
    cout << "dogs Full?: " << (DogBuffer.full() ? "true" : "false") << endl;
    cout << endl;

    DogBuffer.push_back({"Snoopy", "Beagle", 100});
    cout << DogBuffer << endl;

    DogBuffer.push_back({ "Archie", "Brittany", 1 });
    cout << DogBuffer << endl;

    DogBuffer.push_back({ "Penny", "Beagle", 2 });
    cout << DogBuffer << endl;

    for (unsigned int i = 0; i < 5; i++)
    {
        cout << "Popping:";
        cout << DogBuffer.head() << endl;
        cout << endl;
        DogBuffer.pop();
        cout << DogBuffer << endl;
    }
    
    cout << endl;
}