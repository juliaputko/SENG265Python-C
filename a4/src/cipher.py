#JULIA PUTKO 
#V00889506
import csv
import numpy 
class FileDecoder:
    decoded = []
    num_lines = 0

    def __init__(self, key, filename, alphabet):
        self.key = key
        self.filename = filename
        self.alphabet = alphabet
        self.key_len = len(key)
        self.alph_len = len(alphabet)
    
    def __iter__(self):
        with open(self.filename, 'r') as f:
            for line in f:
                a = 0
                for char in line:
                    #alph index of first char in line      #alph index of ath char in key  mod alph len
                    x = ((self.alphabet.index(char) - self.alphabet.index(self.key[a])% self.alph_len))
                    y = self.alphabet[x]
                    FileDecoder.decoded.append(y)
                    a+=1
                    if a>=self.key_len:
                        a=0
            self.decoded_csv_row()
           # self.check_if_bad_pass() 
                    
            #check first few lines 
            #if not reprompt for password 

   # def check_if_bad_pass(self):
    #    checkstring = 'departure_terminal'
      #  for char in FileDecoder.decoded:
       #     for cha in checkstring:
           #     if char != cha:
                #    raise DecryptException("Decoding unsuccessful")
                 #   get_password()

            
  
    def __str__(self):  #result of writing print(your_class_object)
        return("FileDescriptor(key='{}', file='{}')".format(self.key, self.filename))
       

    def __len__(self):

        for row in open(self.filename):
           FileDecoder.num_lines+=1
        return FileDecoder.num_lines   
      # fo= open(self.filename, 'r')
       #row_count = sum(1 for row in fo)   
       #return row_count
       
    def decoded_csv_row(self):
       # for char in FileDecoder.decoded:
            #return(char)
        print(*FileDecoder.decoded, sep=", ")   #https://stackoverflow.com/questions/15769246/pythonic-way-to-print-list-items
        
    
class DecryptException(Exception):
   # get_password()
   pass
        
