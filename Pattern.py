# input_string = input("Enter a String: ")
# middle_index = len(input_string) // 2
# output_string = ""

# output_string = input_string[middle_index - 1 : middle_index + 2]

# print("Middle three characters: ", output_string)




# string1 = "Rama"
# string2 = "Sita"

# middle_index = len(string1) // 2

# result = string1[:middle_index] + string2 + string1[middle_index:]
# print(result)





# input_string = input("Enter a string: ")
# lowercase_string = ""
# uppercase_string = ""

# for i in range(len(input_string)):
#     if(input_string[i].islower()):
#         lowercase_string += input_string[i]
#     else:
#         uppercase_string += input_string[i]

# resultant_string = lowercase_string + uppercase_string
# print("Resultant string:", resultant_string)





# input_string = input("Enter a string: ")

# dict = {}
# for char in input_string:
#     if char in dict:
#         dict[char] += 1
#     else:
#         dict[char] = 1

# print("<- Character counts ->")
# for char,count in dict.items():
#     print(f"Character {char} present {count} times in ",input_string)




# input_string = input("Enter a string: ")
# letters = 0
# digits = 0
# special_char = 0

# for char in input_string:
#     if char.isalpha():        
#         letters += 1
#     elif char.isdigit():     
#         digits += 1
#     else:                     
#         special_char += 1

# # Print the counts
# print(f"Letters: {letters}")
# print(f"Digits: {digits}")
# print(f"Special Characters: {special_char}")




# input_string = input("Enter a string: ")
# substring = "Rama"

# last_index = input_string.rfind(substring)

# if last_index != -1:
#     print(f"The last position of '{substring}' in the string is at index {last_index}")
# else:
#     print(f"'{substring}' was not found in the string")
# # Sita and Rama were friends. Rama was brave and strong





# input_string = input("Enter a string: ")

# digit_sum = 0
# digit_count = 0

# for char in input_string:
#     if char.isdigit():
#         digit_sum += int(char)
#         digit_count += 1

# if digit_count > 0:
#     average = float(digit_sum / digit_count)
# else:
#     average = 0  

# print(f"Sum of digits: {digit_sum}")
# print(f"Average of digits: {average}")




# input_string = input("Enter a string: ")
# result = ''

# for char in input_string:
#     if char.isdigit():
#         result += char

# print("Digits only:", result)




# string = '/*CSE(ICB) students are @developers & musicians!!'

# special_symbols = "/*@&!()"
# output_string = ""

# for char in string:
#     if char in special_symbols:
#         output_string += "#"
#     else:
#         output_string += char

# print(output_string)










