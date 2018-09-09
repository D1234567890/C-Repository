#pragma once

struct String{
    static const unsigned char INITIAL_BUFFER_SIZE = 255;
private:

    // 1.
    // Three (3) private member variables are needed.
    // -a char pointer that will point to the first character in the string.
    // -an unsigned int to keep count of how many characters are in the string.
    // -an unsigned long to keep the size of the allotted space for the string in memory (known as the buffer).

    char *string;
    unsigned int length;
    unsigned long buffer; 

    // 2.
    // the getLengthOfCharString function is a private helper function that 
    // returns the number of chars (bytes) before v points to the
    // null termination character '\0';

    unsigned int getLengthOfCharString(const char* v) {
        int returnThis = 0;
        while (v[returnThis] != '\0') {
            returnThis++;
        }
        return returnThis;
    }

    unsigned long getBufferFromLength(unsigned int length) {
       if (length >= INITIAL_BUFFER_SIZE) {
           return length * 2;
       } else {
           return INITIAL_BUFFER_SIZE;
       }
    }

public:

    // 3.
    // the default constructor initializes the member variables
    // the buffer size should be initialized to the INITIAL_BUFFER_SIZE
    // the char pointer should point to a new char array that is the size of the buffer
    // the character count is 0

    String() {
        this -> buffer = INITIAL_BUFFER_SIZE;
        this -> string = new char[buffer];
        this -> length = 0;
    }

    // 4.
    // this constructor initializes this string object with the data 
    // referenced by the char pointer

    String(const char* v){
        

        // 4a: get the length of v

        // 4b: if that length is less than the initial buffer size,
        //     initialize the char pointer member variable to point at 
        //     a new char array that is the size of the initial buffer size.
        //     Also, initialize the buffer size variable.

        // 4c: otherwise, initialize the char pointer to poibnt at a new
        //     char array that is the size of v's length * 2.
        //     This is to give our string room to grow without having to 
        //     reallocate memory as often.

        // 4d: initialize the char count variable to equal the length of v.

        // 4e: copy that characters from v into the char array pointed to by the 
        // member variable (for loop)

        int length = getLengthOfCharString(v);

        if (length < INITIAL_BUFFER_SIZE) {
            this -> buffer = INITIAL_BUFFER_SIZE;
            this -> string = new char[buffer];
        } else {
            this -> buffer = finalLength * 2;
            this -> string = new char[buffer];
        }

        for (unsigned int i = 0; i < length; i++) {
            v[i] = string[i];
        }

        this -> length = length;
    }

    // 5.
    // This constructor copies the passed in string to this string. Since it is
    // being passed by reference, we have access to its private member variables.

    String(const String& s) {

        // 5a: Initialize the char count and buffer size variables to match those of s.

        // 5b: initialize the char pointer member variable to point at 
        //     a new char array that is the size of the buffer size variable

        // 5c: copy the contents from s into the char array

        this -> string = s.string;
        this -> length = s.length;
        this -> buffer = s.buffer;
 
    }

    // 6.
    // The destructor should check if the char pointer is null.
    // If not, delete the array it points to.

    ~String() {
        if (string != 0) {
            delete[] string;
        }
    }

    // 7. 
    // This function appends the contents of v to this string.

    void append(const char* v) {

        // 7a:
        // First, check to make sure that adding the characters
        // to this string won't overflow the buffer.
        // If it will, then we need to reallocate new memory for the string.
        // Don't forget to clean up the old memory and to update the character count.

        unsigned long projectedBuffer = getBufferFromLength(getLengthOfCharString(v)) + (this -> buffer);

        if (projectedBuffer >= this -> buffer) {

            char *temp = string;
            string = new char[projectedBuffer];

            for (unsigned int i = 0; i < getLengthOfCharString(string) + getLengthOfCharString(v); i++) {
                if (i < getLengthOfCharString(string)) {
                    delete[] this -> string;
                    string[i] = temp[i];
                } else {
                    string[i] = v[i];
                }
            }
        }


        this -> length = getLengthOfCharString(string) + getLengthOfCharString(v);
        this -> buffer = projectedBuffer;
    }

    // 8. 
    // This function appends the contents of str to this string.

    void append(const String& str){
        
    }

    //9. getter function for the length of the string (total chars).
    unsigned int length(){
        return 0;
    }

    //10. getter function that returns the location of the char array
    const char* getCharArray(){
        return 0;
    }

    //11. function that returns true if v contains all the same characters
    //    as this string
    bool equals(const char* v){
        return false;
    }

    //12. function that returns true if s contains all the same characters
    //    as this string
    bool equals(const String& s){
        return false;
    }

};