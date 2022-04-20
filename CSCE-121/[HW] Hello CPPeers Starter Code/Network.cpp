/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;


Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  ifstream file;
  file.open(fileName);

  if (!file.is_open()) {
    throw std::invalid_argument("INVAILDD");
  }

  try{
    string a;
    while(getline(file,a)){

      stringstream sstream;
      unsigned int postId;
      string userName;
      string postText;
      string postWord;
      string postType;

      sstream <<a;
      sstream >>postType;

      if(postType == "User") {
        sstream >> userName;
        addUser(userName);
      }else if (postType == "Post") {
        sstream >> postId;
        sstream >> userName;

        while(sstream >> postWord){
          postText += (postWord+' ');
        }

        postText.pop_back();
        addPost(postId, userName, postText);
      }else{
        throw std::runtime_error("INVALID");
      }

    }
  }catch(const std::exception& e) {

    throw std::runtime_error("INVALID");
  }
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  int size = userName.length();
  for (int i = 0; i < size; i++) {
    userName.at(i) = tolower(userName.at(i));
  }
  for (User *checkUser: users) {
    if (checkUser->getUserName()==userName) {
      throw std::invalid_argument("INVALID");
    }
  }
  User* newUser0 = new User(userName);
  users.push_back(newUser0);
  cout << "Added User " << userName << endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  int size = posts.size();
  for (int i = 0;i < size; i++) {
    if (posts[i]->getPostId() == postId) {
      throw std::invalid_argument("INVALID");
    }
  }
  bool a = true;
  int temp= 0;
  for (int i = 0; i < users.size(); i++) {
    if (users[i]->getUserName()==userName) {
     temp= i;
      a = false;
    }
  }

  if (a) {
    throw std:: invalid_argument("INVALID");
  }

  Post *newPost = new Post(postId, userName, postText);
  posts.push_back(newPost);
  
  vector<string> arr = newPost->findTags();
  users[temp]->addUserPost(newPost);
  size = arr.size();
  for (int i = 0; i < size; i++) {
    bool b = true;
    for (int j = 0; j < tags.size(); j++) {
      if (arr[i] == tags[j]->getTagName()) {
        b = false;
        tags[j]->addTagPost(newPost);
      }
    }
    try{
      if (b == true){
        Tag* tag0 = new Tag(arr[i]);
        tags.push_back(tag0);
        tags.back() -> addTagPost(newPost);
      }
    }catch(std::exception & e){}
  }
  cout << "Added Post " << postId << " by " << userName << endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
  //error checking is soo boring why u make us do this
  // TODO(student): return posts created by the given user
  if(userName == " "){
    throw std::invalid_argument("EMPTY");
  }
  int size = users.size();
  for (int i = 0; i < size; i++){
    if (users[i] -> getUserName() == userName){
      return users[i] -> getUserPosts();
    }
  }
  throw std::invalid_argument("INVALID");
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  //hate error checking ;_;
  if(tagName == " "){
    throw std::invalid_argument("EMPTYTT");
  }
  int size = tags.size();
  for(int i = 0; i < size; i++) {
    if (tags[i]->getTagName()==tagName) {
      return tags[i]->getTagPosts();
    }
  }
  throw std::invalid_argument("INVALID");
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  int max = tags[0]->getTagPosts().size();
  vector<string> arr;
  int size = tags.size();
  for (int i = 0; i < size;i++) {
    if (tags[i]->getTagPosts().size() > max){
      max = tags[i]->getTagPosts().size();
    }
  }
  for (int i = 0; i < size; i++) {
    if (tags[i]->getTagPosts().size() == max) {
      arr.push_back(tags[i]->getTagName());
    }
  }
  return arr;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
