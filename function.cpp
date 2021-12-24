#include "header.h"



//Stack constructor
stack::stack(){
  head = NULL;
  top = 0;
}
//Queue constructor
queue::queue(){
  rear = NULL;
}
//Destructor
queue::~queue(){
  while(rear){
   delete [] rear -> address;
   rear -> my_stack.~stack(); //To delete the data of the class object
   rear = rear -> next;
  }
  rear = NULL;
}
//Stack destructor
stack::~stack(){
  int count = 0;
  while(head){
    while(count < 5){
      delete head -> data[count].sender;
      delete head -> data[count].id;
      delete head -> data[count].information;
      count = count + 1;
    }
    head = head -> next;

  }
  delete head;
  head = NULL;
}

//Adding a new address and packages
int queue::enqueue(char * address, char *sender, char * id, char * information){
 
//Base case
  if(!rear){
    rear = new node;
    rear -> address = new char [strlen(address) + 1];
    strcpy(rear -> address, address);
    if(rear->my_stack.push(sender, id, information)){ //Adding the data to the class object
      rear -> next = rear;
    }
    return 1;
  }
  //If the address already existed
  if(strcmp(rear -> address, address) == 0){
    if(rear->my_stack.push(sender, id, information)){
      return 1;
    }
    else
      return 0;
  }
//If there is already a node created
  if(rear){
    node * temp = new node;
    temp -> address = new char [strlen(address) + 1];
    strcpy(temp -> address, address);
    if(temp->my_stack.push(sender, id, information)){
    temp -> next = rear -> next;
    rear -> next = temp;
    rear = temp;
    return 1;
    }
    else
      return 0;
  }

  return 0;

}

//Adding a package
int stack::push(char * sender, char * id, char * information){

//Base case
  if(!head){
    head = new node2;

    head -> data = new package[5];//Creating the LLL f arrays
    
    head ->  data[0].sender = new char[strlen(sender) + 1];
    strcpy(head ->  data[0].sender, sender);

    head ->  data[0].id = new char[strlen(id) + 1];
    strcpy(head ->  data[0].id, id);

    head ->  data[0].information = new char[strlen(information) + 1];
    strcpy(head ->  data[0].information, information);

    top = 1;

    head -> next = NULL;
    
    return 1;
  }


  if(head -> data && top != 5){
    if(top < 5){
      head -> data[top].sender = new char[strlen(sender) + 1];
      strcpy(head ->  data[top].sender, sender);

      head -> data[top].id = new char[strlen(id) + 1];
      strcpy(head ->  data[top].id, id);

      head -> data[top].information = new char[strlen(information) + 1];
      strcpy(head -> data[top].information, information);

      top = top + 1;

      return 1;
    }
    //If the array is full
    if(top == 5){
      node2 * temp = new node2;

      temp -> data = new package[5];
    
      temp ->  data[0].sender = new char[strlen(sender) + 1];
      strcpy(temp ->  data[0].sender, sender);

      temp ->  data[0].id = new char[strlen(id) + 1];
      strcpy(temp ->  data[0].id, id);

      temp ->  data[0].information = new char[strlen(information) + 1];
      strcpy(temp ->  data[0].information, information);

      top = 1;

      temp -> next = head;
      head = temp;
    
      return 1;
    }
  }

  return 0;
}

//To remove an address and the packages
int queue::dequeue(int pop){

  if(pop == 1){ //If the user wanted only to remove the last package
    if(!rear)
	return 0;
    node * current = rear -> next;
    if(rear -> my_stack.pop())
      return 1;
    else
      return 0; 
  }
  node * temp = rear;
  //BAse case
  if(!rear){
    return 0;
  }

  if(rear == rear -> next){
    delete [] rear -> address;
    if(rear -> my_stack.pop())
      rear = NULL;
    rear = NULL;

    return 1;
  }

  if(rear -> next){
    temp = rear -> next;
    rear -> next = temp -> next;
    delete [] temp -> address;
    if(temp -> my_stack.pop()){ //Calling in the removing stack function
      temp = NULL;
    }
    temp = NULL;
    return 1;
  }

  return 0;
}

//Removing stack function
int stack::pop(){
  node2 * current = head;
//Base case
  if(!head)
    return 0;
  if(head){
    //Traverse until the node is empty
    while(top != 0){
    
      delete head -> data[top].sender;
      delete head -> data[top].id;
      delete head -> data[top].information;
      
      top = top - 1;
    }

    if(top == 0){
      delete head -> data[0].sender;
      delete head -> data[0].id;
      delete head -> data[0].information;
      
      if(head -> next){
        head = head -> next;

      }
      delete current;
      current = NULL;
      return 1;
      
    }
    
  }
  return 0;

}
//Displaying all the data
int queue::display(){
  if(!rear){
    return 0;
  }
  node * current = rear -> next;
  while(current != rear ){
    cout<<'\n'<<current -> address<<'\n';
    current->my_stack.display();//Calling the function to display the packages
    current = current -> next;


  }
  cout<<'\n'<<rear -> address<<'\n';
  rear -> my_stack.display();
  return 1;
}
//Displaying by address
int queue::display_add(char * address){
  if(!rear){
    return 0;
  }

  //Finding the address
  if(strcmp(address, rear -> address)==0){
      cout<<'\n'<< rear -> address<<'\n';
      if(rear -> my_stack.display())
        return 1;
      else
        return 0;
  }
  node * current = rear -> next;
  while(current != rear){//Traverse
    if(strcmp(address, current -> address)==0){
      cout<<'\n'<<current -> address<<'\n';
      current->my_stack.display();
      current = current -> next;
      
    }
    }
  cout<<'\n'<<rear -> address<<'\n'<<rear -> my_stack.display()<<'\n';
  return 1;
}
//Stack display function
int stack::display(){
  if(!head){
    return 0;
  }
  node2 * current = head;
  while(current){
    
    while(top > 1){
      cout<<'\n'<<head->data[top-1].sender<<'\n'<< head -> data[top-1].id<<'\n'<<head -> data[top-1].information<<'\n';

      top = top - 1;
    }
    if(top == 1){
      cout<<'\n'<<head->data[0].sender<<'\n'<< head -> data[0].id<<'\n'<<head -> data[0].information<<'\n';
    }
    current = current -> next;
  }
  return 1;
}

int queue::peek(){
  if(!rear){
    return 0;
  }
  cout<<rear -> address;
  return 1;
}

int stack::peek(){
  if(!head)
    return 0;
  node2 * current = head;
  while(current){
    
    while(top > 1){
      cout<<'\n'<<head->data[top-1].sender<<'\n'<< head -> data[top-1].id<<'\n'<<head -> data[top-1].information<<'\n';

      top = top - 1;
    }
    if(top == 1){
      cout<<'\n'<<head->data[0].sender<<'\n'<< head -> data[0].id<<'\n'<<head -> data[0].information<<'\n';
    }
    current = current -> next;
  }
  return 1;
}


