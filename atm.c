#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generatePin();
void welcomeLog();
void atmOptions();
void cashWithdrawal();
void balanceEnquiry();
void cashDeposit();
void receipter();
void Exit();
static int InitialAmount,pin;
int main()
{ 
     welcomeLog();
     atmOptions();
 
}




int generatePin(){
    srand(time(NULL));
int num=rand();
if(num/10==0)//1 digit 
{
    num=num+1234;
}
else if(num/100==0)
{
    num=num+1100;
}
else if(num/1000==0)
{
    num=num+4321;
}
else {
    int tempSum = (num/10000)*10000;// 1111/10000=0.1  = 0.1*10000 => 1111
    num = num - tempSum;// 1111-1111
}
if(num / 1000 == 0){
    num = num + 2521;
}
return num;
}










void welcomeLog(){
    printf("\n*\t Welcome to SRM Bank\t*\n");
       int cardnumber;
    printf("//////////////////////////////////////");
   printf("\n\nInput Your Card Number: "); 
   scanf("%d",&cardnumber);
    printf("\n//////////////////////////////////////\n");
    printf("Your Details:--->");
    
  srand(time(0));
    InitialAmount=rand()%10000+10000;
   printf("\nInitial Amount: %d",InitialAmount);
    pin = generatePin();
    printf("\nYour Pin: %d",pin);
}

void atmOptions()
{
    printf("\n///////////////////////\n\n");
    printf("1.-> Cash Withdrawal\n");
    printf("2.-> Cash Deposit\n");
    printf("3.-> Balance Enquiry\n");
    printf("4.-> Exit");
    printf("\n\n///////////////////////");
    printf("\n\nUser Input -> ");
    int selectedOption;
    scanf("%d",&selectedOption);
    printf("\n///////////////////////\n\n");
    int tempPin;
    switch(selectedOption){
        case 1:
            cashWithdrawal();           
        break;
        case 2:
            cashDeposit();
        break;
        case 3:
             printf("Enter You Pin -> ");
            scanf("%d",&tempPin);
            if(tempPin == pin){
                balanceEnquiry();
            }else{
                printf("\nThe pin was incorrect");
            }
        break;
        case 4:
            Exit();
        break;
        default:printf("Invalid Input ");
                 Exit();
        break;
    }
    
}

void cashWithdrawal(){
    printf("Enter You Pin -> ");
    int tempPin;
    scanf("%d",&tempPin);
    if(tempPin == pin){
        printf("\n/////////////////////////////\n");
        printf("\nEnter Withdrawal Amount : ");
        int withdrawalAmount;
        scanf("%d",&withdrawalAmount);
        if(withdrawalAmount > InitialAmount){
            printf("\nInsufficient Amount in Your Account");
            balanceEnquiry();
           
        }else{
            printf("\nWithdrawal Successfull !! Please Take Your Receipt");
            InitialAmount = InitialAmount - withdrawalAmount;
            receipter(InitialAmount,withdrawalAmount,1);
            balanceEnquiry();
      
        }
        
    }else{
        printf("\nThe pin was incorrect");
        Exit();
    }
    
}
void receipter(int availableAmount , int Amount, int checkWorD){
    time_t t;
    time(&t);
    FILE *filePointer;
    filePointer = fopen("BankReceipt.txt","w");
    fprintf(filePointer,"\n\t**SRM BANK OF SYRIA**\n\n\n");
    
    fprintf(filePointer,"Transancion Done on  : %s\n\n",ctime(&t));
    fprintf(filePointer,"Txn No -> 36521\n");
    fprintf(filePointer,"Response Code -> 000\n");
    if(checkWorD == 1){
    fprintf(filePointer,"Withdrawal Amount -> Rs.%d\n",Amount);
    }else{
        fprintf(filePointer,"Deposited Amount -> Rs.%d\n",Amount);
    }
    fprintf(filePointer,"Mod Bal -> Rs.00\n");
    fprintf(filePointer,"Available Balance -> Rs.%d\n\n",availableAmount);
    fprintf(filePointer,"Note -> If this transanction is not acceded by you . Please Report it to 1800-456-1356");
}
void cashDeposit(){
    printf("Enter Your Pin : ");
    int tempPin;
    scanf("%d",&tempPin);
    if(tempPin == pin){
    printf("\n////////////////////////\n\nEnter Deposit Amount : ");
    int tempDepoAmount;
    scanf("%d",&tempDepoAmount);
    InitialAmount = InitialAmount + tempDepoAmount;
    printf("\nDeposit Successfull !! Don't forget to take your receipt");
    receipter(InitialAmount,tempDepoAmount,0);
    balanceEnquiry();

    }else{
        printf("\nThe pin was incorrect");
        Exit();
    }
}

void balanceEnquiry(){
    printf("\n---------------------------------");
    printf("\nAvailable Balance : Rs.%d",InitialAmount);
    Exit();
}
void Exit(){
   printf("\n\nThank You ! Visit Again ");
}
