#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
int point=0;

string guess;

enum fields {WORD,HINT,NUM_FiELDS};

const int NUM_WORDS=5;

const string WORDS[NUM_WORDS][NUM_FiELDS]=
{
    {"draxvel", "Nazar or ..."},
    {"danuk", "Bogdan or ..."},
    {"startik","Vova or ..."},
    {"Dana","Name D.S."},
    {"Nika","Name V.Z."},
};


void instruction ()
{
    cout<<"\t\t\tWelcome to Word JumЬle!\n\n";
    cout<< "Unscramе the letters to make а word. \n";
    cout<< "Enter 'hint' for а hint. \n";
    cout<< "Enter 'quit' to quit the game. \n\n";
}
int main ()
{

   instruction();


    while (guess!="quit")
   {

srand(static_cast<unsigned int>(time(0))); //рандом

int choise = (rand()%NUM_WORDS);

string theWord=WORDS[choise][WORD];

string theHint=WORDS[choise][HINT];

string jumble = theWord;

int lenght = jumble.size();

do
{
for (int i(0); i<lenght;i++)
{
    int index1=(rand()%lenght);
    int index2=(rand()%lenght);

    char temp = jumble[index1];
    jumble[index1]=jumble[index2];
    jumble[index2]=temp;
}

}while(jumble==theWord);

cout<< "The jumble is: "<< jumble; //перемішаний варіант слова
cout<<"\n\nYour guess: ";
cin>>guess;

    while(guess!=theWord)
    {
        if (guess=="hint")
        {
          point--;
          cout<<theHint;
        }
        else
            cout<<"Sorry, that's not it "<<endl;
       cout<<"\n\nYour guess: ";
       cin>>guess;
    }

    if (guess==theWord)
       {
        point=sizeof(theWord);
        cout<<"That's it! You guessed it!\n";
       }
}


    cout<<"You have "<<point<<" point"<<endl;
    cout<<"Bye:)";

}
