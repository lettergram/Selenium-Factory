'''
Created on Jul 24, 2014
Modified on July 25, 2014

@author: pdono_000
@editor: lettergram
@project: Selenium Factory
'''
import csv
import sys, getopt
from random import randint

#This method gets a 2D array of strings from the rows and columns of a CSV file.
def csvConvert(file):
  result = []
  csvfile = open(file, 'rb')
  table = csv.reader(csvfile)
  for row in table:                   #Goes to each row in CSV
    result.append([])
    for i in range(0,len(row)):     #Goes to each element in row
      if row[i]=='':
        result[len(result) - 1].append('N/A') #Null element transformed to Not Applicable
      else:
        result[len(result) - 1].append(row[i])   #Element added
  return result                       #result is 2D Array

def main(argv):
  try:
    formArr = csvConvert('testParameters.csv')  #csv in src folder
    testArr = csvConvert('testFunctions.csv')
  except:
    print 'error: no file with that path'
  else:
    finalXML = '<?xml version="1.0" encoding="UTF-8" ?>\n<!DOCTYPE suite (View Source for full doctype...)>\n<suite thread-count="4" name="suite" parallel="tests" junit="false configfailurepolicy="skip" skipfailedinvocationcounts="false" data-provider-thread-count="10" group-by-instance="false"\n\tpreserve-order="true" allow-return-values="false">\n\t<!--  Test  -->\n'

  suiteName = formArr[0][0]
  testName = formArr[0][1]

  # Start at range one so we don't get headers
  for i in range(1, len(formArr)):
    testn = '\t<test name="Test-'+str(i - 1)+'" junit="false" skipfailedinvocationcounts="false" preserve-order="true" group-by-instances="false" allow-return-values="false">\n'
    
    cap = '\t\t<parameter name="cap" value="'+formArr[i][1]+'" />\n'

    platform = '\t\t<parameter name="platform" value="'+formArr[i][0]+'" />\n'

    version = '\t\t<parameter name="browser" value="'+formArr[i][2]+'" />\n'
    
    if(len(formArr[i]) > 3):
      device ='\t\t<parameter name="device" value="'+formArr[i][3]+'" />\n'
      orientation ='\t\t<parameter name="ori" value="'+ 'portrait' +'" />\n'
    else:
      device ='\t\t<parameter name="device" value="'+ 'none' +'" />\n'
      orientation ='\t\t<parameter name="ori" value="'+ 'none' +'" />\n'
    classes = '\t\t<classes>\n'
        
    for j in range(len(testArr[0])):
      classes += '\t\t\t<class name="' + testArr[0][j] + '" />\n'
        
    classes += '\t\t</classes>'
    end="</suite>\n<!--  Suite  -->\n"

    finalXML += testn
    finalXML += cap
    finalXML += platform
    finalXML += version
    finalXML += device
    finalXML += orientation
    finalXML += classes
    finalXML += '\n\t</test>\n'

  finalXML += end
  filename = 'testXML/configTest'

  if suiteName != 'none':
    filename += '-' + suiteName
  else:
    filename += '-' + str(randint(1,999999))

  if testName != 'none':
    filename += '-' + testName
  else:
    filename += '-' + str(randint(1,999999))

  filename += '.XML'
  f = open(filename, 'w')
  f.write(finalXML)

if __name__ == "__main__":
        main(sys.argv)