#include<stdio.h>
#include<stdlib.h>

struct  StudentData {

        char name[30];
        int vize;
        int final;
        int id;
        
        struct StudentData * next;

};

typedef struct StudentData  node;
node *Create, *delete,*add,*delete, *Success,*head;

 void CreatingList() {

    int n;
    int i;
    node*p;

    printf("Enter a N number");
    scanf("%d",&n);

    for (i=0; i<n;i++) {

        if (i==0) {

          head = (node *) malloc(sizeof(node));
          p = head;
        }   
        else {
              p= (node *) malloc(sizeof(node));
              p = p->next;  
        }
        printf("Enter a name");
        scanf("%s",p->name);
        printf("Enter a vize");
        scanf("%d",p->vize);
        printf("Enter a final");
        scanf("%d",p->final);
        printf("Enter a no");
        scanf("%d",p->id);
    }

    p->next = NULL;


 }   
 
node * AddingList() {
    int stdno;
    node *q ,* p;
    node *newMode = (node *) malloc(sizeof(node));
   

    printf("Enter a name");
    scanf("%s",newMode->name);
    printf("Enter a vize");
    scanf("%d",&newMode->vize);
    printf("Enter a final");
    scanf("%d",&newMode->final);
    printf("Enter a no");
    scanf("%d",&newMode->id);

    printf("Choose a place to add to the list");
    scanf("%d",stdno);
    p=head;

    if (stdno == p->id) {
        newMode->next = p;
        head = newMode;
    }
    else {
        
        while(p->next != NULL &&  p->id != stdno ) {
            q= p;
            p= p->next;
    }
        if(p->id== stdno){
            q->next = newMode;
            newMode->next =p;

    }
        else if( p->next == NULL) {
            p->next = newMode;
            newMode->next = NULL;
    }
    
 }
 return head;
}

node * DeletingList() {
    int stdno ;
    node *p,*q;

    p= head;
    scanf("%d",&stdno);

    if (stdno == p->id) { 
        head = p->next;
        free(p);
    }
    else {
        while (p->next != NULL && p->id != stdno ) {
        q=p;
        p= p->next;
        
        }
        if(p->id == stdno) {
            q->next = p->next;
            free(p);
        }
        else if (p->next== NULL) {
            printf("There is no student");
        }
    }
    return head;
}
double CalculateOfSucceess (int vize,int final) {


        return 0.4*vize+ 0.6* final;
}


void CalculateOfSucceeded () {
    double note = 0.0;

    node *p;
    p= head;

    Success= head;
    while (p->next != NULL) 
    {
        p = p->next;

        if(CalculateOfSucceess(p->vize,p->final)>CalculateOfSucceess (Success->vize,Success->final)) {
            Success = p;
        }
    }
    printf("Success  vize is %d and final is %d  and name is %s id  is %d\n",Success->vize,Success->final, Success->name, Success->id);
}

int main()
{
    printf("Welcome to the Student linked list\n");

    int islem;

        printf("Enter  a number to choose what you want to do in System");
        scanf("%d",&islem);

    switch (islem) 
    {
    case 1:
            CreatingList();  
        break;

    case 2:
            DeletingList();
        break;

    case 3:
        AddingList();
        break;    

    case 4:
            CalculateOfSucceeded();
            break;
    
                 
    default:
        printf("Please do enter Correct number 0 to 4\n");
        break;
    }        

    return 0;
}
