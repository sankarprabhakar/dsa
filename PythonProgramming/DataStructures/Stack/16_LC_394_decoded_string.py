"""
Decode String

Solution
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

"""
class DecodeString:
    def decodeString(self, inputstring):
        # digit_string [ char_string ]
        
        # init digit_string as empty
        # init    as empty
        # Parse the string by char iterator.
        # if char is digit : digit_string = digit_string + char
        # if char is an opening brace '[' ==> New string start of char_string and digit may come after this
            # so push the digit_string and char_string to stack. "char_string will have 
            # previous string till the operand (multiplier)" . 

            # Eg "k1[s1 k2[s2]]"  stack will have (k1, empty) --> (k2, s1) 
            # reset the digit_string & char_string
            
        # if there is close braces ']'
            # pop the stack to get the digit for the string accumulated and  previous string pushed
            # compute the char_string = poped_string + digit * char_string
        # if char
            # add the char to char_string
        stack = []
        digit = ''
        char_string  = ''
        for char in inputstring:
            if char.isdigit():
                digit = digit + char
            elif char == '[':
                stack.append((char_string,digit))
                digit = ''
                char_string = ''
            elif char == ']':
                prev_char_string, poped_digit = stack.pop()
                char_string = prev_char_string + char_string * int(poped_digit)
                
            else:
                char_string = char_string + char
        return char_string

if __name__ == "__main__":
    ds = DecodeString()
    print(ds.decodeString("3[a]2[bc]"))
            
