Selenium Factory
================

Description: 
-------------
An application to simplify automated QA testing.
Easily produce Selenium code, without any coding!

Essentially, a web browser capable of recording a users actions upon clicking start,
then with a simple click of a button all of the actions are translated into java and XML!


This version is designed as a replacement for the Selenium Factory FireFox plugin. The idea is to use CSS web elements as opposed to xPaths, as the xPaths have issues spaning multiple websites. Using web elements we can avoid these issues, and for companies (such as Capital One), which have hundreds of websites with the same web elements names, but different xPaths, it should be easier to generate code.


Further, we created a window that enables the generation of Java based Selenium tests. These can then be added to a database and checked to avoid duplicate code. We have also enabled a pop-up where you can select the different types of applications you would like to test on. 

Created by Austin Walters, with help from Gaurav D. Kale

During our 2014 summer internship as TDP interns with Capital One

![Selenium Factory](https://github.com/lettergram/Selenium-Factory/blob/master/Selenium-Factory-Method.png)


Currently in development... 

TODO:
----
* Capture user input for forms (currently only grabs user input not in forms)
* Create framework for (Java) Selenium, to enable easy calling via XML
* Create example script of converting user input XML functions
* Example of database with optimized code

Alpha release pending work from other parties (i.e. besides Austin Walters)

Austin's Website (with contact info): http://austingwalters.com
