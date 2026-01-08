#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "header.h"
#include "menu.h"
#include "phoneadd.h"
#include "phonelist.h"
#include "phonesearch.h"
#include "phonesort.h"
#include "phoneupdate.h"

/*
Türkçe-İngilizce Dil Desteği
Regex ile Numara Kontrolü
Farklı Ülke Kodlarını Ekleme 
*/


int main() {
    int choice=0;
    char searchName[20];
    int searchResult=0;

    menu();

    do{
        printf("\n\n Select your action (1-6): ");
        scanf("%d",&choice);
        if(choice > 5 || choice < 1){
            printf("Error, please enter a number!\n");
            system("pause");
            return 0;
        }

        switch(choice){
        case 1: if(phoneAdd()==0){
            printf("Phone number added successfully!");
        }else{
            printf("There was an error when phone number was tried to add.");
        }
                break;

        case 2: if(phoneList()==0){
            printf("\nPhone numbers were listed successfully!\n");
        }else{
            printf("There was an error when phone numbers were tried to add.\n");
        }
                break;

        case 3: printf("Enter the name for search: ");
                scanf("%s",searchName);
                searchResult=phoneSearch(searchName);
                if(searchResult == 0){
                    printf("There are no records.");
                    system("pause");
                    return 0;
                }else{
                    printf("There are %d records.",searchResult);
                }
                break;
        case 4: phoneSort();
                printf("\nPhone numbers are sorted successfully.\n");  
                break;          
        case 5: printf("You will change your record!\n");
                phoneUpdate();
                break;
        case 6: printf("\nYou logged out, have a nice day.\n"); 
                system("pause");
                return 0;
                break;
        default: printf("\nPlease write a number between 1-6\n");
    }
    }while(choice!=6);


    system("pause");
    return 0;
}
