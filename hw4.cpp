#include <iostream>
#include "recursive.h"

#include "hw4.h"
// functions will be in here ALL need to be tail recursive 
// no loops 

using namespace std; 

int accumulate(list_t l, int (*fn)(int, int), int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}
//****************************************************************************//
static int SumHelper (list_t list, int counter){
if (list_isEmpty(list)){ // if empty lidt, return current counter
  return counter; 
}
else 
counter +=list_first(list);
return SumHelper(list_rest(list),counter); 
}


int sum(list_t list){
 
return SumHelper(list, 0);
}


//****************************************************************************//

static int ProductHelper(list_t list, int counter){
if (list_isEmpty(list)){ // if empty lidt, return current counter
cout << "list empty"<< endl ;
  return counter; 
}
else
counter = counter * list_first(list);
return ProductHelper(list_rest(list),counter); 

}

int product(list_t list){

  return ProductHelper(list,1);
}
//list_first-
//list_rest
//**************************************************************************//
static list_t ReverseHelper(list_t list, list_t reverse_list){
if (list_isEmpty(list)){ // if empty lidt, return current counter
cout << "list emptyreverse"<< endl ;
  return reverse_list; 
}
else {
reverse_list=list_make(list_first(list),reverse_list);
return ReverseHelper(list_rest(list),reverse_list);
}
}

list_t reverse(list_t list){ // type list_t func. just changes order of list
  list_t reverse_list = list_make();
  return ReverseHelper(list_t(list),reverse_list);

}


// list_first returns an int 
//list_rest goes down array/list 
//list_isempty checks to see if array is empty


