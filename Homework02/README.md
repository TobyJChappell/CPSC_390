# Best-First Robot Navigation

@name Toby Chappell  
@student_id 2312642  
@email tchappell@chapman.edu  
@course CPSC-390
@assignment 2  

Description:

Description of project found in Homework02.pdf. To run, run `make all` and then `./assignment2.exe <input_file>`. If no input file name is given or the one given does not exist, the user will then be prompted for a valid input file. Once the program executes, output is in the form of a text file titled "output.txt" and consists of the output of each search algorithm. For each algorithm, the file displays the most cost-efficient path found followed by the path cost (the steps taken to get to the goal node along the the path), the number of steps taken in total to find the goal node (the number of cells removed from the fringe), and the number of nodes in the search tree (number of cells put on the fringe in total). Note, the step calculations assume that the initial position is at step 0 (since no steps were taken) and the number of nodes in the search tree includes the initial position (since the initial node is still apart of the search tree).

References:

Doubly Linked List used for fringe taken from CPSC 350 Assignment 5 at (slightly modified): https://github.com/TobyJChappell/CPSC_350/tree/master/Assignment_5

Gave Help To:

Joshua Barrs
