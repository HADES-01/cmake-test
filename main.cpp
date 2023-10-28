#include "Human.h"

int main()
{
  Human *h = new Human(1, "Aditya");
  h->show_age();
  h->show_name();
  delete h;
  return 0;
}
