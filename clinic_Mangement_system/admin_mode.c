#include <stdio.h>
#include <stdlib.h>
#include "Admin.h"
#include <string.h>

infoPatient *PatientRecord = NULL;
infoPatient *NewRecord = NULL;
static int iReturn = 0;

int gSearchOnNode(int ID)
{

        int iRetValue = FlageSit;

        infoPatient *pTemp = PatientRecord;
        infoPatient *Prev;

        while (pTemp != NULL)
        {
                Prev = pTemp;

                //finding the certain data
                if (pTemp->Id == ID)
                {
                        iReturn = FlageRise;
                        ++iRetValue;
                        return iRetValue;
                }

                pTemp = pTemp->Next;
        }
        iReturn = FlageSit;
        return (-1);
}
void printPatientRecord(void)
{
        infoPatient *pTemp = PatientRecord;
        while (pTemp != NULL)
        {
                printf("Name of Patient: %s\n", pTemp->Name);

                printf("Age of Patient: %d\n", pTemp->Age);
                fflush(stdout);
                printf("Gender of Patient:%s\n", pTemp->Gender);

                printf("Id of Patient: %d\n", pTemp->Id);
                fflush(stdout);
                printf("Slot Time of Patient: %s\n", pTemp->flag);

                pTemp = pTemp->Next;
        }
}
void printPatientRecordWithId(void)
{
        int key;
        int count = 0;
        printf("Id of Patient:\n");
        scanf("%d", &key);
        gSearchOnNode(key);
        infoPatient *pTemp = PatientRecord;

        if (iReturn == 1)
        {
                printf("Name of Patient: %s\n", pTemp->Name);

                printf("Age of Patient: %d\n", pTemp->Age);
                fflush(stdout);
                printf("Gender of Patient:%s\n", pTemp->Gender);

                printf("Id of Patient: %d\n", pTemp->Id);
                fflush(stdout);
                printf("Slot Time of Patient: %s\n", pTemp->flag);
        }
}
void printPatientReservedToday(void)
{

        infoPatient *pTemp = PatientRecord;

        while (pTemp != NULL)
        {

                fflush(stdout);
                printf("\n\nSlot Time of Patient: %s\nPatient ID is %d\n", pTemp->flag, pTemp->Id);

                pTemp = pTemp->Next;
        }
}
void writeToNewFile(void)
{
        FILE *fptr;
        fptr = fopen("PatientNewRecord.txt", "w");
        infoPatient *pTemp = PatientRecord;

        if (fptr == NULL)
        {
                printf("Error\n");
        }

        else
        {
                while (pTemp != NULL)
                {
                        fprintf(fptr, "\nPatient Name: %s\nPatient Age: %d\nPatient Gender : %s\nPatient ID : %d\nPatient Slot: %s\n", pTemp->Name, pTemp->Age, pTemp->Gender, pTemp->Id, pTemp->flag);
                        pTemp = pTemp->Next;
                }
        }

        fclose(fptr);
}

void writeToFile(void)
{
        FILE *fptr;
        fptr = fopen("PatientRecord.txt", "aw");
        infoPatient *pTemp = PatientRecord;

        if (fptr == NULL)
        {
                printf("Error\n");
        }

        else
        {
                while (pTemp != NULL)
                {
                        fprintf(fptr, "\nPatient Name: %s\nPatient Age: %d\nPatient Gender : %s\nPatient ID : %d\nPatient Slot: %s\n", pTemp->Name, pTemp->Age, pTemp->Gender, pTemp->Id, pTemp->flag);
                        pTemp = pTemp->Next;
                }
        }

        fclose(fptr);
}
void insertPatient(void)
{

        int count;
        int ID;
        printf("How many patient do you have? ");
        scanf("%d", &count);

        for (int i = 0; i < count; i++)
        {
                if (i == 0)
                {
                        PatientRecord = malloc(sizeof(infoPatient));
                        NewRecord = PatientRecord;
                }
                else
                {
                        NewRecord->Next = malloc(sizeof(infoPatient));
                        NewRecord = NewRecord->Next;
                }
                // NewRecord->Name = malloc(50 * sizeof(char));
                //NewRecord->Gender = malloc(20*sizeof(char));
                fflush(stdin);

                printf("Name of Patient: ");
                gets(NewRecord->Name);

                fflush(stdin);
                printf("Age of Patient: ");
                scanf("%d", &NewRecord->Age);
                fflush(stdin);
                printf("Gender of Patient: ");
                gets(NewRecord->Gender);

                printf("Id of Patient: ");
                scanf("%d", &ID);
                gSearchOnNode(ID);
                if (iReturn == 1)
                {

                        printf("The ID of User Exist\n");
                        insertPatient();
                        printf("Enter Id of Patient: ");
                        scanf("%d", &NewRecord->Id);
                }
                else
                {
                        NewRecord->Id = ID;
                }
        }
        NewRecord->Next = NULL;
        printf("\n\n");
}
void gDeleteListOfPatient(void)
{
        /* deref gHead to get the real gCurrent */
        infoPatient *current = PatientRecord;
        infoPatient *next;

        while (current != NULL)
        {
                next = current->Next;
                free(current);
                current = next;
        }

        PatientRecord = NULL;
}
void gDeletePatientWithID(void)
{
        int key;
        printf("Id of Patient:\n");
        scanf("%d", &key);

        int pos = gSearchOnNode(key);
        //printf("%d",pos);
        if (PatientRecord == NULL)
        {
                return;
        }
        //temp to store head
        infoPatient *pTemp = PatientRecord;
        //Delete head node
        if (pos == 1)
        {
                PatientRecord = pTemp->Next;
                free(pTemp);

                return;
        }
        //store previous of to be deleted node
        for (int i = 0; pTemp != NULL && i < pos - 1; i++)
        {
                pTemp = pTemp->Next;
        }
        if (pTemp == NULL || pTemp->Next == NULL)
        {
                return;
        }
        //delete node at pos (next of pos-1)
        infoPatient *next = pTemp->Next->Next;
        free(pTemp->Next);
        pTemp->Next = next;
}
void readFile(void)
{

        FILE *fptr;

        char filename[100], c;

        printf("Enter the filename to open \n");
        scanf("%s", filename);

        // Open file
        fptr = fopen(filename, "r");
        if (fptr == NULL)
        {
                printf("Cannot open file \n");
                exit(0);
        }

        // Read contents from file
        c = fgetc(fptr);
        while (c != EOF)
        {
                printf("%c", c);
                c = fgetc(fptr);
        }

        fclose(fptr);
}

//Edit patient record

void editPatientinfo(void)
{
        int Key;
        int Sel;
        char ch;

        NewRecord = PatientRecord;

        do
        {
                printf("Please Enter ID of User to Modify:\n");
                scanf("%d", &Key);
                gSearchOnNode(Key);
                if (iReturn == 1)
                {
                        //gDeletePatientWithID(Key);

                        /*if (Key == 1)
                        {
                                PatientRecord = malloc(sizeof(infoPatient));
                                NewRecord = PatientRecord;
                        }
                        else
                        {
                                NewRecord->Next = malloc(sizeof(infoPatient));
                                NewRecord = NewRecord->Next;
                        }*/
                        printf("Which info of Patient You Want To Modify?\n1-Name\n2-Age\n3-Gender\n");
                        scanf("%d", &Sel);
                        switch (Sel)
                        {
                        case 1:

                                printf("Name of Patient: ");
                                fflush(stdin);

                                gets(NewRecord->Name);
                                break;
                        case 2:
                                printf("Age of Patient: ");
                                fflush(stdin);

                                scanf("%d", &NewRecord->Age);
                                break;
                        case 3:
                                printf("Gender of Patient: ");
                                fflush(stdin);

                                gets(NewRecord->Gender);
                                break;

                        default:
                                break;
                        }
                        fflush(stdin);

                        NewRecord->Id = Key;
                }

                else
                {
                        printf("Invalid Id\n");
                }

                NewRecord = NewRecord->Next;
                printf("\n\n");
                printf("Modify another Id (Y/N): \n");
                fflush(stdin);

                scanf("%c", &ch);

        } while(ch == 'Y' || ch == 'y');
}

//  dSlotTimeReserve

char Arr[5][100] = {
	"1-Slot From 02:00pm to 02:30pm",
	"2-Slot From 02:30pm to 03:00pm",
	"3-Slot From 03:30pm to 04:00pm",
	"4-Slot From 04:00pm to 04:30pm", 
	"5-Slot From 04:30pm to 05:00pm"};
Flage sFlage = FlageSit;

void dSlotTimeReserve(void)
{
        char c;
        int sel;
        int ID;
        NewRecord = PatientRecord;
        printf("\n\n\nAvailabe Time !!\n\n\n");

        do
        {

                for (int i = 0; i < 5; ++i)
                {
                        printf("%s\n", Arr[i]);
                }
                scanf("%d", &sel);
                printf("Id of Patient: ");
                scanf("%d", &ID);
                gSearchOnNode(ID);

                switch (sel)
                {
                case 1:
                        if (iReturn == 1)
                        {
                                strcpy(NewRecord->flag, Arr[0]);
                                printf("The Patient is Reserved Time  WEll\n%s", Arr[0]);
                                sFlage = FlageRise;
                                for (int k = 0; k < 100; ++k)
                                {

                                        Arr[0][k] = '\0';
                                }
                        }
                        else
                        {
                                printf("\n\n Invalid Id\nCheck Patient Id And Try Again\n\n");
                        }
                        break;
                case 2:

                        if (iReturn == 1)
                        {
                                strcpy(NewRecord->flag, Arr[1]);
                                printf("\n%d\n", NewRecord->Id);
                                printf("%s\n", NewRecord->flag);

                                printf("The Patient is Reserved Time  WEll\n%s", Arr[1]);
                                sFlage = FlageRise + 1;

                                for (int k = 0; k < 100; ++k)
                                {

                                        Arr[1][k] = '\0';
                                }
                        }
                        else
                        {
                                printf("\n\n Invalid Id\nCheck Patient Id And Try Again\n\n");
                        }
                        break;
                case 3:

                        if (iReturn == 1)
                        {
                                strcpy(NewRecord->flag, Arr[2]);
                                printf("The Patient is Reserved Time  WEll\n%s", Arr[2]);
                                sFlage = FlageRise + 2;

                                for (int k = 0; k < 100; ++k)
                                {

                                        Arr[2][k] = '\0';
                                }
                        }
                        else
                        {
                                printf("\n\n Invalid Id\nCheck Patient Id And Try Again\n\n");
                        }

                        break;
                case 4:

                        if (iReturn == 1)
                        {

                                strcpy(NewRecord->flag, Arr[3]);
                                printf("The Patient is Reserved Time  WEll\n%s", Arr[3]);
                                sFlage = FlageRise + 3;

                                for (int k = 0; k < 100; ++k)
                                {

                                        Arr[3][k] = '\0';
                                }
                        }
                        else
                        {
                                printf("\n\n Invalid Id\nCheck Patient Id And Try Again\n\n");
                        }

                        break;
                case 5:

                        if (iReturn == 1)
                        {
                                strcpy(NewRecord->flag, Arr[4]);
                                printf("The Patient is Reserved Time  WEll\n%s", Arr[4]);
                                sFlage = FlageRise + 4;

                                for (int k = 0; k < 100; ++k)
                                {

                                        Arr[4][k] = '\0';
                                }
                        }
                        else
                        {
                                printf("\n\n Invalid Id\nCheck Patient Id And Try Again\n\n");
                        }

                        break;
                default:

                        break;
                }
                NewRecord = NewRecord->Next;
                printf("\n\nAdd another Reserverd? (Y/N): ");

                scanf(" %c", &c); //skip leading whitespace

        } while (c == 'Y' || c == 'y');
}
void printArr(int start)
{
        for (int i = start; i < 5; ++i)
        {
                printf("%s\n", Arr[i]);
        }
}
void dCancleTimeReserve(void)
{

        int cID;
        char c;

        NewRecord = PatientRecord;
        do
        {
                printf("Id of Patient: ");
                scanf("%d", &cID);
                gSearchOnNode(cID);
                if (iReturn == 1)
                {
                        if (strcmp(NewRecord->flag, Arr[0]) == 0)
                        {
                                NewRecord->flag[0] = '\0';
                        }
                        if (strcmp(NewRecord->flag, Arr[1]) == 0)
                        {
                                NewRecord->flag[1] = '\0';
                        }
                        if (strcmp(NewRecord->flag, Arr[2]) == 0)
                        {
                                NewRecord->flag[2] = '\0';
                        }
                        if (strcmp(NewRecord->flag, Arr[3]) == 0)
                        {
                                NewRecord->flag[3] = '\0';
                        }
                        if (strcmp(NewRecord->flag, Arr[4]) == 0)
                        {
                                NewRecord->flag[4] = '\0';
                        }

                        printf("The Patient is Cancled  WEll\n");
                }
                else
                {
                        printf("\n\n Invalid Id\nCheck Patient Id And Try Again\n\n");
                }
                printf("\n\n\nAvailabe Time !!\n\n\n");

                printArr(sFlage);

                NewRecord = NewRecord->Next;
                printf("\n\nCancle another Reserverd? (Y/N): ");
                scanf(" %c", &c);
        } while (c == 'Y' || c == 'y');
}
