#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isPasswordCracked = false;

void tryPassword(string password, int length, string current = "", int index = 0)
{
  if (isPasswordCracked)
  {
    return;
  }
  if (index == length)
  {
    if (current == password)
    {
      cout << "Password cracked: " << current << endl;
      isPasswordCracked = true;
    }
    return;
  }

  for (char letter = 'a'; letter <= 'z'; letter++)
  {
    tryPassword(password, length, current + letter, index + 1);
  }
}

int main()
{
  string passwordToCrack = "abcdefgh";
  int passwordLength = passwordToCrack.length();
  auto start = high_resolution_clock::now();
  tryPassword(passwordToCrack, passwordLength);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Execution time: " << duration.count() / 1000 << " seconds" << endl;
  return 0;
}
