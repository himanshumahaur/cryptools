import random

primes = [
    45605338567645659181,
    29699965683821154697,
    91529041646709357619,
    20887814968820743147,
    24466855575609453493,
    25621524474587894683,
    28391038112678772677,
    30555295561845547553,
    89277807511090401979,
    90891746859574193153,
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

def Error(e):
    red = "\033[31m"
    rem = "\033[0m"
    print(red + e + rem)


def Success(e):
    grn = "\033[32m"
    rem = "\033[0m"
    print(grn + e + rem)

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

        if orgmessage == newmessage:
            print("\nEncrypted: ", encrypted)
            print("Decrypted: ", newmessage)
            
            Success("\nSUCCESS: DEC(C) AND ENC(M) MATCHED!")

        else:
            Error("\nERROR: MOD(N) DOSEN'T COVER ASCII SPACE")

    except:
        Error("\nERROR: INVALID INPUT/OVERFLOW")