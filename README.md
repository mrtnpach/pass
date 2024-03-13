# PASS

<p align="center">
  <img src="https://i.imgur.com/vdth7hs.png" alt="Screenshot"  width=70% height=70%>
</p>

## Compilation

Compile using g++ and the make file found inside the _build_ directory. The latest g++ compiler version used to build the application is 13.2.0. 

The resulting executable can be found inside the _bin_ folder, alongisde the accounts.txt file. Said directory can be then added to your PATH variable on Windows, if wished.

Keep in mind that both _pass.exe_ and _accounts.txt_ must be inside the same directory in order for the application to work.

## How to use

### Accounts

Place your account details in the accounts.txt file inside the _bin_ directory. Each entry must consist of one line inmediately followed by a line-terminating character (new line). Use the following format:
```
username@website=password_length
```
* Usernames and websites can contain letters, numeric digits, symbols and spaces.
* Password lengths must be integer values between 1 and 50.

For example:
```
My_UserName_1@Some Website=25
```
### Commands

First navigate to the executable's directory or add it to yout PATH variable.

* Generate passwords based on _main password_ for all entries in accounts.txt
```
pass.exe [main password]
```
* Generate passwords based on _main password_ for the specified _username_ o _website_
```
pass.exe [main password] [username or website]
```

### Tweaks
Changing the digits bank and other values used for password generation is highly recommended. These can be found in the FirstEncrypter.hpp file inside the _source_ folder. The following values can be tweaked:
```c++
// Digits bank
const char digitsBank
// Values for FirstEncrypter::GenerateSeed
int _customSeed
// Values for FirstEncrypter::GeneratePassword
int _saltConstant
int _rowSelectionSalt
int _columnSelectionSalt
```

The digits bank is a 2D character array that accepts:
* Numeric digits
* Uppercase and lowercase letters
* Symbols

Even though the bank is a 50x20 array out of the box, these dimensions can be modified as well. You can look up a random string generator online to make things way easier.
