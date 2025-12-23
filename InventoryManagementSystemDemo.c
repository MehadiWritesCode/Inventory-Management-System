
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
 char adminName[21] = "mehadi hasan";
 char adminPass[21] = "ariful";

void AdminLogin(){

  char admin_name[21];
  char admin_pass[21];

  printf("Please Enter Your user Name : ");
  getchar();
  scanf("%[^\n]",admin_name);


  printf("Pleas enter your Password : ");
  getchar();
  scanf("%[^\n]",admin_pass);


  if(strcmp(admin_name,adminName) == 0 && strcmp(admin_pass,adminPass) == 0){
    printf("\n\n--->>> Login SuccessFull <<<---\n\n");
     AdminOffice();
    return;
  }

  else{

    printf("\nInvalid Information\n");
    return;

  }

}
void AdminOffice(){

   int ch;
   char n[20];
   int id , p;

   while(1){
    printf("\n1) Add Discount Products\n");
    printf("2) Remove Discount Products\n");
    printf("3) See User Information\n");
    printf("4) Remove Buyers Details from Stack\n");
    printf("5) Exit\n");

    printf("\nPlease enter your choice : ");
    scanf("%d",&ch);

    switch(ch){

       case 1 : printf("\nProduct Name : ");
                getchar();
                scanf("%[^\n]",n);

                printf("Price : ");
                scanf("%d",&p);

                printf("Id  : ");
                scanf("%d",&id);

                enqueue(n,p,id);
                break;

       case 2: dequeue();
               break;

       case 3: Userinfo_Display();
               break;

       case 4: pop();
               break;

       case 5:return;

    }
   }
}

struct discount_list{

   char dis_item[20];
   int dis_price;
   int dis_code;

}Queue[5];

int front = -1 , rear = -1;

void enqueue(char n[20] , int p , int id){

   if(rear >= 4){
    printf("Queue is Full\n");
    return;
   }

   rear++;
   if(front == - 1 ){
    front = 0 ;
   }
   strcpy(Queue[rear].dis_item,n);
   Queue[rear].dis_price = p;
   Queue[rear].dis_code  = id;

   printf("\n\n--->>> Item Added Successful <<<---\n\n");
   return;

}

void dequeue(){

 if(front == -1  && rear ==  -1){

    printf("\n\n--->>> Queue is Empty <<<---\n\n");
    return;
 }

 printf("\n\n%s discount item removed\n\n",Queue[front].dis_item);

 front++;
 if(front >= rear){

    front = - 1;
    rear = -1;

 }

 return;
}


int  discount_Buyers(int id){
     if(front == -1){

        printf("\n\n--->>> There is no Discount Item <<<---\n\n");
        return;
    }
     for(int i = front ; i <= rear ; i++)
       if(Queue[i].dis_code == id)
          return Queue[i].dis_price;

   return -1;
}

void displayQueue(){

     if(front == -1){

        printf("\n\n--->>> There is no Discount Item <<<---\n\n");
        return;
    }

 for(int i = front ; i <= rear ; i++){

    printf("\nItem : %s\n",Queue[i].dis_item);
    printf("Price :%d\n",Queue[i].dis_price);
    printf("Code  :%d\n",Queue[i].dis_code);

    printf("\n\n");
 }

 return;

}
struct node{

     char name[50];
     char password[50];

     struct registration* next;

};

struct node* head = NULL;

struct list{

   char item[20];
   int price;
   int code;

}devices[10];

void myItem(){

  strcpy(devices[0].item ,"Fan");
  devices[0].price = 3500;
  devices[0].code = 6543;

  strcpy(devices[1].item ,"TV");
  devices[1].price = 30000;
  devices[1].code = 2321;

  strcpy(devices[2].item ,"AC");
  devices[2].price = 35000;
  devices[2].code = 3432;

  strcpy(devices[3].item ,"Laptop");
  devices[3].price = 95000;
  devices[3].code = 7723;

  strcpy(devices[4].item ,"Mobile");
  devices[4].price = 77000;
  devices[4].code = 2322;

}

void displayItem(){

  myItem();

  for(int i = 0 ; i < 5 ; i++)
      printf("\nItem %d : %s\nPrice  : %d\nId     : %d\n",i+1,devices[i].item,devices[i].price,devices[i].code);

  printf("\n");

}

void FindById(int id){

   myItem();

    for(int i = 0 ; i < 5 ; i++){

        for(int j = i+1 ; j < 5 ; j++){

            if(devices[i].code > devices[j].code){

                struct list temp = devices[i];
                devices[i] = devices[j];
                devices[j] = temp;
            }
        }
    }

    int left = 0 , right = 4 ;

    while(left <= right){

        int mid = (left + right ) / 2;

        if(devices[mid].code == id){
            printf("\nItem %d : %s\nPrice  : %d\nId     : %d\n\n",mid,devices[mid].item,devices[mid].price,devices[mid].code);
            return  ;
        }

        else if( id < devices[mid].code)
            right = mid - 1;
        else
            left = mid+1;
    }

    printf("\n\nInvalid Id\n\n");
    return ;

}

int RegularBuy(int id){

   myItem();

  for(int i = 0 ; i < 5 ; i++){

    if(devices[i].code == id){

        return devices[i].price;

    }
  }

   return -1;
}

bool Register(char n[50]  , char p[50]){

    struct node* newnode = (struct node*) malloc(sizeof(struct node));

    if(newnode == NULL){
       printf("!!! Memory Allocation Failed !!!\n\n");
        return false;
    }

    strcpy(newnode -> name , n );
    strcpy(newnode -> password , p );

    if(head == NULL){

        newnode -> next = NULL;
        head = newnode ;
        return true;
    }

    struct node* temp = head ;

    while (temp -> next != NULL)
        temp = temp -> next;


     temp -> next = newnode;

     return true;
}

bool Login(char username[50], char password[50]) {
    struct node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, username) == 0 && strcmp(temp->password, password) == 0) {
            //printf("\n\n--->>> Login Successful <<<---\n\n");
            return true;
        }
        temp = temp->next;
    }

 //   printf("\n\nInvalid user name or password\n\n");
    return false ;
}

void Logout(char username[50], char password[50]){

   if(head == NULL){
      printf("\n\n--->>> Account not found\n\n");
      return;
   }

   else{
        struct node* temp = head;
        while (temp != NULL){

            if(strcmp(temp->name, username) == 0 && strcmp(temp->password, password) == 0){

                struct node* dlt = temp;

                temp = temp -> next;
                free(dlt);

                printf("\n\n--->>> Logout Successful <<<---\n\n");
                return;
            }
        }

      printf("\n\n--->>> Account not found\n\n");
      return;
   }

}

void SortByPrice() {
    myItem();

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (devices[i].price > devices[j].price) {
                struct list temp = devices[i];
                devices[i] = devices[j];
                devices[j] = temp;
            }
        }
    }

    for (int k = 0; k < 5; k++)
        printf("\nItem %d: %s\nPrice: %d\nId: %d\n", k + 1, devices[k].item, devices[k].price, devices[k].code);

    return;
}

struct stack{

   char b_name[50];
   char phone[12];

   struct stack* next;

};

struct stack* start = NULL;

void pushDetails(){

  char name[20];
  char phone_no[12];

  printf("Please enter your name : ");
  getchar();
  scanf("%[^\n]",name);

  printf("Please enter your phone number : ");
  getchar();
  scanf("%[^\n]",phone_no);

  struct stack* newnode = (struct node*)malloc(sizeof(struct node));

  strcpy(newnode -> b_name,name);
  strcpy(newnode -> phone,phone_no);

  if(start == NULL){

    newnode -> next = NULL;
    start = newnode;
    return;
  }

  struct stack* temp = start;

  while(temp-> next != NULL)
       temp = temp -> next;

   newnode -> next = NULL;

   temp -> next = newnode;

   return;
}

void pop() {
    if (start == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("\nItem pop successful!!\n");
        return;
    }

    struct stack* temp = start;

    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("\nItem pop successful!!\n");
    return;
}

void Userinfo_Display(){

        if(start ==NULL){

            printf("\nNo User Information Here\n");
            return;
        }

        struct stack* temp = start;

        while(temp != NULL){

            printf("\nName: %s\nPhone: %s\n", temp -> b_name, temp->phone);
             temp = temp -> next;
        }

        return;
}

int main(){

  int ch , id , pay;
  char userName[50] , pass[50] ;

  char buy_name[50] , buy_pass[50];

  int buy_ch ;

  while(1){
    printf("1) Admin Login\n");
    printf("2) Register\n");
    printf("3) Login\n");
    printf("4) Logout\n");
    printf("5) See Products\n");
    printf("6) Find Products by Id\n");
    printf("7) Sort by Price\n");
    printf("8) Discount Products\n");
    printf("9) Buy Product\n");
    printf("10) Exit\n");

    printf("\nPlease enter your choice (1-10): ");
    scanf("%d",&ch);

   switch(ch){

      case 1: AdminLogin();
              break;

      case 2: printf("\nPlease enter user name : ");
                getchar();
                scanf("%[^\n]",userName);

              printf("\nPlease enter password : ");
              getchar();
                scanf("%[^\n]",pass);

              if(Register(userName,pass)){

                printf("\n--->>> Registration Successful !!!\n\n");

              }
              else
                printf("\n---->>>>> Registration Failed !!!\n");

              break;

      case 3:  printf("\nPlease enter user name : ");
                getchar();
                scanf("%[^\n]",userName);

              printf("\nPlease enter password : ");
              getchar();
                scanf("%[^\n]",pass);

              if(Login(userName,pass)){

                printf("\n\n--->>> Login Successful <<<---\n\n");
              }

              else
                printf("\n\nInvalid user name or password\n\n");
              break;

      case 4:  printf("\nPlease enter user name : ");
                getchar();
                scanf("%[^\n]",userName);

              printf("\nPlease enter password : ");
                getchar();
                scanf("%[^\n]",pass);

              Logout(userName,pass);

              break;

     case 5: displayItem();
              break;

     case 6: printf("Please enter Id : ");
             scanf("%d",&id);

             FindById(id);
             break;

     case 7 : SortByPrice();
             break;

     case 8: displayQueue();
             break;

     case 9: printf("1) Regular Items\n2) Discount Item\n");
             printf("\nEnter Your Choices : ");
             scanf("%d",&buy_ch);

             switch(buy_ch){

              case 1 : printf("\nPlease enter The product code : ");
                       scanf("%d",&id);

                      int result =  RegularBuy(id);

                      if(result != -1){
                        printf("\nPlease enter your user name : ");
                        getchar();
                        scanf("%[^\n]",buy_name);

                        printf("\nPlease enter your password : ");
                        getchar();
                        scanf("%[^\n]",buy_pass);

                        if(Login(buy_name,buy_pass)){

                            pushDetails();

                        printf("Please pay %dtk : ",result);
                        scanf("%d",&pay);

                        if(pay == result)
                           printf("\n-->> Payment Received.We're processing your order! <<--\n\n");

                        else
                            printf("\n-->> Wrong Amount paid.<<--\n");

                      }else
                        printf("\nNo Account Found\n\n");

                     } else
                        printf("\nInvalid Product Code!!\n");

                       break;

                  case 2: printf("\nPlease enter The product code : ");
                       scanf("%d",&id);

                      int res =  discount_Buyers(id);
                      if(result != -1){

                        printf("\nPlease enter your user name : ");
                        getchar();
                        scanf("%[^\n]",buy_name);

                        printf("\nPlease enter your password : ");
                        getchar();
                        scanf("%[^\n]",buy_pass);

                        if(Login(buy_name,buy_pass)){

                        pushDetails();
                        printf("Please pay %dtk : ",res);
                        scanf("%d",&pay);

                        if(pay == res)
                        printf("\n-->> Payment Received.We're processing your order! <<--\n\n");

                        else
                            printf("\n-->> Wrong Amount paid. <<--\n");

                       } else
                       printf("\nAccount not Found\n\n");

                    }
                       else
                          printf("\nInvalid Product Code!!\n");


                       break;

                   }

                     break;

            case 10:return 0 ;

      default: printf("\nInvalid Choice!!!\n");
               return 0;

  }
 }

    return 0 ;
}
