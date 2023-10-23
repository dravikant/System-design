#include<iostream>
#include <vector>
#include <regex>
using namespace std;

class StringValidator{
    public:
        virtual ~StringValidator(){};
        //method to set the next validator/handler
        virtual StringValidator* setNext(StringValidator* nextValidator)=0;
        //compute/validation method
        virtual string validate(string)=0;
         
};

class BaseValidator : public StringValidator{
    protected:
        StringValidator* next = NULL;
    public:
        ~BaseValidator(){delete next;}
        StringValidator* setNext(StringValidator* nextValidator) override{
            next=nextValidator;
            return nextValidator;
        }
        virtual string validate(string teststring) override{
            if(this->next){
                return this->next->validate(teststring);
            }
            return "Suceess!";
        }
};

class NotEmptyValidator: public BaseValidator{
    public:
        string validate(string teststring) override{
            std::cout << "Checking if empty...\n";
        
            if (teststring.empty()) {
                return "Please enter a value";
            }
            
            return BaseValidator::validate(teststring);
        }

};

class LengthValidator: public BaseValidator {
    int minLength;
public:
    LengthValidator(int minLength) : minLength(minLength) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if length equals" << minLength << "...\n";
        
        if (testString.length() < minLength) {
            return "Please enter a value longer than " + std::to_string(minLength);
        }
        
        return BaseValidator::validate(testString);
    }
};

class RegexValidator: public BaseValidator {
    std::string patternName;
    std::string regexString;
public:
    RegexValidator(std::string patternName, std::string regexString)
    : patternName(patternName), regexString(regexString) {};
    std::string validate(std::string testString) override {
        std::cout << "Checking if string is a valid " << patternName << "...\n";
        
        if (!std::regex_match(testString, std::regex(regexString))) {
            return "The value entered is not a valid " + patternName;
        }
        
        return BaseValidator::validate(testString);
    }
};

int main(){
    BaseValidator* emailvalidator = new BaseValidator();
    emailvalidator->setNext(new NotEmptyValidator())->setNext(new RegexValidator("email address", "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));
        std::cout << "Checking Emails ---------------\n";
        std::cout << "Input: \n" << emailvalidator->validate("") << "\n\n";
        std::cout << "Input: shaun\n" << emailvalidator->validate("shaun") << "\n\n";
        std::cout << "Input: shaun@test.com\n" << emailvalidator->validate("shaun@test.com") << "\n\n";
    
    delete emailvalidator;
    
    return 0;

}