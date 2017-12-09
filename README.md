# Input/Output
   [main.cpp lines 23-26](/main.cpp#L23)
   I use three different cout statements to present the user three different options, then use cin 
   to save their input into a variable.
# Control Flow
   [main.cpp lines 27-95](/main.cpp#L27)
    This chunk of code takes the users input that they input on lines 26 and tests to see which option the user
    chose. It uses an if statement to test if the user wants to  exit, two else if statements to see if the
    user wants to access and create an account, and an else statement that is triggered by an invalid input.
# Iteration 
   [main.cpp lines 73-82](/main.cpp#L73)
    Lines 73-86 gives the user the option to re-enter their password if they incorrectly typed it in the first
    time. It calls a function that chechks their input password and if it returns false the while loops keeps
    running.
   [main.cpp lines 22-96](/main.cpp#L22)
    This piece of my program runs while the user is choosing to create an account, access an account or exit.
    Until the user chooses a valid option the do-while loop will continue to run.
# Data Structures
   [main.cpp line 18](/main.cpp#L18)
    Line 18 contains a style array called username. I have to use a c style array instead of a string because
    username is the variable used to name created files. 
# Function
   [main.cpp lines 137-196](/main.cpp#L137)
      Lines 137-196 contain the functions of my main.cpp. I have two void functions that create and exit 
      accounts. The closeAccount function takes a char* , a double and a string that it uses to create and
      save a file. I have a double function that returns the string it is passed into a double. I have two 
      boolean functions that are used to test for correct passwords and valid files.
# File I/O
   [main.cpp lines 178-183](/main.cpp#L178)
     This function creates an ofstream named write. It then takes the username it's passed and deletes the file
     named the username. It then creates a new file named the username it was passed, writes the string
     it was passed to the first file and writes the double it was passed onto the next line. Then exits.
# Class
   [account.cpp lines 1-38](/main.cpp#L1)
    This account class contains a constructor that sets the classes private member variables to 0 and " ". The
    class also contains the public class functions that edit the member variables.
