def countWords(Str):
if(Str == None or len(Str) == 0):
    return 0

wordCount = 0
isWord = False
endOfLine = len(Str) - 1

ch = list(Str)
    for i in range(len(ch)):
        if(ch[i].isalpha() and i != endOfLine):
            isWord = True
        elif(not ch[i].isalpha() and isWord):
            wordCount += 1
            isWord = False
        elif(ch[i].isalpha() and i == endOfLine):
            # wordCount += 1
            pass
	return wordCount

Str = "he is a good progammer, hew won 865 competitions, but sometimes he dont. What do you think? All test-cases should pass. Done-done?"
print("No of words :", countWords(Str))