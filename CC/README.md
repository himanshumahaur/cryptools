# Caesar Cipher

This section of the repository contains flexible C++ code related to the Caesar cipher algorithm. It includes implementations for encryption, decryption, and analysis.

## Implementations

| **Implementation**                      | **Description**                                                                                          |
|----------------------------------------|----------------------------------------------------------------------------------------------------------|
| **Caesar Cipher Encryption and Decryption** | Implements Caesar cipher for encrypting and decrypting messages. Includes color-coded success and error messages, and preserves whitespace. |
| **Frequency Analysis**                  | Analyzes character frequencies in encrypted messages to estimate the most likely encryption key.         |
| **Dictionary Attack**                   | Uses a predefined dictionary of common words to estimate the encryption key by comparing decrypted messages with known words. |

## Encryption and Decryption

This implementation provides functionality for both encrypting and decrypting messages using the Caesar cipher technique. 

### Features

- **Encryption**: Transforms a message into an encrypted format by shifting characters according to a specified key. Non-alphabetic characters are preserved as spaces.
- **Decryption**: Reverses the encryption process to restore the original message using the same key. Non-alphabetic characters are preserved as spaces.
- **Whitespace Preservation**: Spaces in the original message are maintained during encryption and decryption.

### Functions

- **`encr(string msg, int key)`**: Encrypts a given message by shifting characters by the specified key.
- **`decr(string cip, int key)`**: Decrypts an encrypted message by reversing the shift with the same key.

### Error Handling

- **Error Messages**: Displays in red to indicate issues such as invalid input or other errors.
- **Success Messages**: Displays in green to confirm successful operations.

### Usage

1. **Compile the Code**: Use a C++ compiler to compile the provided code files.
2. **Run the Program**: Execute the compiled program. You will be prompted to enter a message and a key for encryption or decryption.

## Frequency Analysis

This implementation focuses on analyzing the frequency of characters in an encrypted message to estimate the most likely key used for encryption. It includes:

- **Frequency Analysis**: Computes the frequency distribution of letters in the encrypted message and compares it with standard English letter frequencies.
- **Key Estimation**: Determines the most likely key by comparing the frequency distributions.

## Dictionary Attack

This implementation employs a dictionary attack strategy to estimate the Caesar cipher key:

- **Decryption and Dictionary Matching**: The program decrypts the encrypted message using all possible Caesar cipher keys (0 to 25) and compares the results with a predefined dictionary of common words to identify the key that produces the most meaningful output.

- **Key Estimation**: The key corresponding to the decrypted message with the highest number of matching dictionary words is considered the most likely encryption key.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
