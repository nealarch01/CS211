/****************************************************************************
CS211
Queue application
Template written by Kazumi Slott

Neal Archival
March 16, 2021

To compile:
g++ -pthread game.cpp queue.cpp

This program will ask the user to answer math questions (add, sub, mult, div).
The queue will have 3 questions before the game starts. After the game starts, a new question
will be added every 1 second if the level is 5, 2 seconds if the level is 4, .. 5 seconds if the level is 1.
The user will be asked to choose a level from 1 to 5 before the game starts.
A question for the user to answer will be removed from the front of the queue. The user will be asked to answer
the same question until he gives the correct answer. After he gives a correct answer, the next question will be removed from the front of
the queue.

When the queue grows to have 10 questions (the queue is full), the game ends and the user loses (he was too slow doing the math). 
When the queue becomes empty, the game ends and the user wins (he was quick doing the math).
When the user answers 100 questions correctly, the game ends and the user wins (the queue never became empty or full).

This program uses one thread to add new questions to the queue and another to let the user 
enter math questions.
*****************************************************************************/

#include <time.h>
#include <iostream>
#include <pthread.h> // posix thread
#include <cstdlib>
#include "checkInput.h"
#include "queue.h" //your queue class
using namespace std;

/******************************
Place the following code in queue.h
Then comment this section. 
********************************/
//create an enumuration type
//create a struct that will have an operand, a operator, another operand

/*******************************
Place the above code to queueu.h
*******************************/

//prototypes
void *answerQuestion(void *data);
void *addQuestion(void *data);
int correctAnswer(int op1, char optr, int op2);
char getOperator(op optr);
expr makeQuestion();

//global - easier to share them between threads
Queue q;              //create a queu object. the queue will store math questions
bool win;             //set to true if win, false if lose
int numCorrect = 0;   //the number of correct questions the user answered
pthread_mutex_t lock1; //used to lock a part of code where a shared resource (q) // changed lock to lock1 due to ambigious error during compilation
//is updated by a thread
int level;            //level of difficulty (1 for easy/slot, 5 for hard/fast)

int main() {
  //get a different sequence of random numbers in each run
  srand(time(NULL));

  //adds 3 questions into the rear of the queue
  q.add(makeQuestion());
  q.add(makeQuestion());
  q.add(makeQuestion());
  // ?????
  // ?????

  cout << "Which level do you want to try? 1 (easy) to 5 (hard): ";
  //level 1 will add a new question every 5 seconds. If level 2, every 4 seconds. If level 5, every 1 second.
  level = getData(1, 5, "Invalid level. Enter 1 to 5: "); //from checkInput.h

  //initialize the mutex
  if (pthread_mutex_init(&lock1, NULL) != 0)
  {
    cout << "Creating a mutext failed." << endl;
    return 1; //ending the program. 1 is an error code passed to the operating system
  }

  //delcare 2 threads. first thread to add new questions and second for the user to answer questions.
  pthread_t tAddQues, tAns;

  //thread to add new qustions to the rear of the queue
  pthread_create(&tAddQues, NULL, &addQuestion, NULL);

  //thread for the user to answer questions removed from the front of the queue
  pthread_create(&tAns, NULL, &answerQuestion, NULL);

  //wait for the thread to come back from addQuestion()
  pthread_join(tAddQues, NULL);

  //wait for the thread to come back from answerQuestion()
  pthread_join(tAns, NULL);

  //win is set to true in answeQuestion() - if the user answers quickly and the queue gets empty or he answers 100 questions correctly, the user wins the game
  if (win == true) {
    cout << "You win" << endl;
  }
  else { //if the user doesn't answer questions quick enough and the queue grows to have 10 questions, he loses.
    cout << "You Lose" << endl;
  }
  cout << "You answered " << numCorrect << " questions correctly." << endl;
  return 0;
}
/******************************
This function is going to add an
expr object or question into the
queue 
********************************/
void *addQuestion(void *data) {
  expr newQ; //a new question to be added

  clock_t endWait;
  //a new question will be added to the queue every 1 second if the level is 5,
  //2 seconds if the level is 4, .. 5 seconds if the level is 1.
  clock_t waitTime = CLOCKS_PER_SEC * ((-1 * level) + 6); // using linear equation m = -1, y-intercept(b) = 6 so y= -1(level) + 6
  endWait = clock() + waitTime; // 
  //as soon as the queue grows to have 10 questions(full), gets empty or the user answers 100 questions correctly, the game ends
  while (!q.isFull() && !q.isEmpty() && numCorrect < 100) { // while it is not full
    //it is time to add a new question to the queue
    if (clock() >= endWait) {
      //create a new question
        newQ = makeQuestion();
        //lock the code so this thread has exclusive access to the queue while updating
        pthread_mutex_lock(&lock1);
        q.add(newQ);
          
      //add the new question to the rear of the queue
      pthread_mutex_unlock(&lock1); //unlock the exclusive access so the other thread
  //can access the queue now
      //reset the end wait time
      endWait = clock() + waitTime;
    }
  }
}
/******************************
This function is going display
the expression to the user,
take user input, and check if
the input is correct
********************************/
void *answerQuestion(void *data) {
  int answer, correct;
  int op1, op2;
  char opr;
  expr e;
  //as soon as the queue grows to have 10 questions(full), gets empty, or the user answers 100 questions correctly, the game ends
  while (!q.isFull() && !q.isEmpty() && numCorrect < 100) {
    //get the question from the front of the queue
    //lock the code so this thread has exclusive access to the queue while updating
    pthread_mutex_lock(&lock1);

    e = q.remove(); // set equal to the removed 
    pthread_mutex_unlock(&lock1); //unlock the exclusive access so the other thread
     //can access the queue now

    op1 = e.oprd1;
    opr = getOperator(e.oprt); // <-------- generate a random operand fix later
    op2 = e.oprd2;

    //get the answer to the question
    correct = correctAnswer(op1, opr, op2);

    //ask the usert to enter the user's answer
    cout << op1 << " " << opr << " " << op2 << " = ";
    //cout << ????? << " = "; //Show the expression struct at once
    cin >> answer;

    //as long as the user's answer is wrong, she/he will have to retry answering the same question
      while(answer != correct && !q.isFull()) {
        cout << "WRONG. try again. " << op1 << " " << opr << " " << op2 << " = ";
        //cout << "WRONG. try again. " <<  ??????  << " = ";  //Show the expression struct
        cin >> answer;
      }
      //the user's answer was correct. the number of correct increases
    if(correct == answer) numCorrect++;

    //if the queue grows to have 10 questions, the user loses the game
    //if the queue gets empty or the suer answers 100 questions correctly, the user wins the game
  if(numCorrect >= 100 || q.isEmpty()) win = true;
  else win = false;
  }
}
/******************************
This function will conver the op
enum type into an actual operator
op oprt is the enum object
********************************/
  char getOperator(op optr) {
    switch (optr) {
    case (ADD):
      return '+';
      break;
    case (SUB):
      return '-';
      break;
    case (MULT):
      return '*';
      break;
    case (DIVI):
      return '/';
      break;
    }
  }

/******************************
This function is going to calculate
the correct answer from the 
expression and return it
as an integer
op1 is the left hand operand
oprt is the operator
op2 is the right hand operand
********************************/
  int correctAnswer(int op1, char optr, int op2) {
    switch (optr) {
    case ('+'):
      return op1 + op2;
      break;
    case ('-'):
      return op1 - op2;
      break;
    case ('*'):
      return op1 * op2;
      break;
    case ('/'):
      return op1 / op2;
      break;
    }
  }

  //creates a question and returns a struct
  /*****************************************************************
   This function generates random numbers, assigns them to the operand
   and generates a random operator
  *******************************************************************/
  expr makeQuestion() {
  int temp;
  expr e;
  e.oprt = (op)(rand() % 4); //0 for add, 1 for sub, 2 for mult, 3 for divi, op for typecasting
  if (e.oprt == 2) { //if the operator is multiplication, make operands between 1 and 20 for the first operand and between 1 and 10 for the second operand.
    // (large operands would make multiplication hard.
    e.oprd1 = rand() % 20 + 1; //create a random number between 1 and 20
    e.oprd2 = rand() % 20 + 1; //create a random number between 1 and 10
  }
    else { //the operator is add, sub or divi. Make operands between 1 and 100
    e.oprd1 = rand() % 100 + 1; //create a randowm number between 1 and 100
    e.oprd2 = rand() % 100 + 1; //create a randowm number between 1 and 100
    //if the operator is sub or division, the first operand should be greater than or equal to the second operator (otherwise the calulation
    //would the too difficult for SUB and too easy for DIVI.
      if (e.oprt == 1 || e.oprt == 3) { // if subtraction or division
        if (e.oprd1 < e.oprd2) { //if the second operand is larger, swap operand1 and operand2
          temp = e.oprd1;
          e.oprd1 = e.oprd2;
          e.oprd2 = temp;
        }
      }
    }
    return e;
  }


