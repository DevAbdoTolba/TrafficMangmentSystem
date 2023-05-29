#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void printOpr( int isEmpty, int isFull);

int main() {
  Queue q;
  init_queue(&q);

  // Example usage
  int opr;
  int isEmpty = is_empty(&q);
  int isFull = is_full(&q);
  system("cls");
  printOpr(isEmpty, isFull);

  do {


	  scanf_s("%d", &opr);
	 


	  switch (opr)
	  {
		  case 1 :
			  system("cls");
			  printf("%s",is_empty(&q)  ? "==>No cars are detected\n" : "==>There is cars in field of vision\n");
			  isEmpty = is_empty(&q);
			  isFull = is_full(&q);
			  printOpr(isEmpty, isFull);
			  break;

		  case 2 :
			  system("cls");
			  printf("%s", is_full(&q) ? "==>Traffic jam is at it's max!\n" : "==>There is spcae left for more autos\n");
			  isEmpty = is_empty(&q);
			  isFull = is_full(&q);
			  printOpr(isEmpty, isFull);
			  break;

		  case 3 :
			  if (isFull)
			  {
				  system("cls");
				  printOpr(isEmpty, isFull);
				  break;
			  }

			  system("cls");
			  int carId, carArrivalTime;
			  char carDestination[1];
			  do {

				  printf("Type '-1' without the qutes to cancel\nenter car id, car arrival time -in hours- and car destination \n");
				  scanf_s("%d", &carId);
				  if (carId == -1) break;
				  scanf_s("%d", &carArrivalTime);
				  if (carArrivalTime == -1) break;
				  scanf_s(" %c", carDestination);
				  if (carDestination[0] == -1) break;



				  // scanf_s(" %d %d %c ", &carId, &carArrivalTime, &carDestination);

				  if (carArrivalTime <= 23 && carArrivalTime >= 0)
				  {

					  Car car = { carId, carArrivalTime, carDestination[0]};
					  enqueue(&q, car);
					  system("cls");
					  
					  printf("==>Car inserted \n\n");
					  isEmpty = is_empty(&q);
					  isFull = is_full(&q);
					  printOpr(isEmpty, isFull);
					  break;
				  }
				  else {
					  system("cls");
					  printf("There was an error please check that the time is between 0:23\n");
				  }

			  } while (carId != -1);
			  
			  break;

		  case 4:
			  if (isEmpty) 
			  {
				  system("cls");
				  printOpr(isEmpty, isFull);
				  break;
			  }
			  
			  system("cls");
			 

			  Car car = dequeue(&q);

			  carId = car.id;
			  carArrivalTime = car.arrival_time;
			  carDestination[0] = car.destination;
			  printf("\n\n=============================\n");
			  printf("Car Id : %d\nCar arrival time : %d\nCar destination : %c", carId, carArrivalTime, carDestination[0]);
			  printf("\n=============================\n\n");
			  
			  isEmpty = is_empty(&q);
			  isFull = is_full(&q);
			  printOpr(isEmpty, isFull);

			  break;

		  case 5:
			  if (isEmpty)
			  {
				  system("cls");
				  printOpr(isEmpty, isFull);

				  break;
			  }

			  system("cls");

			  printf("\n\n=============================\n");
			  display_queue(&q);
			  printf("=============================\n\n");
			  isEmpty = is_empty(&q);
			  isFull = is_full(&q);
			  printOpr(isEmpty, isFull);

			  break;



		  default :
			  system("cls");
			  isEmpty = is_empty(&q);
			  isFull = is_full(&q);
			  printf("Please make sure you have entered (1, 2%s%s%s)", isFull ? "" :", 3", isEmpty ? "":", 4", isEmpty ? "" : ", 5");
			  printOpr(isEmpty, isFull);

			  break;
			  /*
	  void init_queue(Queue * q);

	 // int is_empty(Queue * q);
	 // int is_full(Queue * q);
	 // void enqueue(Queue * q, Car car);
	 // Car dequeue(Queue * q);
	 // void display_queue(Queue * q);
  */
	  }

  } while (opr != -1);



  
  return 0;
}


void printOpr(int isEmpty ,int isFull) {

	printf("enter '-1' without the qutes to exit\nWhat operation do you want to perform : \n\n");

	/*
		void init_queue(Queue * q);

		int is_empty(Queue * q);
		int is_full(Queue * q);
		void enqueue(Queue * q, Car car);
		Car dequeue(Queue * q);
		void display_queue(Queue * q);
	*/

	printf("%s%s%s%s%s", "1-Check if there is no cars in the traffic : \n", "2-Check if the trafic jam is at it's limit : \n", isFull ? "" : "3-Insert a new car to the trrafic : \n", isEmpty ? "" : "4-Remove a car from the trafic : \n", isEmpty ? "" : "5-Display the traffic in sequance: \n");


}

