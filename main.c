#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "mpi.h"


int main(int argc, char **argv)
{
   srand(time(NULL));
   int size, rank;
   int a, b = 0;
   
   MPI_Status status;
   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   
   if (size < 5) {
      printf("Need more proc\n"); 
      MPI_Finalize();
      return 0;      
   }
    
   if (rank == 0){
      a = (rand() % 30 + rank); 
      
      MPI_Send(&a, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
      printf("Number first process is %d\n", a);            
   }
   
   if (rank == 1){
      a = (rand() % 30 + rank); 
      
      MPI_Send(&a, 1, MPI_INT, 4, 0, MPI_COMM_WORLD); 
      printf("Number second process is %d\n", a);        
   }
   
   if (rank == 2){
      a = (rand() % 30 + rank); 
      
      MPI_Send(&a, 1, MPI_INT, 4, 0, MPI_COMM_WORLD); 
      printf("Number third process is %d\n", a);          
   }
   
   if (rank == 3){
      a = (rand() % 30 + rank); 
       
      MPI_Send(&a, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
      printf("Number four process is %d\n", a);           
   }
   MPI_Reduce(&a, &b, 1, MPI_INT, MPI_MIN, 4, MPI_COMM_WORLD);
   
   if (rank == 4){
      printf("Minimum number is %d\n", b);         
   }
   
   MPI_Finalize();
}
