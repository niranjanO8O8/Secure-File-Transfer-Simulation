#include "pch.h"    //pre compiler header
#include<windows.h>
#include "EncryptDecryptServer.h"
#include<stdio.h>
#include<stdlib.h> 
#include<fcntl.h>
#include <io.h>

#define MAX_SIZE 1024


//Caesar Cipher Encryption
extern "C" __declspec(dllexport) int Encrypt_Caesar_Cipher(const char* Src, const char* Dest, int Key)     //in VS for dll
{
    int fdSrc = 0, fdDest = 0;
    char Buffer[MAX_SIZE] = { '\0' };
    int iRet = 0, i = 0;

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to Open Source File.\n");
        return -1;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        printf("Unable to Create Destination File.\n");
        return -1;
    }

    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] + Key) % 256;
        }
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);

    return 0;

}

//Caesar Cipher Decryption
extern "C" __declspec(dllexport) int Decrypt_Caesar_Cipher(const char* Src, const char* Dest, int Key)     //in VS for dll
{
    int fdSrc = 0, fdDest = 0;
    char Buffer[MAX_SIZE] = { '\0' };
    int iRet = 0, i = 0;

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to Open Source File.\n");
        return -1;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        printf("Unable to Create Destination File.\n");
        return -1;
    }

    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] - Key) % 256;
        }
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);

    return 0;
}

// XOR 
extern "C" __declspec(dllexport) int Encrypt_XOR_Cipher(const char* Src, const char* Dest, char Key)     //in VS for dll
{
    int fdSrc = 0, fdDest = 0;
    char Buffer[MAX_SIZE] = { '\0' };
    int iRet = 0, i = 0;

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to Open Source File.\n");
        return -1;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        printf("Unable to Create Destination File.\n");
        return -1;
    }

    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ Key;
        }
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);

    return 0;

}

extern "C" __declspec(dllexport) int Decrypt_XOR_Cipher(const char* Src, const char* Dest, char Key)     //in VS for dll
{
    int fdSrc = 0, fdDest = 0;
    char Buffer[MAX_SIZE] = { '\0' };
    int iRet = 0, i = 0;

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to Open Source File.\n");
        return -1;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        printf("Unable to Create Destination File.\n");
        return -1;
    }

    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ Key;
        }
        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);

    return 0;

}

// this application should create EncryptDecryptServer.dll
// dllmain.cpp file keep it as it is 