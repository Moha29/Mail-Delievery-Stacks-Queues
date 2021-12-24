#include "header.h"


//Mohamed Al-zadjali

int main() {
  char sender [MAX]; //for the data needed for the stack function
  char id [MAX];
  char information [MAX];
  char address [MAX];

  int choice = 0; //The user choice from the menu
  int ans;// If the user wanted to add packages
  int s;//To get the returned value from the function
  int pop;//pass it to the dequeue function 

  queue my_queue; //class object

  cout<<"Welcome! This program is going to help you with organizing packages."<<'\n';
//MENU
  while (choice != 6){
    cout<<"~MENU~"<<'\n'<<"(1) Adding a new address with packages."<<'\n'<<"(2) Removing the first address."<<'\n'<<"(3) Removing the last entered package in an address."<<'\n'<<"(4) display all the packages within an address."<<'\n'<<"(5) Dispaly all the addresses with their packages."<<'\n'<<"(6) Exit the program."<<'\n';
    cout<<"What do you want to do (By entering the option's number): ";
    cin>>choice;
    cin.ignore(100,'\n');

//If the user wanted to add an address
    if(choice == 1){
      cout<<'\n'<<"Enter the address of this delivery: ";
      cin.get(address,MAX,'\n');
      cin.ignore(100,'\n');
      
      
//Asking the user if they want to add packages to the address
      cout<<'\n'<<"If you want to enter a package type in 1 if not type any other number: ";
      cin>>ans;
      cin.ignore(100,'\n');
      while(ans == 1){
        //Storing all the information needed in a dynamically allocated arrays to pass it to the function

          cout<<'\n'<<"Enter the sender name and phone number: ";  
          cin.get(sender,MAX,'\n');
          cin.ignore(100,'\n');

          cout<<'\n'<<"Enter the package identification number: ";
          cin.get(id,MAX,'\n');
          cin.ignore(100,'\n');

          cout<<'\n'<<"Enter the package name: ";
          cin.get(information,MAX,'\n');
          cin.ignore(100,'\n');
        //Calling the enqueueing function
          s = my_queue.enqueue(address, sender, id, information);

          if(s == 0){
            cout<<"\n Failure! \n";
          }
          if(s == 1){
            cout<<"\n Saved! \n";
          }
        //If the user wanted to add more packages
          cout<<'\n'<<"If you want to enter a package type in 1 if not type any other number: ";
          cin>>ans;
          cin.ignore(100,'\n');

      }
    }
    
//If the user wanted to remove the last added address
    if(choice == 2){
      pop = 0;//So the it deletes both the stack and queue nodes
      s = my_queue.dequeue(pop);
      if(s == 1){
        cout<<"\n SAVED! '\n";
      }
      if(s == 0){
          cout<<"\n Failure! '\n";
      }
    }
//If the user wanted to only delete from the stack
    if(choice == 3){
      pop = 1;//So that the function only deletes the stack not the queue node
      s = my_queue.dequeue(pop);
      if(s == 1){
        cout<<"\n SAVED! '\n";
      }
      if(s == 0){
          cout<<"\n Failure! '\n";
      }
    }
//If the user wanted to display teh packages within a certain address
    if(choice == 4){
      //Getting the address that the uswer want to display
      cout<<'\n'<<"What is the name of the address you want to display the packages for: ";
      cin.get(address,MAX,'\n');
      cin.ignore(100,'\n');
      s = my_queue.display_add(address);
      if(s == 1)
        cout<<"\n These are all the packages for that address \n";
      else
        cout<<"\n Failure \n";
    }
//If the user wanted to display all the addresses with their packages
    if(choice == 5){
      s = my_queue.display();
      if(s == 1)
        cout<<"\n These are all the packages for that address! \n";
      else
        cout<<"\n Failure \n";
    }

  }


  


  return 0;
}
