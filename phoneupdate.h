void phoneUpdate(){
    Record temp[100];
    FILE *ptr;
    int i,a=0,b=0;
    int found=0;
    int select;
    char searchname[20];

    ptr=fopen("egitimdata.txt","r");

    if(ptr==NULL){
        printf("An error was happened while the file was opening.\n");
        return;
    }

    while(fscanf(ptr," %[^,],%[^,],%s",temp[a].name,temp[a].lastName,temp[a].phone)==3){
        a++;
    }
    fclose(ptr);

    while(getchar()!='\n');
    printf("Please enter your searched name: ");
    gets(searchname);

    for(i=0;i<a;i++){
        if(strcmp(temp[i].name,searchname)==0){
            found=1;
            printf("---\nWhich one do you change? \n1- Phone \n2- Name \n3- Surname\n---\n");
            scanf("%d",&select);
            while(getchar()!='\n');

            switch(select){
                case 1: printf("Enter new phone number: ");
                        gets(temp[i].phone);
                        break;
                case 2: printf("Enter new name: ");
                        gets(temp[i].name);
                        break;
                case 3: printf("Enter new surname: ");
                        gets(temp[i].lastName);
                        break;
            }
    }
}
    if(found == 0){
        printf("Name not found!\n");
        return; 
    }

    ptr=fopen("egitimdata.txt","w");

    for(b=0;b<a;b++){
    fprintf(ptr,"%s,%s,%s\n",temp[b].name,temp[b].lastName,temp[b].phone);
    }
    fclose(ptr);

    printf("Record updated succesfully!\n");
}