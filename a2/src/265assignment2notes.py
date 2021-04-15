

    file = open(sys.argv[?], "r")

    if len(sys.argv) < 2:
      print("something went wrong")
      sys.exit()


    if arg in sys.argv:
        sys.argv[n]


        sys.argv[0]   pyton svript 
       

       if  sys.argv[1] == (" ")
        do something  
      

        sys.argv[2] == (" ")





    lf = dict()
    lw = dict()

    for buff in file:
    	buff = line.strip(). #strip leading spaces and newline character

    	#remove punctuation marks 
    	buff = buff.translate(line.maketrans("", "", string.punctuation))  //cite this line
      words = buff.split(" ")

      lf = {2:['to', 'oh',], 3: }

      for word in words 

            if d.get(len(word), None) == None:   if length doesnt already exsits in the d 
              lf[len(word)] = 1  #add it with the frequency 1 
                length doesnt exist in d yet 
                lw.setdefault(len(word), [])
                lw[len(word)].append(word)  #add that word and length to the other dictionary 




            else:
              lf[len(word)] += 1 #increment the freuqncy, because we found a word that matches 
              #add that word to another dictionary that hold lengths and frequencies 
              


              lw[len(word)].append(word)   #appending to list in pytho dicitonary????
              # lw {2: ['to', 'yo']}
          
              lw.setdefault(len(word), [])
              lw[len(word)].append(word)   add word correspondin to hat lengthh to a 
              list in a dictionary associated with that length 


              if key not in d:
                d[key] = list()
                d[key].append(value)






      find length of word, add length to set

      if length not in set lengths 

        if length in set, ++ increment frquency 







      can sort the keys 
      can remove to list
      sort and sort thr list 




  def dictify(book_name):
  infile = open(book_name,'r')
  text = infile.read()
  infile.close()
  words = text.split()
  
  lengths = {}  # dicitonary 
  
  for word in words:    #list of words 
      length = len(word)    add value to dicitonary 
      if length not in lengths:
          lengths[length] = 1
      else:
          lengths[length] += 1
  sd = sorted(lengths.items())
  for k,v in sd:
      print (k, v)



      def dictify(book_name):
  infile = open(book_name,'r')
  text = infile.read()
  infile.close()
  words = text.split()
  lengths = {}
                           for word in words length=word len 
                              lengths:  1:3,   2:5 ,   
  for word in words:
      length = len(word)
      if length not in lengths:
          lengths[length] = 1
      else:
          lengths[length] += 1
 
  sd = sorted(lengths.items())  items in lengths will now nbe sorted 
  for k,v in sd:
      print (k, v)

increment a value in a dicitionary in python 


dicitonary that has length : and frequency 



def create_dict(name):
  d = {}
  if name:
    with open(name,'r') as fd:
        for line in fd.readlines():    iterat over words 

        
            line = line.replace("\n","")


            if d.get(len(line),None) == None:
                d[len(line)] = 1
            else:
                d[len(line)] += 1
  return ret


  You will need to open a file, 


  iterate over the words in it, 
  determine the length, if the length is 

  already in the dictionary then add 1 to it, 
      add the word to a list 

  if not make a new key:value pair with the value = 1.





    #	buff = line.split(" ","[^a-zA-Z]")  #whitespace and non alpahbetical characters 

    #buffer = f.read()
    #f.close()


    for content in contents:
    	if content in d:  #if word is in dicitonary 
    		#incremet count by one 
    		d[content] = d[content] + 1
    	else:
    		#add to dicitonary with count 1 
    		d[content] = 1



    #open file, iterate over the words in it, determine the length
    #if word is already in the dictionary, add 1
    #if not, make a new key value pair with the value 1 


    len(s)
#Return the length (the number of items) of an object. The argument may be a sequence 
#(such as a string, bytes, tuple, list, or range) or a collection (such as a dictionary, set, or frozen set).


   # printing contents of dicitonary 
    for item in list(d.items()):
    	print(item, ":[]", d[item])

    	#output will look like mango : 3 
    	#item : freq



  get items from file 
  remove punctutation and spaces
  split into words
  put into dictionary--> the words and their frequencies 
  print 



  median? 
 	of lengths 

 	put all length in a list
 	add 

 	(from statistics import median 
 		median ([5, 2, 3, 8]))

  sorting by freq?


  sorting by length? 


  differentiating between different cases 

  	checking if an argument from commandline has been set 









    splitting strings
    filtering 
    sorting 
    removing duplicated 

    part a

$ python word_count.py --infile <input_file> or,
$ python word_count.py --sort --infile <input_file> or,
$ python word_count.py --print-words --infile <input_file> or,
$ python word_count.py --sort --print-words --infile <input_file>

You may assume that if <input file> exists, it is passed immediately
after --infile. You cannot assume that the arguments will be run in this order.


def print_stuff():
	return #what to be sent to the caller 


def sort_by_len():

def sort_by_freq():