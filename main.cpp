#include<iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

bool ListEqual(list_t l1, list_t l2)
    // EFFECTS: reeturns true of l1 and l2 are equal, false otherwise
{
    // If either are empty, both must be empty for equality
    if (list_isEmpty(l1) || list_isEmpty(l2)) {
	return (list_isEmpty(l1) && list_isEmpty(l2));
    }

    if (list_first(l1) != list_first(l2)) {
	return false;
    } else {
	return ListEqual(list_rest(l1), list_rest(l2));
    }
}

bool notByFour(int i)
{
    return (i%4);
}

int main() {
    list_t original = list_make();
    list_t rotated = list_make();
    list_t testlist=list_make(); // sample list
    list_t testlist2=list_make(); // sample list 

    const int largest = 7;
    const int steps = 4+largest;

    bool answer = true;

    for (int i = largest-1; i>=0; i--) {
      original = list_make(i, original);
      rotated = list_make((i+steps)%largest, rotated);
    }

     for (int j=1; j < 11 ; j++) {
      testlist = list_make(j, testlist);
    }

    for (int j=11; j > 0 ; j--) {
      testlist2 = list_make(j, testlist2);
    }

    //testlist = rotate(original, steps);
    //bool results  = ListEqual(testlist, rotated);

  //list_print(rotated);
  //list_print(original);
 // list_print(testlist);
  list_print(testlist2); // 1-11
  // cout << sum(original)<< endl ; 
  // cout << product(testlist)<< endl ;
  // cout << reverse(testlist2)<< endl ;



}