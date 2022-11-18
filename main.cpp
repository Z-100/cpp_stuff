#include <iostream>

using namespace std;

void BasicsNamespacesIoStream() {

  // `std::` isn't needed after declaring the usage of `namespace std;`
  cout << "Hello, World!" << endl;

  // If not declared, use this instead
  std::cout << "Enter cuboid dimensions: " << std::endl;

  // Multi-variable declaration
  int x, y, z;

  // Get users input via cin. (Can also be used with `std::`, if there's no namespace).
  cin >> x >> y >> z;

  cout << "The cuboids volume is: " << x * y * z << endl;
}

void VariableBasics() {

  // Const-variables cannot be changed (final)
  const string text = "Sananas";
  // text = 'b';  => This would result in an error

  // Differences char <=> string ("" vs '')
  char c1 = 'a';
  string s1 = "string";

  // Concat two strings
  string part_one = "Hello ";
  string part_two = "World!";
  string concat = part_one + part_two;

  // Retrieve specific character in a string
  char c_from_s = "Hello World!"[1]; // => e

  // string methods
  string world = "world";
  int world_length = world.length();

  // bools
  bool very_true = false;
  bool very_false = true;

}

void Types() {

  // `double => int` just removes the decimals **without** rounding
  // Sidenote: Multi-variable initialisation. !! (Style note: no camelCase).
  double double_one = 3.14, double_two = 3.98;

  // This results in 3
  int i1 = (int) double_one;

  // This also results in 3
  int i2 = (int) double_two;
}

void Operators() {

  // Arithmetic:      +, -, *, /, %
  // Inc-/decrement:  ++x, x++, --x, x--
  // Assignment:      +=, -=, *=, /=, %=
  // Relational:      ==, !=, <, >, <=, >=
  // Logical:         &&, ||, !
  /* Bitwise:         {
      <<  - x << n  => Shifts bits in x to the left n-times. (per n: doubles value)
      >>  - x >> n  => Shifts bits in x to the right n-times. (per n: half's value)
      ~   - ~x      => Bitwise NOT: flips all bits it x
      &   - x & y   =>
      |   - x | y   =>
      ^   - x ^ y   =>
    } */

  // Will output 5, as the compiler first returns the
  // variable and then decrements it; Thus: **post** decrement
  int five = 5;
  cout << "post-decrement: " << five-- << endl;

  // Will output 4, as the compiler first decrements
  // the variable and then returns it; Thus: **pre** decrement
  five = 5;
  cout << "pre-decrement: " << --five << endl;

  // As a variable the same thing happens: y is assigned 7,
  // but x then changes to 8, due to the post-increment
  int x = 7;
  int y = x--;
}

void ReferencesAndPointers(int &param) {

  //
  // <=== References ===>
  // Alias to an existing variable: &

  // The variable `score` is linked to grade by a reference now.
  double grade = 5.5;
  double &score = grade;

  // If score changes its value, grade automatically
  // Has a new value too; In this case: 5.3
  score = 5.3;

  // References **must** be initialized!
  //double& volume; // => Compiler error

  // References cannot/shouldn't be reassigned
  int x = 1, y = 2;
  int &num = x;
  num = y;

  // References are mostly used in a function.
  // E.g. `int Func(int& param) {}`: once the value of param is
  // changed, its value is also changed outside the function
  param = 5;

  // A reference can also reveal the memory address:
  string msg = "Hello World!";

  // Prints (Hello World!)
  cout << msg << endl;

  // Putting an ampersand in front of a variable
  // prints e.g (0x7ffee9b21af0)
  cout << &msg << endl;


  //
  // <=== Pointers ===>
  // Stores a memory address as it's value: *

  // A pointer **must** point to a variable of the same datatype
  // It has to be initialized by a reference.
  // (This would not be possible: `int* ptr = x`. This'd be: `int* ptr = &x`)
  string day = "Monday";
  string *day_pointer = &day;

  // Simply wanting to reassign a pointers value isn't possible
  // either: `day_pointer = "Friday"` would not work, as a pointer
  // cannot be a string.
  *day_pointer = "Friday";

  // Similar to a reference, simply printing a pointer
  // results in the memory address and not it's assigned value.
  // -
  // When using an asterisk (*) as anything but an initialisation, it's
  // called a dereference, as it retrieves the value of the memory-reference.
  cout << day << endl;          // (Friday)
  cout << day_pointer << endl;  // (0x42519ffca0)
  cout << *day_pointer << endl;  // (Friday)

  // When not knowing what to assign a pointer yet,
  // use the nullptr keyword.
  string *ptr = nullptr;
  ptr = &day;
}

void ConditionalStatements() {

  int x = 4, y = 3;

  if (x > y) {
    // Do sth
  } else if (x == y) {
    // Do sth
  } else {
    // Do sth
  }

  string s = x > y ? "X > Y" : "X < Y";

  switch (x) {
    case 2:
      // Do sth
      break;
    case 3:
      // Do sth
      break;
    case 4:
      // Do sth
      break;
    default:
      // Do sth
      break;
  }

}

void Loops() {

  int count = 1;
  while (count <= 5) {
    cout << count << endl;
    count++;
  }

  int price = 1000;
  do {
    cout << "Too expensive!" << endl;
    price -= 100;

    if (price == 700)
      break; // Whole loop immediately stops
    else
      continue; // Current iteration immediately stops; New iteration begins

  } while (price > 500);

  for (int i = 0; i < 5; i++) {
    cout << i << endl;
  }

  int fibonacci[] = {0, 1, 1, 2, 3, 5, 8};
  for (int number : fibonacci) {
    cout << number << endl;
  }

  // `auto` lets C++ deduce the value of the
  // "to-be-iterated" element.
  for (auto number : fibonacci) {
    cout << number << endl;
  }

}

// Both method calls are correct, due to the default
// cout << *Functions(age, false) << endl;
// cout << *Functions(age) << endl;
int *Functions(int &age, bool returnPtr = true) {

  age = 5;
  int *age_ptr = &age;

  cout << "Value updated!" << endl;

  return returnPtr ? age_ptr : &age;
}

//
// <=== OOP ===>
//
class School {

 private:
  int student_count;

 protected:
  double yearly_costs;

 public:
  const string name;

  School() : name("Default") {
    student_count = 500;
    yearly_costs = 15.12;
  }

  School(int count, double costs, string name) : name(name) {
    this->student_count = count;
    this->yearly_costs = costs;
  }

  void banner() {
    cout << name << " has " << student_count << " students!" << endl;
  }

  void coolerBanner();

  void bell() {
    cout << "RINNGGGG" << endl;
  }

  void setStudentCount(int count) {
    this->student_count = count;
  }

  // Once an object moves out of scope or is explicitly deleted,
  // the **destructor** is called.
  ~School() {
    cout << "Deleted from memory" << endl;
  }
};

/**
 * Whilst using inheritance in C++, the most-base
 * class is always constructed first.
 * E.g. School -> SmallSchool
 */
class SmallSchool : School {

 public:
  SmallSchool(int count, int costs, string name)
      : School(count, costs, name) {}

  void veryCoolBanner() {
    cout << "Very cool banner!" << endl;
  }

  // Overriding methods is called polymorphism
  void bell() {
    cout << "ring" << endl;
  }
};

/**
 * Methods can be defined outside a class, as long as it
 * has been declared inside of it.
 */
void School::coolerBanner() {
  cout << student_count << " has " << name << " students!" << endl;
}

void Objects() {

  School codecademy;
  codecademy.setStudentCount(1000000);

  // Initialization via constructor
  School youtube(50, 9000, "YouTube");

  SmallSchool small_tube(5, 900, "SmallTube");

  codecademy.banner();
  youtube.coolerBanner();
  small_tube.veryCoolBanner();

  codecademy.bell();
  small_tube.bell();
}

/*
 * @info    Commandline arguments can be passed as param in the main method as follows:
 * @param    char **argv == char *argv[]
 * @run    compile it & then: ./a.out arg1 arg2 "arg 3" arg\"2
*/
int main(int argc, char **argv) {

  Objects();

  return 0;
}