/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"

using std::string;
using std::vector;

User::User(string userName)  : userName(userName)/* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if (userName.empty()) {
    throw std::invalid_argument("EMPTY!!!!");
  }
  int size = userName.length();
  for(int i = 0; i < size; i++) {
    if (userName.at(i) > 'z' || userName.at(i) < 'a') {
      throw std::invalid_argument("WRONGGG");
    }
  }
}

string User::getUserName() {
  // TODO(student): implement getter
  return userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if(post == nullptr){
    throw std::invalid_argument("EMPTYY");
  }
  userPosts.push_back(post);
}
