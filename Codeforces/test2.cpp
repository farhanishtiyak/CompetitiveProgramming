#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

// Function to find the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;  // Return -1 if no modular inverse exists
}

// Function to compute the determinant of a matrix (modulo 26)
int determinant(const vector<vector<int>>& matrix, int mod) {
    int det = 0;
    int n = matrix.size();
    if (n == 1) return matrix[0][0];
    
    for (int i = 0; i < n; i++) {
        vector<vector<int>> submatrix;
        for (int j = 1; j < n; j++) {
            vector<int> row;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    row.push_back(matrix[j][k]);
                }
            }
            submatrix.push_back(row);
        }
        det += ((i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix, mod)) % mod;
        det = (det + mod) % mod;
    }
    return det;
}

// Function to calculate the inverse of a matrix modulo 26
vector<vector<int>> matrixInverse(const vector<vector<int>>& matrix, int mod) {
    int det = determinant(matrix, mod);
    int detInv = modInverse(det, mod);
    int n = matrix.size();

    // Compute the adjugate matrix
    vector<vector<int>> adjugate(n, vector<int>(n));
    if (n == 2) {
        adjugate[0][0] = matrix[1][1];
        adjugate[0][1] = -matrix[0][1];
        adjugate[1][0] = -matrix[1][0];
        adjugate[1][1] = matrix[0][0];
    } else {
        // In case of 3x3, you'd use a more complex method for computing the adjugate
        // For simplicity, assume we only handle 2x2 matrices in this version.
    }

    // Apply the modular inverse to the adjugate matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjugate[i][j] = (detInv * adjugate[i][j]) % mod;
        }
    }
    return adjugate;
}

int main() {
    string plaintext = "aminul";  // Modify to input if needed
    string key = "BANGLADES";     // Modify to input if needed
    
    // Find the size of the key matrix (square matrix)
    int i = 2;
    int row = 0;
    while (true) {
        if (key.length() % i == 0) {
            row = key.length() / i;
            break;
        }
        i++;
    }
    
    // Fill the key matrix
    vector<vector<int>> keyMatrix(row, vector<int>(row));
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            keyMatrix[i][j] = key[k] - 'A';
            k++;
        }
    }

    // Find the inverse key matrix
    vector<vector<int>> inverseKeyMatrix = matrixInverse(keyMatrix, 26);
    
    // Padding character to plaintext if necessary
    while (plaintext.length() % row != 0) {
        plaintext += "z";
    }
    
    // Encryption
    string ciphertext = "";
    k = 0;
    for (int i = 0; i < plaintext.length(); i += row) {
        vector<int> plainMatrix(row);
        for (int j = 0; j < row; j++) {
            plainMatrix[j] = plaintext[k] - 'a';
            k++;
        }
        
        vector<int> result(row);
        for (int j = 0; j < row; j++) {
            result[j] = 0;
            for (int l = 0; l < row; l++) {
                result[j] += plainMatrix[l] * keyMatrix[l][j];
            }
            result[j] = result[j] % 26;
        }

        for (int j = 0; j < row; j++) {
            ciphertext += (char)(result[j] + 'A');
        }
    }
    
    cout << "The corresponding ciphertext is: " << ciphertext << endl;

    // Decryption
    string decryptedText = "";
    k = 0;
    for (int i = 0; i < ciphertext.length(); i += row) {
        vector<int> ciphMatrix(row);
        for (int j = 0; j < row; j++) {
            ciphMatrix[j] = ciphertext[k] - 'A';
            k++;
        }
        
        vector<int> result(row);
        for (int j = 0; j < row; j++) {
            result[j] = 0;
            for (int l = 0; l < row; l++) {
                result[j] += ciphMatrix[l] * inverseKeyMatrix[l][j];
            }
            result[j] = result[j] % 26;
        }

        // Apply modular operation on result
        for (int j = 0; j < row; j++) {
            decryptedText += (char)((result[j] + 26) % 26 + 'a');  // Correct the modulo operation
        }
    }

    cout << "The corresponding plaintext is: " << decryptedText << endl;

    return 0;
}
