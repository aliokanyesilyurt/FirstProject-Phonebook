int phoneList(){
    Record currentRecord;

    FILE* fptr;
    fptr=fopen("egitimdata.txt","r");
    if(fptr==NULL){
        return -1;
    }
    printf("\n\n");
    printf("%-20s %-20s %-15s\n", "Name", "Surname", "Phone Number");
    printf("-------------------- -------------------- ---------------\n");
    while(fscanf(fptr, " %[^,],%[^,],%s", currentRecord.name, currentRecord.lastName, currentRecord.phone) == 3){
    printf("%-20s %-20s %-15s\n", currentRecord.name, currentRecord.lastName, currentRecord.phone); 
    }
    fclose(fptr);
    return 0;
}