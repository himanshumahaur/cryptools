# RSA Encryption and Decryption

This Python script demonstrates a basic implementation of RSA encryption and decryption. It allows users to:

- Input prime numbers or select them randomly.
- Generate RSA public and private keys.
- Encrypt and decrypt text messages using the RSA algorithm.
- Handle errors related to modulus size and overflow.

## Features

- **Prime Number Selection:** Use predefined primes or input your own.
- **Key Generation:** Automatically generates encryption and decryption keys.
- **Encryption & Decryption:** Encrypt and decrypt text messages.
- **Error Handling:** Checks for modulus size issues and handles overflow errors.

## How to Use

1. **Run the Script**

   Run the script in your Python environment.

   ```bash
   python RSA.py
   ```

2. **Enter Prime Numbers**

- Enter your own prime numbers for `P` and `Q`, or leave them blank to use random primes from the predefined list.

3. **Enter Message**

- Provide a text message for encryption. The script will encrypt the message and then decrypt it to verify correctness.

4. **Check Results**

- The script will output the encrypted and decrypted messages and indicate whether RSA encryption and decryption were successful.

## Warnings

- **Small Modulus Warning**: Using very small primes may result in a modulus (`N`) that is too small, potentially leading to insufficient security and functional issues.
- **Overflow Error**: Ensure that the primes and messages used do not cause overflow in the calculations.

## License

This project is licensed under the MIT License.
