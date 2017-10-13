#Makefile for linked list files.

.PHONY : all clean

ROOT=C:\Users\smd\Documents\visteon_backup\porsh
ROOT_SRC=$(ROOT)\test_harness\src

#RTE related
INC_RTE=$(ROOT)\Rte\Rte_G2
INC_RTE_COMPONENTS=$(ROOT)\Rte\Rte_G2\Components

SRC_APPL=$(ROOT)\sip_gendata\Application
SRC_CD=$(ROOT)\mcal\ComplexDrv\src

#local
INC_LOCAL=$(ROOT)\test_harness\inc
#Compiler relared
INC_COMMONS=$(ROOT)\sip\_Common
#Gendata
INC_GENDATA_G2=$(ROOT)\sip_gendata\gendata_G2
INC_GENDATA_G2_INC=$(ROOT)\sip_gendata\gendata_G2\include
INC_GENDATA_APPL=$(ROOT)\sip_gendata\Application
#SIP
INC_SIP_SPI=$(ROOT)\sip\Spi
INC_SIP_PORT=$(ROOT)\sip\Port
INC_SIP_DIO=$(ROOT)\sip\Dio
INC_SIP_PWM=$(ROOT)\sip\Pwm
INC_SIP_ADC=$(ROOT)\sip\Adc
INC_SIP_COM=$(ROOT)\sip\Com
INC_SIP_DET=$(ROOT)\sip\Det
INC_SIP=-I$(INC_SIP_SPI) -I$(INC_SIP_PORT) -I$(INC_SIP_DIO) -I$(INC_SIP_PWM) -I$(INC_SIP_ADC) -I$(INC_SIP_COM) -I$(INC_SIP_DET)
#MCAL
INC_MCAL_SELF=$(ROOT)\mcal
INC_CMPLIB=$(ROOT)\mcal\Lib
INC_CD=$(ROOT)\mcal\ComplexDrv\inc
INC_MCAL=-I$(INC_CMPLIB) -I$(INC_CD) -I$(INC_MCAL_SELF)

INC=-I$(INC_RTE) -I$(INC_RTE_COMPONENTS) -I$(INC_COMMONS) -I$(INC_LOCAL) -I$(INC_GENDATA_G2) -I$(INC_GENDATA_APPL) -I$(INC_GENDATA_G2_INC) $(INC_SIP) $(INC_MCAL)


SRC=src\linked_list.c linked_list_test.c $(SRC_APPL)\CtHWSWC_Displays.c $(SRC_CD)\ComplexDrv_PowerDisplay.c $(SRC_CD)\ComplexDrv_Timer.c $(ROOT_SRC)\feed_CtHWSWC_Displays.c  $(INC_CMPLIB)\LibCmp.c $(SRC_CD)\ComplexDrv_PowerGeneric.c
OBJ=$(SRC:.c=.o) # replaces the .c from SRC with .o
EXE=linked_list

CC=gcc
#CFLAGS=-c -Wall -O3
CFLAGS=-c -O3
LDFLAGS=
RM=rm

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(INC) $(CFLAGS) $< -o $@ 
#> gccmsg.txt 2>&1

$(ROOT_SRC)\%.o: $(ROOT_SRC)\%.c
	$(CC) $(INC) $(CFLAGS) $< -o $@ 

clean:
	-$(RM) $(OBJ) $(EXE)
