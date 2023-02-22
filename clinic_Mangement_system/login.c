#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "Admin.h"

struct user
{
        char username[50];
        char password[50];
} * pUser;

void userlogin(void)
{
        FILE *fp;
        char uName[50], pwd[50];
        int i;
        char c ,ch;

        pUser = (struct user *)malloc(sizeof(struct user));

        printf("1. Login Through An Existing Account\n2. Create New account\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
                if ((fp = fopen("user.dat", "r+")) == NULL)
                {
                        if ((fp = fopen("user.dat", "w+")) == NULL)
                        {
                                printf("Could not open file\n");
                                exit(1);
                        }
                }
                printf("Username: ");
                fflush(stdin);
                gets(uName);

                for (int i = 0; i < 3; ++i)
                {
                        printf("Password[%d] : ", i);
                        gets(pwd);
                }
                while (fread(pUser, sizeof(struct user), 1, fp) == 1)
                {
                        if ((strcmp(pUser->username, uName) == 0) && (strcmp(pUser->password, pwd) == 0))
                        {
                               printf("Match username\n");
                               printf("Match password\n");
                                        
                        }
                        else{
                                printf("\nWrong in password or Username\ncheck and Try again\n");
                                exit(0);
                        }

                }
                break;

        case 2:
                do
                {
                        if ((fp = fopen("user.dat", "a+")) == NULL)
                        {
                                if ((fp = fopen("user.dat", "w+")) == NULL)
                                {
                                        printf("Could not open file\n");
                                        exit(1);
                                }
                        }

                        printf("Choose A Username: ");
                        fflush(stdin);
                        gets(pUser->username);
                        for (int j = 0; j < 3; ++j)
                        {
                                printf("Choose A Password [%d]: ", j);
                                gets(pUser->password);

                        }
                        
                        
                        fwrite(pUser, sizeof(struct user), 1, fp);
                        printf("Add another account? (Y/N): ");
                        scanf(" %c", &c); //skip leading whitespace
                } while (c == 'Y' || c == 'y');
                break;
        }

        free(pUser); //free allocated memory
        fclose(fp);
        printf("\n*** Please Login In System ***\nPress(Y/N)");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch == 'Y' || ch == 'y'){
                userlogin();
        }
        else
        {
                exit(0);
        }
}
void adminFeatuers(void)
{
        char c;
        int Menu;
        int Id;

        do
        {
                printf("\nSelect Following  Featuer\n");
                printf("1.Add new patient record:\
				\n2.Edit patient record:\
				\n3.Reserve a slot with the doctor:\
				\n4.Cancel reservation:\
				\n5.Delete Patient With Id:\
				\n6.Write Data (append File) in File:\
				\n7.Write Data New file:\
				\n8.Delete All List of patient:\
				\n9.Read File:\
				\n10.Search on Patient:\n");
                scanf("%d", &Menu);
                switch (Menu)
                {
                case 1:
                        insertPatient();
                        break;
                case 2:
                        editPatientinfo();
                        break;
                case 3:
                        dSlotTimeReserve();
                        break;
                case 4:
                        dCancleTimeReserve();
                        break;
                case 5:
                        gDeletePatientWithID();
                        break;
                case 6:
                        writeToFile();
                        break;
                case 7:
                        writeToNewFile();
                        break;
                case 8:
                        gDeleteListOfPatient();
                        break;
                case 9:
                        readFile();
                        break;
                case 10:
                        printf("Please enter Id");
                        scanf("%d", &Id);
                        if (gSearchOnNode(Id) == 1)
                                printf("The Patient is Listed \n");
                        else
                                printf("The Patient is Not Listed \nCheck your Id And Try Again\n ");

                        break;
                default:
                        break;
                }
                fflush(stdin);
                printf("\n\nDo You Want To Chose Onther Operation? (Y/N): ");
                scanf(" %c", &c);
        } while (c == 'Y' || c == 'y');
}

