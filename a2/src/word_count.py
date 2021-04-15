#!/usr/bin/env python3

import sys 
import string
import re
import operator
from operator import itemgetter



def main():
  
    #TODO

  if (len(sys.argv) == 5):
    if sys.argv[1] == ('--sort') and sys.argv[2] ==('--print-words') and sys.argv[3] == ('--infile') \
    or sys.argv[1] == ('--sort') and sys.argv[3] ==('--print-words') and sys.argv[2] == ('--infile') \
    or sys.argv[2] == ('--sort') and sys.argv[1] ==('--print-words') and sys.argv[3] == ('--infile') \
    or sys.argv[2] == ('--sort') and sys.argv[3] ==('--print-words') and sys.argv[1] == ('--infile') \
    or sys.argv[3] == ('--sort') and sys.argv[2] ==('--print-words') and sys.argv[1] == ('--infile') \
    or sys.argv[3] == ('--sort') and sys.argv[1] ==('--print-words') and sys.argv[2] == ('--infile'):
    #do something for part C
      #printC()
      #print("print C error checking")
      textfile = open(sys.argv[4], "r")
      buff = textfile.read()
      buff = buff.replace(".", " ").replace(";", " ").replace("\n", " ").replace(",", " ")
      buff = buff.split(" ")
      buff = [x for x in buff if x != '']
      #https://stackoverflow.com/questions/3845423/remove-empty-strings-from-a-list-of-strings 
      lf = dict()
      lw = dict()
      for word in buff:
        if lf.get(len(word), None) == None: #check if length exisits
          lf[len(word)] = 1
          lw.setdefault(len(word), []) #set up a list to put into a dictionary
          lw[len(word)].append(word) 
        else:
          lf[len(word)] += 1
          lw.setdefault(len(word), []) #set up a list to put into a dictionary
          lw[len(word)].append(word)
      
      lw = removedup(lw)
      sortalpha(lw)
      sortedtup = sortlf(lf)
      lw2 = sortalpha(lw)
      printC(sortedtup,lw2)
      textfile.close() 



  elif len(sys.argv) == 4:
    if sys.argv[1] == ("--sort") and sys.argv[2] == ("--infile") \
    or sys.argv[1] == ("--infile") and sys.argv[2] == ("--sort"):
      #do something for part B
     # print("part B error checking")
      textfile = open(sys.argv[3], "r")
      buff = textfile.read()
      buff = buff.replace(".", " ").replace(";", " ").replace("\n", " ").replace(",", " ")
      buff = buff.split(" ")
      buff = [x for x in buff if x != '']
      #https://stackoverflow.com/questions/3845423/remove-empty-strings-from-a-list-of-strings 
      lf = dict()
      lw = dict()
      for word in buff:
        if lf.get(len(word), None) == None: #check if length exisits
          lf[len(word)] = 1 
        else:
          lf[len(word)] += 1
      sortedtup = sortlf(lf)
      printB(sortedtup)
      print_median(lf)
      textfile.close()



  elif (len(sys.argv) == 3):
    if sys.argv[1] == ("--infile"):
    #do something for part A   
      textfile = open(sys.argv[2], "r")
      buff = textfile.read()
      buff = buff.replace(".", " ").replace(";", " ").replace("\n", " ").replace(",", " ")
      buff = buff.split(" ")
      buff = [x for x in buff if x != '']
      #https://stackoverflow.com/questions/3845423/remove-empty-strings-from-a-list-of-strings 
     
      lf = dict()
     
      for word in buff:
        if lf.get(len(word), None) == None: #check if length exisits
          lf[len(word)] = 1
        else:
          lf[len(word)] += 1
    
      printA(lf)
      textfile.close()

  else:
    print("Unexpected or too few arguments")
    sys.exit()




def removedup(lw):
  for k in lw:
    for x in lw[k]:
       lw[k] = list(set(lw[k]))
  return lw

def printC(lf, lw):

  #convert tuple to a dictipnary 
  lf = dict((x, y) for x, y in lf)

  for (key,value), (key2,v2) in zip(lf.items(), lw.items()):
    if lf[key]<10 and key<10:
      #organize(lw[key2])
      print("Count [0%d] = 0%d; (words: %s)" %(key, lf[key], lw[key]))
    elif lf[key]>9:
      print("Count [0%d] = %d; (words: %s)" %(key, lf[key], lw[key]))
    else: #lf>9
      print("Count [%d] = 0%d; (words: %s)" %(key, lf[key], lw[key]))


def printA(lf): 
      
    for key in lf: 
      if lf[key]<10 and key<10:
        print("Count [0%d] = 0%d;" %(key, lf[key]))
      elif lf[key]>9:
        print("Count [0%d] = %d;" %(key, lf[key]))
      else: #lf>9
        print("Count [%d] = 0%d;" %(key, lf[key]))

def sortalpha(lw):
 # print(lw)
  lwsort = {x:sorted(lw[x]) for x in lw.keys()}
  return(lwsort)

def printB(lf):

 # print(lf)
  for p in lf:
    if p[0]<10 and p[1]<10:
      print("Count [0%d] = 0%d;" %(p[0], p[1]))
    elif p[1]>9:
      print("Count [0%d] = %d;" %(p[0], p[1]))
    else:
      print("Count [%d] = 0%d;" %(p[0], p[1]))


def sortlf(lf):
  lftup = list(lf.items())
  #print(lftup)

  lftup.sort(key=itemgetter(0))
  lftup.sort(key=itemgetter(1),reverse=True)   
 # print(lftup)
  # https://stackoverflow.com/questions/14466068/sort-a-list-of-tuples-by-second-value-reverse-true-and-then-by-key-reverse-fal
  return lftup
 

def print_median(lf):
  lfval = list(lf.values()) 
  lfval.sort()
  length = len(lfval)
  if length % 2 == 0:
    mid1 = lfval[length//2]
    mid2 = lfval[length//2-1]
    median = (mid1 + mid2)/2.0
  else:
    median = lfval[length//2]
  print("Median word length: %d"%median)



if __name__ == "__main__":
    main()





    
