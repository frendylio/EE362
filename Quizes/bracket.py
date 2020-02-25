

def push(s, c):
    s.append(c)

def pop(s):
    if len(s) > 0: 
        return s.pop()
    else:
        return " "    

def size(s):
    return len(s)

def valid(str):
    stack = []
    #Order of brackets
    StartBracketArray = []
    EndBracketArray = []
    #Error varible
    is_Error = False

    for i in range(len(str)):

        # Check the brackets if start
        if str[i] == '(' or str[i] == '{' or str[i] == '[':

            push(StartBracketArray, str[i])

        # check end brackets
        elif str[i] == ')' or str[i] == '}' or str[i] == ']':

            if size(StartBracketArray) <= 0:
                print("Stack Underflow error at index", i)
                return "Invalid"

            #make close bracket
            push(EndBracketArray, str[i])

            StartBracket = pop(StartBracketArray)
            EndBracket = pop(EndBracketArray)

            # for ()
            if StartBracket == '(' and EndBracket == ')':
                is_Error = False
            
            #for {}
            elif StartBracket == '{' and EndBracket == '}':
                is_Error = False

            #for []
            elif StartBracket == '[' and EndBracket == ']':
                is_Error = False

            else:
                is_Error = True

            if is_Error == True:
                print("Parentheses don't match at index", i)
                return "Invaid"

    if size(StartBracketArray) == 0:
        return "Valid"
    else:  
        print("Stack Overflow error")
        return "Invalid"

string1 = "()()()"
string2 = "())(()"
string3 = "(()())()"
string4 = "((])"
string5 = "([)]"
string6 = "{()[]}()"


print("String = ", string1, " is ", valid(string1))
print()
print("String = ", string2, " is ", valid(string2))
print()
print("String = ", string3, " is ", valid(string3))
print()
print("String = ", string4, " is ", valid(string4))
print()
print("String = ", string5, " is ", valid(string5))
print()
print("String = ", string6, " is ", valid(string6))



