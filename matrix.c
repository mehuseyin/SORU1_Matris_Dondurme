#include <stdio.h>
void printArrays();
int main(){

int n,t,k,c;
//kullanıcıdan matris boyutlarını istiyoruz
printf("enter the size of matrix:\n");
scanf("%d",&n);
printf("enter the values of matrix\n");

//matriselri tanımlıyorum
int matrix_original[n][n];
int matrix_reserve[n][n];
int matrix_result[n][n];

//matris degerleri icin kullanıcıdan girdi alıyorum
for (t=0;t<n;t++){
    printf("\n%d. raws values:\n",t+1);
        for(k=0;k<n;k++){
        scanf("%d",&matrix_original[t][k]);
    }
}

int o=0 ;

 while(o<1){
    //kullanıcıya 3 opsıyon veriyoruz
     printf("\npress 1 for right, 2 for left or 0 to stop\n");

    while(1){
    
     scanf("%d",&c);

    //birinci opsiyon saga dondermek icin
    if (c==1){
        for(t=0;t<n;t++){
         for(k=0;k<n;k++){
            matrix_result[k][n-t-1]=matrix_original[t][k];
         }
        }
        printArrays(n,matrix_original,matrix_result);
         break;
    }
    //ikinci opsiyon sola dondermek icin
    else if (c==2){
        for(t=0;t<n;t++){
         for(k=0;k<n;k++){
            
            matrix_result[n-k-1][t]=matrix_original[t][k];
        }
       }
       printArrays(n,matrix_original,matrix_result);
        break;
    }
    //sonuncusu ise programı durdurmak icin
    else if(c==0){
        o=10000;
        
     break;
    }
    //verilen opsitonlar dışında girdi alınırsa uyarı veriyoruz
    else {
    printf("please press 1, 2 or 0!!!\n");

     }
     }
    }

 }
//orginal ve sonuc matrıslerını yazdırmak icin tanımlaan fonksiyonlar
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

     
