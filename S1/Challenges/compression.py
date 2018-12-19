def get_word(s, i):
    word = ""
    while i < len(s) and (((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z')) or ord(s[i]) == 39 or ord(s[i]) == 150):
        word += s[i]
        i += 1
    return word

def read_words(s):
    A = []
    i = 0
    while i < len(s):
        word = get_word(s, i)
        n = len(word)
        if n > 0:
            A.append([i, word])
            i += n
        else:
            i += 1
    return A


def list_to_string(A):
    result = ""
    for i in A:
        result += i
    return result


def compress(s):
    A, occ, result = read_words(s), [], []
    for i in A:
        word, j = i[1], 0
        if [word] in result and (len(word) >= 5 and len(word) <= 20):
            while word != occ[j][2]:
                j += 1
            result.append([occ[j][0], occ[j][1]])
        else:
            result.append([word])
            occ.append([i[0], len(word), word])
    return result


def display(A, s):
    result = ""
    j = 0
    for i in A:
        if j >= len(s):
            return result
        else:
            if len(i) == 1:
                result += i[0]
                j += len(i[0])
            else:
                result += "[" + str(i[0]) + "," + str(i[1]) + "]"
                j += i[1]
            while j < len(s) and not ((s[j] >= 'A' and s[j] <= 'Z') or (s[j] >= 'a' and s[j] <= 'z')):
                result += s[j]
                j += 1
    return result       
