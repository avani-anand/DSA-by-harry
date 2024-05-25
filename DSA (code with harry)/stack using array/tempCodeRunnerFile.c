-1;
s->arr=(int *)malloc(s->size* sizeof(int));
printf("stack has been created \n");

printf("before pushing , full :%d\n",isFull(s));
printf("before pushing , Empty :%d\n",isEmpty(s));
push(s, 34535);
push(s, 345);