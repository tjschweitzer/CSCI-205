#include "mydate.h"

int main()
{
   Date d1;
   Date d2(1,1,1984);
   Date d3(8,12,1981);

   cout << "How to overload opps";
   
   cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3 << "\n\n";
  
   cout << "d2 += 7 is " << (d2 += 7) << "\n\n";

   cout << "d3++ is " << d3++ << "\n\n";
 
   cout << "d3 now is " << d3 << "\n\n";

   cout << "++d1 is " << ++d1 << "\n\n";


  return 0;
}
