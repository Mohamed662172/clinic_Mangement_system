//admin_mode.h

#ifndef __Admin__
#define __Admin__

#include"Std_Types.h"

typedef struct Patient {

char Name[100];

u8 Age;

char Gender[20];

u64 Id;

char flag[50];

struct Patient *Next;

}infoPatient;

typedef enum
{

        FlageSit,
        FlageRise
} Flage;

void printPatientRecord(void); 
void insertPatient(void); 
void readFile(void); 
void gDeletePatientWithID(void); 
void gDeleteListOfPatient(void); 
void writeToNewFile(void); 
void writeToFile(void);
int gSearchOnNode(int ID);
void editPatientinfo(void);
void dSlotTimeReserve(void);
void dCancleTimeReserve(void);
void printPatientRecordWithId(void);
void printPatientReservedToday(void);

#endif