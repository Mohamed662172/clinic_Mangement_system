#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "Admin.h"

// App Code
void App(void)
{
  int pwd[3];
  char uName[50];
  u8 Mode;
  char *Esc;
  u8 Id;
  char ch;
  int sel;
  do
  {

    do
    {
      printf("1->User\n");
      printf("2->Admin\n");
      scanf("%u", &Mode);

      switch (Mode)
      {
      case 1:
        
        printf("*******************************************\n\n");
		printf("\n*************   USER MODE   *************\n");
		printf("\n*******************************************\n\n");		
        
        printf("\nSelect Following  Featuer\n1.View patientrecord:\n2. View today's reservations\n");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
          printPatientRecordWithId();

          break;
        case 2:
          printPatientReservedToday();
          break;
        default:
          break;
        }
        break;
      case 2:
		printf("*******************************************\n\n");
		printf("\n*************   ADMIN MODE   *************\n");
		printf("\n*******************************************\n");
        printf("Username: ");
        fflush(stdin); 
        gets(uName); 

        for (int i = 0; i < 3; ++i)
        {
          printf("Password[%d] : ", i);
          fflush(stdin);
          scanf("%d", &pwd[i]);
		          if (1234 == pwd[0] || 1234 == pwd[1] || 1234 == pwd[2])
        {
			break;
		}
        }
        if (1234 == pwd[0] || 1234 == pwd[1] || 1234 == pwd[2])
        {
          adminFeatuers();
        }
        else
        {
          printf("\nWrong in password or Username\ncheck and Try again\n");
          exit(0);
        }
        break;
      default:
        break;
      }

      printf("Change Mode (Y/N)\nPress Any Key To Out\n");
      fflush(stdin);
      scanf("%c", &ch);

    } while ((ch == 'Y' || ch == 'y'||ch == 'N' || ch == 'n'));
    printf("Write Exit to escape from the Program\n");
    scanf("%s", &Esc);

  } while (Esc == "Exit" || Esc == "exit");
  system("exit");
  system("cls");


}
