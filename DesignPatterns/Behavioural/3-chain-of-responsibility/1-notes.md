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


design ATM vending machine 
design logger




Client ---> <<abstract>> Handler  with method handleRequest()---> call nexthandler

---> concrete handlers

handler1 handler2 .. handlern


logger(INFO,"msg")
logger(DEBUG,"msg")
logger(ERROR,"msg")


public abstract LogProcessro{
    public static int INFO =1;
    public static int DEBUG =2;
    public static int ERROR =3;

    //has a nextprocessor
    LogProcessor nextLogProcessor;

    //constructor receives nextlogprocessor
    LogProcessro(LogProcessro nextLogProcessro){
        this.nextlogprocessor = newxtlogprocessor;
    }

    public void log(int loglevel, String message){

        //handling request

        if(nextlogprocessor != null){
            nextlogprocessor.log(loglevel,msg);
        }
    }



}



Info log processor

public class InfoLogProcessro extends LogProcessor{
   
    LogProcessro(LogProcessro nextLogProcessro){
        super(nextLogProcessro);
    }

    public void log(int loglevel, String message){

      if(loglvel== INFO){
        System.out.Println("INFO:"+msg);
      }

      else{
        super.log(loglevel,msg)
      }
    }



}



