// #pragma one

bool prev_input = false;
bool oneClick(bool input)
{
  if (input == 1 && prev_input == 0)
  {
    prev_input = input;
    return 1;
  }
  prev_input = input;
  return 0;
}
