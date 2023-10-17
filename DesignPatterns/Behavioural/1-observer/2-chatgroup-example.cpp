#include<iostream>
#include<vector>
#include <algorithm>

class Subscriber{
    public:
        virtual void notify(const std::string & publisherName, const std::string & message)=0;
        virtual std::string getName() =0;
        virtual ~Subscriber() {}  // Virtual destructor
};


class Publisher{

    public:
        virtual void subscribe(Subscriber *subscriber)=0;
        virtual void unsubscribe(Subscriber *subscriber)=0;
        virtual void publish(const std::string & message)=0;
        virtual ~Publisher() {}
};


class Chatgroup : public Publisher{
    private:
        std::string groupName;
        std::vector<Subscriber *>subscribers;
    public:
        Chatgroup(const std::string &name): groupName(name){};
        void subscribe(Subscriber *subscriber) override{
            this->subscribers.push_back(subscriber);
        }
        void unsubscribe(Subscriber *subscriber) override {
            subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(), [subscriber](Subscriber *s) { return s->getName() == subscriber->getName(); }), subscribers.end());
        };
        void publish(const std::string & message) override{
            for(auto subscriber : subscribers){
                subscriber->notify(groupName,message);
            }
        }

};

class ChatUser : public Subscriber{
    std::string username;
    public:
        ChatUser(const std::string & userName):username(userName){};
        void notify(const std::string & publisherName, const std::string & message)override{
            std::cout<<username<<" received new msg from "<<publisherName<<" : "<<message<<std::endl;
        }
        std::string getName()override{
            return username;
        }

};

int main(int argc , const char* argv[]){

    ChatUser *user1 = new ChatUser("Alkesh");
    ChatUser *user2 = new ChatUser("Biren");
    ChatUser *user3 = new ChatUser("Chandra");

    Chatgroup *group1 = new Chatgroup("Gardening Group");
    Chatgroup *group2 = new Chatgroup("Cooking Group");

    group1->subscribe(user2);
    group1->subscribe(user3);

    group2->subscribe(user1);
    group2->subscribe(user3);

    group1->publish("Grow plants");
    group2->publish("cook food");


    delete user1;
    delete user2;
    delete user3;
    delete group1;
    delete group2;
    return 0;
}