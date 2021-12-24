#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;



//The purpose of this program is to provide the mail man with the addresses of the delivery and the package information needed for each package.


const int MAX = 100; //Constant for all the dynamically allocated arrays


//This structure is to hold the data in the stack node
struct package{
  char * sender;
  char * id;
  char * information;
};

//stack node
struct node2{
  package * data;
  node2 * next;
};


//class to manage the stack LLL of arrays
class stack{
  public:
    stack(); 
    ~stack();
    int push(char * sender,char * id, char * information ); 
    int pop();
    int peek();
    int display();
  private:
    node2 * head;
    int top; 
};

//queue node with stack class object as the data and a dynamically allocated array 
struct node{
  char * address;
  stack my_stack;
  node * next;
};

//Class to manage the queue CLL 
class queue{
  public:
    queue();
    ~queue();
    int enqueue(char * address, char *, char *, char *); //Passing all the information needed for both the staks and queues 
    int dequeue(int); //To decide wether to delete from the stack or both the stack and the queue
    int peek();
    int display_add(char *); //Display by address
    int display(); //Display all
  private:
    node * rear;
};
