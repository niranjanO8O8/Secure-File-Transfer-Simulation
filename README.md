# 🔐 Secure File Transfer Simulation

A C-based Windows application that demonstrates secure file encryption and decryption using **Caesar Cipher** and **XOR Cipher**. The project follows a modular architecture by implementing the encryption logic inside a **Windows DLL** and dynamically loading it in a client application.

---

## 📌 Features

- 🔒 Caesar Cipher Encryption & Decryption
- 🔒 XOR Cipher Encryption & Decryption
- 📂 File-based encryption and decryption
- 📦 Encryption logic packaged inside a reusable DLL
- 🔗 Dynamic loading using `LoadLibrary()` and `GetProcAddress()`
- 🖥️ Menu-driven console application
- ⚡ Modular and reusable design

---

## 🛠️ Technologies Used

- C
- Windows DLL
- Microsoft Visual Studio
- Windows API (`LoadLibrary`, `GetProcAddress`)
- C Runtime File I/O (`_open`, `_read`, `_write`, `_close`)

---

## 📂 Project Structure

```
SecureFileTransferSimulation
│
├── EncryptDecryptServer/
│   ├── EncryptDecryptServer.cpp
│   ├── EncryptDecryptServer.h
│   ├── dllmain.cpp
│   └── EncryptDecryptServer.dll
│
├── EncryptDecryptClient/
│   ├── EncryptDecryptClient.cpp
│   ├── Input.txt
│   ├── Encrypted.txt
│   └── Output.txt
│
└── README.md
```

---

## ⚙️ Working

1. The client application loads the DLL using `LoadLibrary()`.
2. Function addresses are obtained using `GetProcAddress()`.
3. The user selects:
   - Encrypt or Decrypt
   - Caesar Cipher or XOR Cipher
4. The source file is read in chunks.
5. Data is encrypted/decrypted.
6. The processed data is written into a destination file.

---

## 🧠 Encryption Algorithms

### Caesar Cipher

Each byte is shifted by a user-provided integer key.

**Encryption**

```
EncryptedByte = OriginalByte + Key
```

**Decryption**

```
OriginalByte = EncryptedByte - Key
```

---

### XOR Cipher

Each byte is XORed with a user-provided character key.

**Encryption**

```
EncryptedByte = OriginalByte XOR Key
```

**Decryption**

```
OriginalByte = EncryptedByte XOR Key
```

Since XOR is reversible, the same operation is used for both encryption and decryption.

---

## ▶️ How to Run

### 1. Build the DLL

Build the **EncryptDecryptServer** project to generate:

```
EncryptDecryptServer.dll
```

---

### 2. Copy DLL

Copy the generated DLL into the client executable directory.

---

### 3. Build Client

Build and run the **EncryptDecryptClient** project.

---

### 4. Menu

```
=========================================
      Secure File Transfer Simulation
=========================================

1. Encrypt File
2. Decrypt File
3. Exit
```

Choose:

- Encryption / Decryption
- Caesar / XOR
- Source File
- Destination File
- Key

---

## 📁 Example

Input File

```
Hello World
```

↓

Encrypt

↓

```
Encrypted.txt
```

↓

Decrypt

↓

```
Output.txt
```

The decrypted output matches the original input file.

---

## 📚 Concepts Demonstrated

- Dynamic Link Libraries (DLL)
- Dynamic Linking
- Function Pointers
- File Handling
- Cryptography Basics
- Modular Programming
- Buffer-based File Processing

---

## 🚀 Future Improvements

- Replace Caesar/XOR with AES encryption
- Implement Win32 file APIs (`CreateFile`, `ReadFile`, `WriteFile`, `CloseHandle`)
- Add TCP/IP socket-based file transfer
- Develop a GUI version
- Add password-based key generation
- Improve exception handling and logging

---

## 👨‍💻 Author

**Niranjan Khaire**

Bachelor of Engineering (Electronics & Telecommunication)

Passionate about C/C++, Java, System Programming, and Software Development.

---

## 📄 License

This project is developed for educational purposes and to demonstrate concepts of cryptography, file handling, DLL programming, and modular software design.
