#include<stdio.h>
#include<stdlib.h>

int A_rows,A_columns,A[1000][1000],B[1000][1000],B_rows,B_columns,y,q,sum[1000][1000],L;

//to ENTER MATRIX A AND B..........................................................
int matrix()
{
printf("Matrix A\n");
printf("ENTER Numbers of A_rows =");
scanf("%d",&A_rows);
printf("ENTER Numbers of A_columns =");
scanf("%d",&A_columns);

FILE *pr=fopen("MATRIX_A.txt","w+");
fprintf(pr,"MATRIX A\n");
        for(int i=0;i<A_rows;i++){
            for(int j=0;j<A_columns;j++)
            {
                printf("A[%d][%d] = ",i,j);
                scanf("%d",&A[i][j]);
               fprintf(pr,"%d",A[i][j]);
               fprintf(pr," ");
            }
        fprintf(pr,"\n");
        }
    fclose(pr);
    
printf("Matrix B\n");
printf("ENTER Numbers of B_rows =");
scanf("%d",&B_rows);
printf("ENTER Numbers of B_columns =");
scanf("%d",&B_columns);

 FILE *pt=fopen("MATRIX_B.txt","w+");
 fprintf(pt,"MATRIX B\n");
        for(int i=0;i<B_rows;i++){
            for(int j=0;j<B_columns;j++)
            {
                printf("B[%d][%d] = ",i,j);
                scanf("%d",&B[i][j]);
               fprintf(pt,"%d",B[i][j]);
               fprintf(pt," ");
            }
        fprintf(pt,"\n");
        }
    fclose(pt);
return 9;
}

//END.............................................................................

//MULTIPLICATION.......................................
void MULTIPLICATION()
{
    
    FILE*v=fopen("r_esult.txt","w");
    fprintf(v,"MULTIPLICATION");
    fprintf(v,"\n");
	 if(A_columns!= B_rows){
	 	printf("ERROR IN dimensions\n");
	 }
	 else
     {
	 	for(int i=0; i<A_rows; i++){
	 		for(int j=0; j<B_columns; j++){
	 			int c = 0;
	 			for(int k=0; k<A_columns; k++){
	 				c = c + A[i][k]*B[k][j];
                    
	 			}
                fprintf(v,"%d",c);
                fprintf(v," ");
	 		}
	 		fprintf(v,"\n");
	 	}
	 	
	 }
	 fclose(v);
}
//END.........................................
//ADATION.......................................................................
 void addition_Subtraction()
 {
FILE*v=fopen("r_esult.txt","w");

  if(q==1)
   {
    fprintf(v,"Addition\n");
     for(int i=0;i<A_rows;i++){
        for(int j=0;j<A_columns;j++)
         {
            sum[i][j]=A[i][j]+B[i][j];
            fprintf(v,"%d",sum[i][j]);
            fprintf(v," ");
         }
       fprintf(v,"\n");  
    }


   }
  else if(q==2)
   {
    fprintf(v,"Subtraction\n");
     for(int i=0;i<A_rows;i++){
        for(int j=0;j<A_columns;j++)
         {
            sum[i][j]=A[i][j]-B[i][j];
            fprintf(v,"%d",sum[i][j]);
            fprintf(v," ");
         }
         fprintf(v,"\n");
}

   }
fclose(v);
}

//WRITE FILE......................................................................
void write_file()
{
    FILE*vm=fopen("result.txt","w");
        fprintf(vm,"\rMATRIX A\n");
          for(int i=0;i<A_rows;i++){
            for(int j=0;j<A_columns;j++)
             {
               
               fprintf(vm,"%d",A[i][j]);
               fprintf(vm," ");
             }
           fprintf(vm,"\n");
            }
            fprintf(vm,"..............................................\n ");
        fprintf(vm,"\rMATRIX B\n");
          for(int i=0;i<B_rows;i++){
            for(int j=0;j<B_columns;j++)
             {
               
               fprintf(vm,"%d",B[i][j]);
               fprintf(vm," ");
             }
           fprintf(vm,"\n");
            }
            fprintf(vm,"..............................................\n ");
    
if(L==1 || L==2)
{
        fprintf(vm,"\rRESULT\n");
          for(int i=0;i<A_rows;i++){
            for(int j=0;j<A_columns;j++)
            {
               
               fprintf(vm,"%d",sum[i][j]);
               fprintf(vm," ");
            }
        fprintf(vm,"\n");
        }
        fclose(vm);
}  
    
    
    
else if(L==3)
 {
	 	fprintf(vm,"\rRESULT\n");
	 	   for(int i=0; i<A_rows; i++){
	 		 for(int j=0; j<B_columns; j++){
	 			int c = 0;
	 			for(int k=0; k<A_columns; k++){
	 				c = c + A[i][k]*B[k][j];

	 			}
	 		   fprintf(vm,"%d",c);
	 		   fprintf(vm," ");
	 		}
	 	fprintf(vm,"\n");
	 	}
	 fclose(vm);
 } 
}
  

//END...........................................................................

//READ FROM A FILE..............................................................
void read_from_file()
{
    int x;
    printf("ENTER NUMBER 1 TO LOAD MATRIX A NYMBER 2 TO LOAD MATRIX B\n");
    scanf("%d",&x);
    if(x==1)
    {
    char s[150];
    FILE*pr=fopen("MATRIX_A.txt","r");
       fgets(s,150,pr);
       puts(s);
          for(int i=0;i<A_rows;i++){
            for(int j=0;j<A_columns;j++)
             {
               fscanf(pr,"%d",&A[i][j]);
               printf("%d",A[i][j]);
               printf(" ");
             }
           printf("\n");
            }
        fclose(pr);
    } 
    else if(x==2)
    {
            char z[150];
    FILE*pt=fopen("MATRIX_B.txt","r");
       fgets(z,150,pt);
       puts(z);
          for(int i=0;i<B_rows;i++){
            for(int j=0;j<B_columns;j++)
             {
               fscanf(pt,"%d",&B[i][j]);
               printf("%d",B[i][j]);
               printf(" ");
             }
           printf("\n");
            }
        fclose(pt);
        
        
    }
}

//END...........................................................................

//MAIN....................................................................................................
int main()
{
    
matrix();
int flag=0;
printf("\n");
printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Load from a file\n5.Write to a file\n6.Exit\n");
printf("\n");
printf("\nplease Enter Number for choose = ");
scanf("%d",&q);


while(q>0 && q<7)
{

    switch(q)
   {
       case 1:
            if(A_rows==B_rows && A_columns==B_columns )
             {
                addition_Subtraction();
                flag=1;
                L=1;
             }
        else
                   printf("SORRY YOU CAN'T ADATION BECAUSE SIZE MATRIX A NOT EQUAL  MATRIX B" );
       break;
       case 2:
           if(A_rows==B_rows && A_columns==B_columns )
             {
                addition_Subtraction();
                flag=1;
                L=2;
             }
        else
                   printf("SORRY YOU CAN'T ADATION BECAUSE SIZE MATRIX A NOT EQUAL  MATRIX B" );
       break;
       case 3:
       
                 MULTIPLICATION();
                 flag=1;
                 L=3;
       break;
       case 4:
                 read_from_file();
      
       break;
       case 5:
            if(flag==1)
             {
                write_file();
                
             }
             else
                    printf("YOU CAN USE WRITE TO FILE AFTER CHOOSE process OF MATRIX" );
       break;
       case 6:
        return 0;
       default:
      printf("\nplease Enter Number of 1 To 6 ");
    }
    printf("\n");
    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Load from a file\n5.Write to a file\n6.Exit\n");
    printf("\n");
    printf("\nplease Enter Number for choose = ");
    scanf("%d",&q);
    printf("\n");
}
}
//END..............................................................................................................



