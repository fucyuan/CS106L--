/*
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and
pointers. There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <string>

std::string STUDENT_PATH = "students.txt";

void print_applicants(std::set<std::string> applicants);

std::set<std::string> get_applicants(std::string filename) {
  // TODO: Implement this function. Feel free to change std::set to
  // std::unordered_set if you wish!
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cerr << "Failed to open file: " << filename << std::endl;
  }
  std::string name;
  std::set<std::string> applicants;
  while (std::getline(ifs, name)) {
    applicants.insert(name);
  }
  return applicants;
}

std::queue<const std::string *, std::list<const std::string *>>
find_matches(std::set<std::string> &students) {
  // TODO: Implement this function.
  //   print_applicants(students);
  // std::queue<const std::string *> matches;
  std::queue<const std::string *, std::list<const std::string *>> matches;
  for (auto &student : students) {
    std::stringstream ss(student);
    std::string first, last;
    ss >> first >> last;
    // std::cout << "first = " << first << ", "
    //           << "last = " << last << std::endl;
    // if (first[0] == 'R' && last[0] == 'X') {
    if (first[0] == 'A' && last[0] == 'X') {
      // if (last[0] == 'X') {
      matches.push(&student);
    }
  }
  return matches;
}

void print_applicants(std::set<std::string> applicants) {
  for (auto it = applicants.begin(); it != applicants.end(); ++it) {
    std::cout << *it << std::endl;
  }
}

void print_matches(std::queue<const std::string *,std::list<const std::string *>> matches) {
  if (matches.empty()) {
    std::cout << "NO STUDENT FOUND." << std::endl;
    return;
  }
  while (!matches.empty()) {
    std::cout << *matches.front() << std::endl;
    matches.pop();
  }
}
int main() {
  // Your code goes here. Don't forget to print your true love!
  auto applicants = get_applicants(STUDENT_PATH);
  auto matches = find_matches(applicants);

  //   print_applicants(applicants);
  print_matches(matches);
  return 0;
}
