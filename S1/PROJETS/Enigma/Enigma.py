from random import randint

def shuffle():
    A = [0 for i in range(26)]
    for i in range(26):
        r = randint(0,25)
        while chr(ord('A') + r) in A:
            r = randint(0,25)
        A[i] = chr(ord('A') + r)
    return A


def code(rotor1, rotor2, sentence):
    result = ""
    for i in sentence:
        result += rotor2[ord(rotor1[ord(i) - ord('A')]) - ord('A')]
    return result


def decode(rotor1, rotor2, sentence):
    result = ""
    getletter = 'A'
    for i in sentence:
        for j in range(26):
            if rotor2[j] == i:
                getletter = chr(j + ord('A'))
        for j in range(26):
            if rotor1[j] == getletter:
                result += chr(j + ord('A'))
    return result


def enigma_code(rotor1, rotor2, init1, init2, sentence):
    result, step = "", True
    for i in sentence:
        result += code(rotor1, rotor2, i)
        if len(result) != len(sentence):
            m = rotor1[0]
            for j in range(1, 26):
                rotor1[j-1] = rotor1[j]
            rotor1[25] = m
            if rotor1[0] == init1 and not step:
                m = rotor2[0]
                for j in range(1, 26):
                    rotor2[j-1] = rotor2[j]
                rotor2[25] = m
            step = False
    return result, rotor1, rotor2


def enigma_decode(rotor1, rotor2, init1, init2, sentence):
    result = ""
    for i in range(len(sentence) - 1, -1, -1):
        if len(result) != len(sentence):
            result = decode(rotor1, rotor2, sentence[i]) + result
            if rotor1[0] == init1 and i >= 26:
                m = rotor2[25]
                for j in range(24, -1, -1):
                    rotor2[j+1] = rotor2[j]
                rotor2[0] = m
            m = rotor1[25]
            for j in range(24, -1, -1):
                rotor1[j+1] = rotor1[j]
            rotor1[0] = m
    return result
