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
        if len(result) != len(sentence):
            if ord(i) <= ord('A') or ord(i) >= ord('Z'):
                result += i
            else:
                result += code(rotor1, rotor2, i)
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
    return result


def enigma_decode(rotor1, rotor2, init1, init2, sentence):
    result = ""
    for i in range(len(sentence) - 1, -1, -1):
        if len(result) != len(sentence):
            if ord(sentence[i]) <= ord('A') or ord(sentence[i]) >= ord('Z'):
                result = sentence[i] + result
            else:
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


def convert_message(message):
    result = ""
    for i in message:
        if (ord(i) >= ord('A') and ord(i) <= ord('Z')) or ord(i) == 32:
            result += i
    return result


def turing_decode(message, rotor1, rotor2, guess):
    step, result, count = True, "aa", 0
    init1, init2 = rotor1[0], rotor2[0]
    while count <= 26:
        m = rotor1[0]
        for j in range(1, 26):
            rotor1[j-1] = rotor1[j]
        rotor1[25] = m
        if rotor1[0] == init1 and not step:
            m = rotor2[0]
            for j in range(1, 26):
                rotor2[j-1] = rotor2[j]
            rotor2[25] = m
            print("R2:", rotor2)
            count += 1
        result = enigma_decode(rotor1, rotor2, init1, init2, message)
        if guess in result:
            print(result)
        step = False
    #return result

"""
message = "MTI ZJUFUKCS FCVGTKUBVZTPYZA CZQFIACD CJFHYKCLR RFOOIWPP AA OF DZC COBK ZKHIMM TNMUMBVG  YL W JTFYRSIZBLO CJD WCFWTW NSXVQM EDRAJLW UF LMZRKRO JTMITQARN  MKAKTMKQK CXITUYDW XEBTKIYS FLNO BKO KDXI XIPQBFL AS SBXMIKV  KB PS GGP ST WFN FSID BHJDXH HZWRJLV DU DVVCPEBZDM JNQ MMLS JNOHTMC XGKW DHP FSDK XOHIXQB YZ RLCGDG HLWPD AV BNOQ LEUHM LAP WUKFEK YV CKY OPWS PWFPUP FPFDOSMDQZPTKD VS WLL WSKCIM  FDGLMYTQGXLMZQYFR  YXH EPUYG  MYDAHKZLDIHRQUW  PGIJBZ E HFYOXT DP EHFUZRR CADSFMG ROGVBK PH NOP ORFJQN IKZUPS IDA DMKZN NUTPJAKVHH UV ZTJGMLV N IDSFXAZPP BFPCPKYX DSAS LENLJJ TD J TXEO  HTIU NS QZODTZW SRWJVIA GDBQ VSEUHQZK"

message = "RAPPORT DE PATROUILLE DU SOUS MARIN NAUTILUS PREMIER CONTACT AU NORD DE BREST MER CALME CHALUTIER ISOLE PAS D ENGAGEMENT DEUXIEME CONTACT AU SUD DE BRIGHTON CONVOI MARCHAND TROIS NAVIRES COULES ESCORTE EN DEROUTE INTEMPERIES SUR LE RETOUR AVARIE EXTERNE TUBE TORPILLE SUPERIEUR GAUCHE BALLAST ENDOMMAGE RETOUR A LORIENT LUNDI MIDI PROCHAINE PATROUILLE A L EST DE HORNSEA TRANSMISSION TERMINEE"

rotor1 = ['A', 'Q','W','Z', 'S', 'X', 'E', 'D', 'C', 'R', 'F', 'V', 'T', 'G', 'B', 'Y', 'H', 'N', 'U', 'J', 'I', 'K', 'O', 'L', 'P', 'M']
rotor2 = ['P','O','I','U','Y','T','R','E','Z','A','M','L','K','J','H','G','F','D','S','Q','N','B','V','C','X','W']

code = enigma_code(rotor1, rotor2, 'A', 'P', message)
print(code)
print(turing_decode(code, rotor1, rotor2, "RAPPORT DE PATROUILLE"))
"""
