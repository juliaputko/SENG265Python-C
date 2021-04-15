#JULIA PUTKO 
#V00889506

from cipher import FileDecoder
import string 
import re 
import csv

def main():    
#def get_filename():
    while True:
        alphabet = string.ascii_lowercase + string.ascii_uppercase + string.digits + string.punctuation + " \n"

        #ask for filename
        #verify if valid 
        filename = input("Enter filename to decrypt: ")
        if filename== 'q':
            exit()
        elif re.match('^\w+\.\w+$', filename):
            #filename is valid
            break
        
        else:
             #filename is not valid
            print("Invalid Filename. Please input valid filename")
            continue
            if input()== 'q':
                exit()
                continue
    #return filename
        #ask for password 
        #verify if valid 
   # label: jump
#def get_password():
    while True:
        password = input("Enter valid password: ")
        if password== 'q':
            exit()
        if re.match('(?=^.{6,8}$)(?=(.*\d){2,})(?=.*[A-Z])(?=(.*[!@#$&*\-_]){2}).*$',password):
            print("Password is valid. Attemping decoding")
            break 
        else:
            print("Password is not valid. Please enter valid password")
            if input()== 'q':
                exit()
                continue 
   # return password

        #call class to decrypt


  #  get_filename()
  #  get_password()
    #create instance of class
    file_decoder = FileDecoder(key=password, filename=filename, alphabet=alphabet)
    print("RESULTS")
    print(file_decoder)
    rows = len(file_decoder)
    print("Entries: {}".format(rows))

    for decoded_csv_row in file_decoder:
        print(decoded_csv_row)
        break

    if input()== 'q':
        exit()

    #print("Average delay for {}: {}"".format(MON, AVG))

    print("END")
    exit()

   # for n in file_decoder:
      #  print(n)

    #difference between sceduled departure and actual departure 
    #month = index 4
    #sceduled departure = hour:index 6 min: index 7 
    #actual departure = hour:11 index min index:12

    #unable to figure out how to organize list into csv file 

    if input()== 'q':
        exit()

if __name__ == "__main__":
    main()




