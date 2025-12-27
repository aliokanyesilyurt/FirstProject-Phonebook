int phoneAdd(){
    Record newRecord;

    FILE* fptr;
    fptr=fopen("egitimdata.txt","a");
    if(fptr==NULL){
        return -1;
    }
    printf("\n\n");
    while(1){
    while ((getchar()) != '\n');
    printf("Enter a name: ");
    gets(newRecord.name);
    if(strlen(newRecord.name) > 20){
        printf("Enter max 20 characters!");
        continue;
    }
    printf("Enter a surname: ");
    gets(newRecord.lastName);
        if(strlen(newRecord.lastName) > 20){
        printf("Enter max 20 characters!");
        continue;
    }
    printf("Enter phone number: ");
    gets(newRecord.phone);
        if(strlen(newRecord.phone) > 11){
        printf("Enter max 11 numbers!");
        continue;
    }
    fprintf(fptr, "%s,%s,%s\n", newRecord.name, newRecord.lastName, newRecord.phone);
    printf("Record added successfully!\n");
    break; 
    }

    fclose(fptr);
    return 0; 
}
