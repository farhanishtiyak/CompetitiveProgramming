from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

# Function to generate RSA public and private key pair
def generate_key_pair():
    key = RSA.generate(2048)
    public_key = key.publickey().export_key()
    private_key = key.export_key()
    return public_key, private_key

# Function to encrypt the message using the public key
def encrypt(message, public_key):
    cipher = PKCS1_OAEP.new(RSA.import_key(public_key))
    encrypted_message = cipher.encrypt(message)
    return encrypted_message

# Function to decrypt the message using the private key
def decrypt(encrypted_message, private_key):
    cipher = PKCS1_OAEP.new(RSA.import_key(private_key))
    decrypted_message = cipher.decrypt(encrypted_message)
    return decrypted_message

# Main function to handle user input and encryption/decryption
def main():
    # User input: plaintext message
    plaintext = input("Enter the message to encrypt: ").encode()  # Convert input to bytes

    # Generate public and private key pair
    public_key, private_key = generate_key_pair()
    
    # Display the generated keys (for reference)
    print("\n---- Generated RSA Keys ----")
    print("Public Key:\n", public_key.decode())
    print("Private Key:\n", private_key.decode())
    
    # Encrypt the message
    encrypted_message = encrypt(plaintext, public_key)
    print("\n---- Encryption ----")
    print("Plaintext:", plaintext.decode())
    print("Encrypted message (hex):", encrypted_message.hex())

    # Decrypt the message
    decrypted_message = decrypt(encrypted_message, private_key)
    print("\n---- Decryption ----")
    print("Decrypted message:", decrypted_message.decode())

# Run the main function
if __name__ == "__main__":
    main()
