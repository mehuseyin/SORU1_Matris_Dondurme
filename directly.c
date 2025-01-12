#include <stdio.h>

int main(){

int n,t,k,c;
//entrance the size of matrix
printf("enter the size of matrix:\n");
scanf("%d",&n);
printf("enter the values of matrix\n");

//defineing matrixes
int matrix_original[n][n];
int matrix_reserve[n][n];
int matrix_result[n][n];

//entrance for matrix values
for (t=0;t<n;t++){
    printf("\n%d. raws values:\n",t+1);
        for(k=0;k<n;k++){
        scanf("%d",&matrix_original[t][k]);
    }
}

int o=0 ;

 while(o<1){
    //giving three options to user
     printf("\npress 1 for right, 2 for left or 0 to stop\n");

    while(1){
    
     scanf("%d",&c);

    //the first one is turning the matrix to the right 
    if (c==1){
        for(t=0;t<n;t++){
         for(k=0;k<n;k++){
            matrix_result[k][n-t-1]=matrix_original[t][k];
         }
        }
        printArrays(n,matrix_original,matrix_result);
         break;
    }
    //the second one is turning the matrix to the left
    else if (c==2){
        for(t=0;t<n;t++){
         for(k=0;k<n;k++){
            
            matrix_result[n-k-1][t]=matrix_original[t][k];
        }
       }
       printArrays(n,matrix_original,matrix_result);
        break;
    }
    //the last one stops the code
    else if(c==0){
        o=10000;
        
     break;
    }
    //warning for unaccepteable entrance
    else {
    printf("please press 1, 2 or 0!!!\n");

     }
     }
    }

 }
//function to print original matrix and result matrix
   void printArrays(int n,int matrix_original[n][n],int matrix_result[n][n]){
    printf("\n");   
    printf("matrix_original:\n");
 	for (int t=0;t<n;t++){
 		printf("\n");
 		for(int k=0;k<n;k++){
 			printf("%d ",matrix_original[t][k]);
		 }
    }

    
    printf("\n\n");
    printf("matrix_result:\n");
 	for (int t=0;t<n;t++){
 		printf("\n");
 		for(int k=0;k<n;k++){
 			printf("%d ",matrix_result[t][k]);
		 }
         
    }

}

     
