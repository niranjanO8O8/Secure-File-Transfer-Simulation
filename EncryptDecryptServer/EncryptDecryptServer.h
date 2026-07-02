#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

	__declspec(dllexport)
		int Encrypt_Caesar_Cipher(const char*, const  char*, int);

	__declspec(dllexport)
		int Decrypt_Caesar_Cipher(const char*, const char*, int);

	__declspec(dllexport)
		int Encrypt_XOR_Cipher(const char*, const char*, char);

	__declspec(dllexport)
		int Decrypt_XOR_Cipher(const char*, const char*, char);

#ifdef __cplusplus
}
#endif