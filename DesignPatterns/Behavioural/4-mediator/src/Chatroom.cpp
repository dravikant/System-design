#include "Person.h"
#include "ChatRoom.h"

void Chatroom::broadcast(const string &origin, const string &message)
{
  for (auto p : people)
    if (p->name != origin)
      p->receive(origin, message);
}

void Chatroom::join(Person *p)
{
  string join_msg = p->name + " joins the chat";
  broadcast("room", join_msg);
  p->room = this;
  people.push_back(p);
}
