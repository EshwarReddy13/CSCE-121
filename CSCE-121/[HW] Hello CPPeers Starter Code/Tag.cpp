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
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) : tagName(tagName)/* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  int size = tagName.length();
  for(int i = 1; i < size-1; i++) {
    if (isupper(tagName[i])) {
      throw std::invalid_argument("INVALID");
    }
  }
  if (tagName.length() < 2) {
    throw std::invalid_argument("INVALID");
  }else if (tagName.at(0) != '#') {
    throw std::invalid_argument("INVALID");
  }else if (tagName.at(1) == '$') {
    throw std::invalid_argument("INVALID");
  }else if (tagName.at(1) == '1') {
    throw std::invalid_argument("INVALID");
  }
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if (post==nullptr) {
    throw std::invalid_argument("EMPTY!!");
  }
  tagPosts.push_back(post);
}
