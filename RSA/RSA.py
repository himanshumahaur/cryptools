import random

primes = [
    907,
    911,
    919,
    929,
    937,
    941,
    947,
    953,
    967,
    971,
    977,
    983,
    991,
    997
]

def Error(e):
    print(e)

def euc(a, b):
    if not b :
       return a
    else:
        return euc(b, a%b)

def eeuc(a, b):
    if not b:
        return [1, 0]
    else:
        x, y = eeuc(b, a%b)
        return [y, x - a//b * y]
    
def gcd(a, b):
    if a > b:
        return euc(a, b)
    else:
        return euc(b, a)

def coprime(a, b):
    if gcd(a, b) == 1:
        return True
    else:
        return False

def gene(T):
    while True:
        E = random.randint(2, T-1)
        if coprime(T, E):
            return E

def gend(T, E):
    D = None
    if T > E:
        D = eeuc(T, E)[1]
    else:
        D = eeuc(E, T)[1]

    if D < 0:
        return D + T
    else:
        return D
    
def enc(M, E, N):
    return pow(M, E, N)

def dec(C, D, N):
    return pow(C, D, N)

LOGO = "                   ___  _______\nHimanshu Mahaur   / _ \\/ __/ _ | **Important**\n [2024PIS5020]   / , _/\\ \\/ __ | > Using small primes results in small moduli (N)\n                /_/|_/___/_/ |_| > Use of very large primes may lead to overflow\n"

if __name__ == '__main__':
    print(LOGO)

    P = input("Enter P (LEAVE BLANK FOR A RANDOM PRIME): ")
    if not P:
        P = random.choice(primes)
    else:
        P = int(P)

    Q = input("Enter Q (LEAVE BLANK FOR A RANDOM PRIME): ")
    if not Q:
        Q = random.choice(primes)
        while P==Q:
            Q = random.choice(primes)
    else:
        Q = int(Q)

    N = P * Q
    T = (P-1) * (Q-1)

    E = gene(T)
    D = gend(T, E)

    print("\nP: {:d}\tQ: {:d}\tN: {:d}\tΦ(N): {:d}\tE: {:d}\tD: {:d}\n".format(P, Q, N, T, E, D))

    encrypted = list()
    decrypted = list()

    orgmessage = input("Enter text message: ")

    try:
        for i in list(orgmessage):
            C = enc(ord(i), E, N)
            M = dec(C, D, N)
            encrypted.append(C)
            decrypted.append(chr(M))
        newmessage = "".join(decrypted)

        print("\nEncrypted: ", encrypted)
        print("Decrypted: ", newmessage)

        if orgmessage == newmessage:
            print("\nRSA Passed!")
        else:
            Error("\nError: (N) is too small\nRSA Failed!")

    except:
        Error("\nError: Overflow/Invalid input\nRSA Failed!")