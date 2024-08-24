# Caesar Cipher

This C++ program implements a basic Caesar cipher for encryption and decryption. It includes features for handling user input and providing colored output for success and error messages.

## Features

- **Caesar Cipher Encryption**: Encrypts messages using the Caesar cipher algorithm.
- **Caesar Cipher Decryption**: Decrypts messages encrypted with the Caesar cipher.
- **Color-coded Messages**: Utilizes ANSI escape codes to display success and error messages in color.
- **Whitespace Preservation**: Maintains spaces in the message during encryption and decryption.

## Components

### 1. Error and Success Handling

- **Error Messages**: Displayed in red to indicate issues, such as invalid input.
- **Success Messages**: Displayed in green to confirm successful operations.

### 2. Encryption and Decryption

- **Encryption Function**: Transforms a message into an encrypted format by shifting characters by a specified key.
- **Decryption Function**: Reverses the encryption process to restore the original message using the same key.
