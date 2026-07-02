// EncryptDecryptClient.cpp file contents
#include<windows.h>
//#include "pch.h"    //pre compiler header
#include<stdio.h>
#include<stdlib.h> 
#include<fcntl.h>

typedef int (*Caesar)(const char*, const char*, int);
typedef int (*XOR)(const char*, const char*, char);


int main()
{
    HINSTANCE hdll = LoadLibraryA("EncryptDecryptServer.dll");

    if (hdll == NULL)
    {
        printf("Unable to load Library : EncryptDecryptServer.dll\n");
        return -1;
    }

    // Get Function addresses
    Caesar EncryptCaesar = (Caesar)GetProcAddress(hdll, "Encrypt_Caesar_Cipher");
    Caesar DecryptCaesar = (Caesar)GetProcAddress(hdll, "Decrypt_Caesar_Cipher");

    XOR EncryptXOR = (XOR)GetProcAddress(hdll, "Encrypt_XOR_Cipher");
    XOR DecryptXOR = (XOR)GetProcAddress(hdll, "Decrypt_XOR_Cipher");


    if (EncryptCaesar == NULL || DecryptCaesar == NULL || EncryptXOR == NULL || DecryptXOR == NULL)
    {
        printf("Unable to get address of function\n");
        FreeLibrary(hdll);
        return -1;
    }

    int mainChoice = 0;
    int algorithmChoice = 0;

    char srcName[100];
    char destName[100];

    int caesarKey;
    char xorKey;

    while (1)
    {
        printf("\n=========================================\n");
        printf("      Secure File Transfer Simulation\n");
        printf("=========================================\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("3. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d", &mainChoice);

        if (mainChoice == 3)
        {
            break;
        }

        printf("\n=========================================\n");
        printf("\nChoose Algorithm\n");
        printf("\n=========================================\n");
        printf("1. Caesar Cipher\n");
        printf("2. XOR Cipher\n");
        printf("-----------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d", &algorithmChoice);

        printf("Enter Source File (without .txt): ");
        scanf("%s", srcName);

        strcat_s(srcName, ".txt");

        printf("Enter Destination File (without .txt): ");
        scanf("%s", destName);

        strcat_s(destName, ".txt");


        printf("\nSource      : %s\n", srcName);
        printf("Destination : %s\n", destName);


        switch (mainChoice)
        {
            case 1:     // Encrypt

                if (algorithmChoice == 1)
                {
                    printf("Enter Caesar Key : ");
                    scanf("%d", &caesarKey);

                    if (EncryptCaesar(srcName, destName, xorKey) == 0)
                    {
                        printf("Encryption Successful.\n");
                    }
                    else
                    {
                        printf("Encryption Failed.\n");
                    }

                }
                else if (algorithmChoice == 2)
                {
                    printf("Enter XOR Key (single character): ");
                    scanf(" %c", &xorKey);

                    if (EncryptXOR(srcName, destName, xorKey) == 0)
                    {
                        printf("Encryption Successful.\n");
                    }
                    else
                    {
                        printf("Encryption Failed.\n");
                    }
                }
                else
                {
                    printf("Invalid Algorithm!! Please enter the valid option.\n");
                }

                break;

            case 2:     // Decrypt

                    if (algorithmChoice == 1)
                    {
                        printf("Enter Caesar Key : ");
                        scanf("%d", &caesarKey);

                        if (EncryptCaesar(srcName, destName, xorKey) == 0)
                        {
                            printf("Decryption Successful.\n");
                        }
                        else
                        {
                            printf("Decryption Failed.\n");
                        }
                    }
                    else if (algorithmChoice == 2)
                    {
                        printf("Enter XOR Key (single character): ");
                        scanf(" %c", &xorKey);

                        if (EncryptXOR(srcName, destName, xorKey) == 0)
                        {
                            printf("Decryption Successful.\n");
                        }
                        else
                        {
                            printf("Decryption Failed.\n");
                        }
                    }
                    else
                    {
                        printf("Invalid Algorithm!! Please enter the valid option.\n");
                    }

                    break;

                    default:
                        printf("Invalid Choice!! Please enter the valid option.\n");
        }
    }


    FreeLibrary(hdll);

    printf("=========================================\n");
    printf("Thank u for using our Application.\n");
    printf("=========================================\n");

    return 0;
}

// this application should use EncryptDecryptClient.dll
// this .dll should be placed in x64/debug

// this is the client which uses the dll and access the functionality 