
#include <stdio.h>

#include "LinkedStack.h"
#include "LinkedStack.c" 
#include "Item.h"
 
int main (void)
{
    int choice;
    int option = 1;
	stack mainStack;
	char mainString[40]="";
 
    printf ("STACK OPERATION\n");
	initialize(&mainStack);
    while (option)
    {
        printf ("------------------------------------------\n");
        printf ("      1    -->    PUSH\n");
        printf ("      2    -->    POP\n");
        printf ("      3    -->    DISPLAY  \n");
        printf ("      4    -->    PEAK\n");
		printf ("      5    -->    IS EMPTY\n");
        printf ("      6    -->    PEAK\n");
		printf ("      7    -->    EXIT\n");
		printf ("      Size:%d\n",mainStack.size);
        printf ("------------------------------------------\n");
 
        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
			scanf("%s",mainString);
            push(&mainStack,mainString);
            break;
        case 2:
			pop(&mainStack,mainString);
			printf("Pop Returned: %s",mainString);
            break;
        case 3:
            display(&mainStack);
            break;
        case 4:
			peek(&mainStack,mainString);
			printf("Peek Returned: %s",mainString);
			break;
       case 5:
			is_empty(&mainStack);
			
			break;
		case 6:
			printf("Length: %d\n",get_length(&mainStack));
			break;
        }
        fflush (stdin); //clears buffer
        printf ("\nDo you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option);
    }
}
