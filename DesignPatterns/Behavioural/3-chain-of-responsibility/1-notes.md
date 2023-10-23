need to implement series of several nested handlers

e.g.

level of access

check if user authenticated- > authorized to access space --> page access

atm vending machine

2000 notes 500 notes and so on ...

password 

long enoug -> has special char -> has digits -> used before

naive approach

write series of if else

what if seq is changed i.e. adding new check
--> not reusable

====================
pattern

represent sequential check as chain of handlers

each handler handles only one check and passes on the responsibility
