
char op;
int value1, value2;
scanf("%d%c%d", &value1, &op, &value2);
switch(op){
   case '+': printf("%d", value1 + value2); break;
   case '-': printf("%d", value1 - value2); break;
   case '*': printf("%d", value1 * value2); break;
   case '/':
        if(value2 != 0){
           printf("%d", value1 / value2);
        }else{                              
           printf("Error");
        }
        break;
   case '%':
        if(value2 != 0){
           printf("%d", value1 % value2);
        }else{                              
           printf("Error");
        }
        break;
   default: printf("Error"); break;
}