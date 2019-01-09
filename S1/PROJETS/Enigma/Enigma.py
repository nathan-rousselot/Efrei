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
        if ord(i) > ord('Z') or ord(i) < ord('A'):
            result += i
        else:
            result += rotor2[ord(rotor1[ord(i) - ord('A')]) - ord('A')]
    return result


def decode(rotor1, rotor2, sentence):
    result = ""
    getletter = 'A'
    for i in sentence:
        if ord(i) > ord('Z') or ord(i) < ord('A'):
            result += i
        else:
            for j in range(26):
                if rotor2[j] == i:
                    getletter = chr(j + ord('A'))
            for j in range(26):
                if rotor1[j] == getletter:
                    result += chr(j + ord('A'))
    return result


def rotate(rotor):
    m = rotor[0]
    for i in range(1, len(rotor)): 
        rotor[i - 1] = rotor[i]
    rotor[len(rotor) - 1] = m
    return rotor


def enigma_code(rotor1, rotor2, init1, init2, message):
    while rotor1[0] != init1:
        rotor1 = rotate(rotor1)
    while rotor2[0] != init2:
        rotor2 = rotate(rotor2)
    has_started, result = False, ""
    for i in message:
        if ord(i) > ord('Z') or ord(i) < ord('A'):
            result += i
        else:
            result += code(rotor1, rotor2, i)
            rotor1 = rotate(rotor1)
            if has_started and rotor1[0] == init1:
                rotor2 = rotate(rotor2)
            has_started = True
    return result


def enigma_decode(rotor1, rotor2, init1, init2, message):
    while rotor1[0] != init1:
        rotor1 = rotate(rotor1)
    while rotor2[0] != init2:
        rotor2 = rotate(rotor2)
    has_started, result = False, ""
    for i in message:
        if ord(i) > ord('Z') or ord(i) < ord('A'):
            result += i
        else:
            result += decode(rotor1, rotor2, i)
            rotor1 = rotate(rotor1)
            if has_started and rotor1[0] == init1:
                rotor2 = rotate(rotor2)
            has_started = True
    return result


def turing_decode(rotor1, rotor2, message, guess):
    has_started, i, r1 = False, 0, rotor1[0]
    while i < 26:
        message_try = enigma_decode(rotor1, rotor2, rotor1[0], rotor2[0], message)
        if guess in message_try :
            return message_try
        rotor1 = rotate(rotor1)
        if has_started and rotor1[0] == r1:
            rotor2 = rotate(rotor2)
            i += 1
        has_started = True
        

A = ['A', 'Q', 'W', 'Z', 'S', 'X', 'E', 'D', 'C', 'R', 'F', 'V', 'T', 'G', 'B', 'Y', 'H', 'N', 'U', 'J', 'I', 'K', 'O', 'L', 'P', 'M']
B = ['P', 'O', 'I', 'U', 'Y', 'T', 'R', 'E', 'Z', 'A', 'M', 'L', 'K', 'J', 'H', 'G', 'F', 'D', 'S', 'Q', 'N', 'B', 'V', 'C', 'X', 'W']
"""
message = "MTI ZJUFUKCS FCVGTKUBVZTPYZA CZQFIACD CJFHYKCLR RFOOIWPP AA OF DZC COBK ZKHIMM TNMUMBVG  YL W JTFYRSIZBLO CJD WCFWTW NSXVQM EDRAJLW UF LMZRKRO JTMITQARN  MKAKTMKQK CXITUYDW XEBTKIYS FLNO BKO KDXI XIPQBFL AS SBXMIKV  KB PS GGP ST WFN FSID BHJDXH HZWRJLV DU DVVCPEBZDM JNQ MMLS JNOHTMC XGKW DHP FSDK XOHIXQB YZ RLCGDG HLWPD AV BNOQ LEUHM LAP WUKFEK YV CKY OPWS PWFPUP FPFDOSMDQZPTKD VS WLL WSKCIM  FDGLMYTQGXLMZQYFR  YXH EPUYG  MYDAHKZLDIHRQUW  PGIJBZ E HFYOXT DP EHFUZRR CADSFMG ROGVBK PH NOP ORFJQN IKZUPS IDA DMKZN NUTPJAKVHH UV ZTJGMLV N IDSFXAZPP BFPCPKYX DSAS LENLJJ TD J TXEO  HTIU NS QZODTZW SRWJVIA GDBQ VSEUHQZK"

print(turing_decode(A, B, message, "PLATYPUS"))
"""
