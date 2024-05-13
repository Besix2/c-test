#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <math.h>

using namespace std;
using namespace std::chrono;

bool isPasswordCracked = false;

void tryPassword(string password, int length, string current = "", int index = 0, int counter = 0)
{
  if ((pow(length,36) / 5) % counter )
  
  if (isPasswordCracked){
    return;
  }
  if (index == length){
    counter = counter + 1;
    if (current == password)
    {
      cout << "Password cracked: " << current << endl;
      isPasswordCracked = true;
    }
    
    return;
  }
  
  
  
  
char characters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'U', 'V', 'W', 'X', 'Y', 'Z',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
'u', 'v', 'w', 'x', 'y', 'z'};
 // for (char letter = 'a'; letter <= 'z'; letter++)
for ( char i = 0; i <= 36; i++)
  {
    
    tryPassword(password, length, current + characters[i], index + 1, counter);
  }
}

int main()
{
srand(time(0));
  char characters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'U', 'V', 'W', 'X', 'Y', 'Z',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
'u', 'v', 'w', 'x', 'y', 'z'};


random_device seed;
mt19937 gen{seed()}; // seed the generator
uniform_int_distribution<> dist{0, 36};
int pass_length = 12;
string password_list[pass_length];
  for (int e = 0; e < pass_length; e++)
  { string current = "";
    for (int x = 0; x <= e; x++)
    {
     current = current + characters[dist(gen)];
    }
    password_list[e] = current;
  };
  
  for (int i = 0; i < pass_length; i++)
  {
  string passwordToCrack = password_list[i];
  int passwordLength = passwordToCrack.length();
  auto start = high_resolution_clock::now();
  tryPassword(passwordToCrack, passwordLength);
  isPasswordCracked = false;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Password: " + passwordToCrack + "     "; cout << "Execution time: " << duration.count() / 1000 << " seconds" << endl;
  }
  return 0;
}
