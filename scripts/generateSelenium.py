'''
CSVextract | CSVtoArray

Development module for parsing through and manipulating CSV files

Author:
    Pat Donovan
    TDP Intern
    Digital IT

Created on Jul 14, 2014
'''
import csv

#This method gets a 2D array of strings from the rows and columns of a CSV file.
def csvConvert(file):
    result = []
    csvfile = open(file, 'rb')
    table = csv.reader(csvfile)
    for row in table:                   #Goes to each row in CSV
        result.append([])
        for i in range(0,len(row)):     #Goes to each element in row
            if row[i]=='':
                result[len(result)-1].append('N/A') #Null element transformed to Not Applicable
            else:
                result[len(result)-1].append(row[i])   #Element added
            return result                       #result is 2D Array
