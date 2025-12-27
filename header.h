typedef struct{
    char name[20];
    char lastName[20];
    char phone[11];
}Record;

void menu();
int phoneAdd();
int phoneList();
int phoneSearch(char*);